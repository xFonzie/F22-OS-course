#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE *file = fopen("input.txt", "r");
    int page, hits = 0, total = 0;
    int n = atoi(argv[1]), counters[1000] = {}, pages[1000] = {};
    while ((fscanf(file, "%i ", &page) != EOF)) {
        int next = 0;
        total++;
        for (int i = 0; i < n; i++)
            counters[i] = counters[i] >> 1;

        for (int i = 0; i < n; i++) {
            if (pages[i] == page) {
                next = i;
                hits++;
                break;
            }
            if (pages[i] == 0 || (counters[i] < counters[next])) {
                next = i;
            }
        }
        pages[next] = page;
        counters[next] = counters[next] | (1 << 30);
    }
    printf("Hits: %i, Misses: %i, Ratio: %f", hits, total - hits, hits / (total - hits + 0.));
    return 0;
}
