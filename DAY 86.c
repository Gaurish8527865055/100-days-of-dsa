#include <stdio.h>

int integerSqrt(int n) {
    if (n == 0 || n == 1)
        return n;

    long low = 1, high = n;
    long ans = 0;

    while (low <= high) {
        long mid = low + (high - low) / 2;

        if (mid * mid == n)
            return mid;
        else if (mid * mid < n) {
            ans = mid;        // possible answer
            low = mid + 1;    // search right
        } else {
            high = mid - 1;   // search left
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", integerSqrt(n));
    return 0;
}