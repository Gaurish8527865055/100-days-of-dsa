#include <stdlib.h>

void merge(int* nums, int* idx, int* temp, int* count, int left, int right) {
    if (right - left <= 1) return;

    int mid = (left + right) / 2;
    merge(nums, idx, temp, count, left, mid);
    merge(nums, idx, temp, count, mid, right);

    int i = left, j = mid, k = left;
    int rightCount = 0;

    while (i < mid && j < right) {
        if (nums[idx[j]] < nums[idx[i]]) {
            temp[k++] = idx[j++];
            rightCount++;
        } else {
            count[idx[i]] += rightCount;
            temp[k++] = idx[i++];
        }
    }

    while (i < mid) {
        count[idx[i]] += rightCount;
        temp[k++] = idx[i++];
    }

    while (j < right) {
        temp[k++] = idx[j++];
    }

    for (i = left; i < right; i++) {
        idx[i] = temp[i];
    }
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    int* count = (int*)calloc(numsSize, sizeof(int));
    int* idx = (int*)malloc(numsSize * sizeof(int));
    int* temp = (int*)malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) idx[i] = i;

    merge(nums, idx, temp, count, 0, numsSize);

    free(idx);
    free(temp);

    *returnSize = numsSize;
    return count;
}