#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <string.h>

typedef struct Thread {
    long unsigned int id;
    int i;
    char* message;
} THREAD;

void * threadFunction(THREAD *thread) {
    thread->id = gettid();
    printf("id: %i, message: %s\n\n", thread->id, thread->message);
}

int main(){
    const int n = 10;
    THREAD thread_arr[n];
    for (int i = 0; i < n; i++) {
        pthread_t t;

        char message[256];
        sprintf(message, "Hello from thread %i", i);
        THREAD temp = {t, i, message};
        thread_arr[i] = temp;

        pthread_create(&t, NULL, threadFunction, &thread_arr[i]);
        printf("Thread %i is created\n", i);
        pthread_join(t, NULL);
    }

	return EXIT_SUCCESS;
}
