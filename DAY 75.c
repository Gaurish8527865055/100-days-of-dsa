#include <stdio.h>

#define MAX 1000

int maxLen(int arr[], int n) {
    int prefixSum = 0, maxLength = 0;

    // Hash map using arrays
    int hash[2 * MAX + 1];

    // Initialize hash with -1
    for (int i = 0; i < 2 * MAX + 1; i++) {
        hash[i] = -1;
    }

    int offset = MAX; // to handle negative sums

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: sum = 0
        if (prefixSum == 0) {
            maxLength = i + 1;
        }

        // Case 2: seen before
        if (hash[prefixSum + offset] != -1) {
            int len = i - hash[prefixSum + offset];
            if (len > maxLength) {
                maxLength = len;
            }
        } else {
            // store first occurrence
            hash[prefixSum + offset] = i;
        }
    }

    return maxLength;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLen(arr, n));
    return 0;
}