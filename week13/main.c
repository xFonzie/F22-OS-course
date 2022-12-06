#include <stdio.h>
#include <stdlib.h>

#define N_processes 5
#define M_resources 3

struct Data {
    int E[M_resources];
    int A[M_resources];
    int C[N_processes][M_resources];
    int R[N_processes][M_resources];
};

// returns amount of deadlocked processes
int deadlocked_processes(struct Data data) {

    int finished_processes[N_processes] = {};

    // try every process to finish
    while (1) {
        // was at least 1 process finished in this iteration
        int was_finished = 0;
        for (int n = 0; n < N_processes; n++) {
            if (!finished_processes[n]) {
                // check if current process is runnable
                int is_runnable = 1;
                for (int r = 0; r < M_resources; r++) {
                    if ( (data.R[n][r] - data.C[n][r]) > data.A[r]) {
                        is_runnable = 0;
                        break;
                    }
                }

                // if runnable, finish current process
                if (is_runnable) {
                    was_finished = 1;
                    printf("%i\n", n);
                    finished_processes[n] = 1;

                    // change allocated resources to availible
                    for (int r = 0; r < M_resources; r++) {
                        data.A[r] += data.C[n][r];
                        data.C[n][r] = 0;
                    }
                }
            }
        }

        if (!was_finished) {
            // count all not finished processes
            int counter = 0;

            for (int n = 0; n < N_processes; n++) {
                if (!finished_processes[n])
                    counter++;
            }

            return counter;
        }
    }
}

int main()
{
    FILE* input = fopen("input.txt", "r");

    struct Data data;

    // read E
    for (int i = 0; i < M_resources; i++) {
        fscanf(input, "%d ", &data.E[i]);
    }

    // read A
    for (int i = 0; i < M_resources; i++) {
        fscanf(input, "%i ", &data.A[i]);
    }

    // read C
    for (int i = 0; i < N_processes; i++) {
        for (int j = 0; j < M_resources; j++) {
            fscanf(input, "%i ", &data.C[i][j]);
        }
    }

    // read R
    for (int i = 0; i < N_processes; i++) {
        for (int j = 0; j < M_resources; j++) {
            fscanf(input, "%i ", &data.R[i][j]);
        }
    }

    int n;
    if ( n = deadlocked_processes(data) ) {
        printf("The deadlock was detected! %i process(es) is(are) deadlocked.\n", n);
    } else {
        printf("No deadlock was detected.");
    }
    fclose(input);
}
