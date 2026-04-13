#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int firstIndex[26];

    // initialize with -1
    for (int i = 0; i < 26; i++)
        firstIndex[i] = -1;

    int minSecondIndex = 100000;
    char result = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';

        if (firstIndex[idx] == -1) {
            // first time seen
            firstIndex[idx] = i;
        } else {
            // second (or more) occurrence
            if (i < minSecondIndex) {
                minSecondIndex = i;
                result = s[i];
            }
        }
    }

    if (result == -1)
        printf("-1\n");
    else
        printf("%c\n", result);

    return 0;
}