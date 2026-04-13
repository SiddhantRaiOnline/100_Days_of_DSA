#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefix_sum = 0;
    int count = 0;

    // Using simple array as hashmap (for small constraints)
    int freq[10001] = {0};  // adjust size if needed
    int offset = 5000;      // to handle negative sums

    freq[offset] = 1; // prefix sum = 0 initially

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        // If this prefix sum seen before
        if (freq[prefix_sum + offset] > 0) {
            count += freq[prefix_sum + offset];
        }

        freq[prefix_sum + offset]++;
    }

    printf("%d\n", count);
    return 0;
}