#include <stdio.h>

int leastInterval(char* tasks, int tasksSize, int n) {
    int freq[26] = {0};

    // Count frequency
    for (int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
    }

    // Find max frequency
    int maxFreq = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq)
            maxFreq = freq[i];
    }

    // Count how many have max frequency
    int countMax = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] == maxFreq)
            countMax++;
    }

    int part = (maxFreq - 1) * (n + 1) + countMax;

    return (tasksSize > part) ? tasksSize : part;
}