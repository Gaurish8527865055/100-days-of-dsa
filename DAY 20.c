#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

// Simple hash map using arrays (for competitive programming style)
long long countZeroSumSubarrays(int arr[], int n) {
    long long count = 0;
    long long prefixSum = 0;

    // Using large range for prefix sums
    int size = 2 * MAX + 1;
    long long *freq = (long long*)calloc(size, sizeof(long long));

    // Shift index to handle negative sums
    int offset = MAX;

    freq[offset] = 1;  // prefix sum 0 initially

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum + offset >= 0 && prefixSum + offset < size) {
            count += freq[prefixSum + offset];
            freq[prefixSum + offset]++;
        }
    }

    free(freq);
    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%lld\n", countZeroSumSubarrays(arr, n));

    return 0;
}