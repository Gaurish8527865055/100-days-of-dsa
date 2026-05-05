#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    // Read array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    // Handle cases where k > n
    k = k % n;

    int temp[n];

    // Rotate array
    for(int i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }

    // Print rotated array
    for(int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}
