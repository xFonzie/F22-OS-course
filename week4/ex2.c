
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Calculate the dot product of the vectors u and v from the component [start] till the component [end] exclusively.
int dotprod(int u[], int v[], int start, int end){

	int result = 0;

	for (int i=start; i<end; i++){
		result += u[i] * v[i];
	}

	return result;
}

const int LEN = 120;

int main(void){

    srand(time(0));

    int u[LEN], v[LEN];
    for (int i = 0; i < LEN; i++) {
        u[i] = rand() % 100;
        v[i] = rand() % 100;
    }

    int n;
    scanf("%d", &n);
    int k = LEN / n + 1, last = LEN % n;
    int done = 0;
    pid_t main_parent = getpid();

    FILE * temp = fopen("temp.txt", "w"); // clear temp.txt
    fclose(temp);

    for (int i = 0 ; i < n; i++) {
        if (i == last) {
            k--;
        }

        pid_t pid = 1;
        if (getpid() == main_parent) {
            pid = fork();
        }

        if (pid == 0) {
            FILE * fapp = fopen("temp.txt", "a");
            fprintf(fapp, "%d\n", dotprod(u, v, done, done + k));
            fclose(fapp);
        }
        done += k;
    }

    while (wait(0) > 0); // wait for all children

    if (getpid() == main_parent) {
        FILE * fin = fopen("temp.txt", "r");
        int sum = 0, cur = 0;
        while (fscanf(fin, "%d", &cur) != EOF) {
            sum += cur;
        }
        printf("%d", sum);
        fclose(fin);
    }

	return EXIT_SUCCESS;

}
