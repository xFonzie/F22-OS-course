#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <string.h>

#define min(a, b) ((a < b) ? a : b)
int is_prime(int n)
{
  if (n <= 1)
    return 0;
  for (int d = 2; d * d <= n; d++)
    if (n % d == 0)
      return 0;
  return 1;
}

int primes_count_in_interval(int start, int finish)
{
  int ret = 0;
  for (int i = start; i < finish; i++)
    if (is_prime(i) != 0)
      ret++;
  return ret;
}

// The structure that will be passed to the threads, corresponding to an interval to count the number of primes in.
typedef struct prime_counter_request
{
  int start, finish;
} prime_counter_request;

void *prime_counter(prime_counter_request *arg)
{
  /*
    TODO
    Complete this function. It takes a primes_counter_request as a parameter and returns the number of primes in the specified interval.
    Be careful how you return the return value.
  */
  //printf("%i, %i\n", arg->start, arg->finish);

  pthread_exit((void *) primes_count_in_interval(arg->start, arg->finish));
}

int main(int argc, char *argv[])
{
  int n = atoi(argv[1]), n_threads = atoi(argv[2]);
  int segment_size = n / n_threads;

  pthread_t *threads = malloc(n_threads * sizeof(pthread_t));

  prime_counter_request *requests = malloc(n_threads * sizeof(prime_counter_request));

  void **results = malloc(n_threads * sizeof(void *));

  for (int i = 0; i < n_threads; i++)
  {
    requests[i].start = (n / n_threads) * i;
    requests[i].finish = min(n, (n / n_threads) * (i + 1));
    pthread_create(&threads[i], NULL, prime_counter, &requests[i]);
  }

  for (int i = 0; i < n_threads; i++)
  {
    pthread_join(threads[i], &results[i]);
  }

  int total_result = 0;
  for (int i = 0; i < n_threads; i++)
    total_result += (int)results[i];

  free(threads);
  free(requests);
  free(results);

  printf("%d\n", total_result);

  exit(EXIT_SUCCESS);
}
