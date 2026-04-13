#include <stdio.h>

int main() {
    int m, n;

    // Input dimensions
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    int sum = 0;

    // Input matrix elements
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate diagonal sum
    for(int i = 0; i < m && i < n; i++) {
        sum += matrix[i][i];
    }

    // Output result
    printf("%d\n", sum);

    return 0;
}