#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    int sum = 0;

    // Read matrix elements
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate primary diagonal sum
    int limit = (m < n) ? m : n;

    for(int i = 0; i < limit; i++) {
        sum += matrix[i][i];
    }

    printf("%d\n", sum);

    return 0;
}
