#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];

    // Input array
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int i = 0, j = n - 1;

    // Two-pointer swap
    while(i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        i++;
        j--;
    }

    // Output reversed array
    for(int k = 0; k < n; k++) {
        printf("%d ", arr[k]);
    }

    return 0;
}