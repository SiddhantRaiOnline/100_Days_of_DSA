#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    // Input string
    scanf("%s", str);

    int i = 0;
    int j = strlen(str) - 1;

    // Reverse using two pointers
    while(i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++;
        j--;
    }

    // Output result
    printf("%s", str);

    return 0;
}