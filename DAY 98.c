#include <stdlib.h>

// Comparator for sorting
int cmp(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {

    // Step 1: sort
    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    int** result = (int**)malloc(sizeof(int*) * intervalsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * intervalsSize);

    int idx = 0;

    // Step 2: process intervals
    for (int i = 0; i < intervalsSize; i++) {

        if (idx == 0 || result[idx - 1][1] < intervals[i][0]) {
            // No overlap → new interval
            result[idx] = (int*)malloc(2 * sizeof(int));
            result[idx][0] = intervals[i][0];
            result[idx][1] = intervals[i][1];
            (*returnColumnSizes)[idx] = 2;
            idx++;
        } else {
            // Overlap → merge
            if (intervals[i][1] > result[idx - 1][1]) {
                result[idx - 1][1] = intervals[i][1];
            }
        }
    }

    *returnSize = idx;
    return result;
}