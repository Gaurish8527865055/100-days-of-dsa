#include <stdio.h>

// Check if allocation is possible with given maxPages
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int currentPages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return 0;

        if (currentPages + arr[i] > maxPages) {
            students++;
            currentPages = arr[i];

            if (students > m)
                return 0;
        } else {
            currentPages += arr[i];
        }
    }
    return 1;
}

// Main function
int allocateBooks(int arr[], int n, int m) {
    if (m > n)
        return -1; // not possible

    int low = 0, high = 0;

    // Find max and sum
    for (int i = 0; i < n; i++) {
        if (arr[i] > low)
            low = arr[i];   // max element
        high += arr[i];     // total sum
    }

    int result = high;

    // Binary Search
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1;  // try smaller
        } else {
            low = mid + 1;   // increase limit
        }
    }

    return result;
}

// Driver code
int main() {
    int n = 4, m = 2;
    int arr[] = {12, 34, 67, 90};

    printf("%d\n", allocateBooks(arr, n, m));
    return 0;
}