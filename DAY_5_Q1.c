#include <stdio.h>

int main() {
    int p, q;

    // Input size of first array
    scanf("%d", &p);
    int a[100], b[100], result[200];

    // Input first sorted array
    for(int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    // Input size of second array
    scanf("%d", &q);

    // Input second sorted array
    for(int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    int i = 0, j = 0, k = 0;

    // Merge both arrays
    while(i < p && j < q) {
        if(a[i] < b[j]) {
            result[k++] = a[i++];
        } else {
            result[k++] = b[j++];
        }
    }

    // Remaining elements of a[]
    while(i < p) {
        result[k++] = a[i++];
    }

    // Remaining elements of b[]
    while(j < q) {
        result[k++] = b[j++];
    }

    // Print merged array
    for(int i = 0; i < k; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}