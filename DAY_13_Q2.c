#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    // Input
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int result[m * n];
    int k = 0;

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while(top <= bottom && left <= right) {

        // Top row
        for(int j = left; j <= right; j++)
            result[k++] = matrix[top][j];
        top++;

        // Right column
        for(int i = top; i <= bottom; i++)
            result[k++] = matrix[i][right];
        right--;

        // Bottom row
        if(top <= bottom) {
            for(int j = right; j >= left; j--)
                result[k++] = matrix[bottom][j];
            bottom--;
        }

        // Left column
        if(left <= right) {
            for(int i = bottom; i >= top; i--)
                result[k++] = matrix[i][left];
            left++;
        }
    }

    // Output in required format
    printf("[");
    for(int i = 0; i < m*n; i++) {
        printf("%d", result[i]);
        if(i < m*n - 1) printf(",");
    }
    printf("]");

    return 0;
}