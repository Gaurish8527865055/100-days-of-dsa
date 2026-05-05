#include <stdio.h>

int isPossible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime)
            return 0;

        if (currSum + boards[i] <= maxTime) {
            currSum += boards[i];
        } else {
            painters++;
            currSum = boards[i];
        }
    }
    return painters <= k;
}

int minTime(int boards[], int n, int k) {
    int sum = 0, maxVal = 0;

    for (int i = 0; i < n; i++) {
        sum += boards[i];
        if (boards[i] > maxVal)
            maxVal = boards[i];
    }

    int low = maxVal, high = sum, ans = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &boards[i]);

    printf("%d\n", minTime(boards, n, k));
    return 0;
}