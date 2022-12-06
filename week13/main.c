#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MAX 50
#define M_MAX 50

struct Data {
    int E[M_MAX];
    int A[M_MAX];
    int C[N_MAX][M_MAX];
    int R[N_MAX][M_MAX];
};

// returns amount of deadlocked processes
int deadlocked_processes(struct Data data, int N_processes, int M_resources) {

    int finished_processes[N_MAX] = {};

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
    int N_processes = 0, M_resources = 0;
    char s[(M_MAX + N_MAX) * 18];

    // read E and count M_resources
    fgets(s, (M_MAX + N_MAX) * 18, input);
    char *c = s;
    while (*c != '\0') {
        int k = 0;
        while (*c != ' ' && *c != '\0' && *c != '\n') {
            k = k * 10 + (*c - '0');
            c++;
        }
        c++;
        data.E[M_resources++] = k;
    }

    // read A
    for (int i = 0; i < M_resources; i++) {
        fscanf(input, "%i ", &data.A[i]);
    }

    // empty line
    fgets(s, (M_MAX + N_MAX) * 18, input);
    s[0] = '1';

    // read C and count N_processes
    while (s[0] != '\n') {
        fgets(s, (M_MAX + N_MAX) * 18, input);
        c = s;
        for (int j = 0; j < M_resources; j++) {
            int k = 0;
            while (*c != ' ' && *c != '\0' && *c != '\n') {
                k = k * 10 + (*c - '0');
                c++;
            }
            c++;
            data.C[N_processes][j] = k;
        }
        N_processes++;
    }

    // read R
    for (int i = 0; i < N_processes; i++) {
        for (int j = 0; j < M_resources; j++) {
            fscanf(input, "%i ", &data.R[i][j]);
        }
    }

    int n;
    if ( (n = deadlocked_processes(data, N_processes, M_resources)) ) {
        printf("The deadlock was detected! %i process(es) is(are) deadlocked.\n", n);
    } else {
        printf("No deadlock was detected.");
    }
    fclose(input);
}
