int missingNum(int *arr, int size) {
    long long sum = 0;

    int n = size + 1;

    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }

    long long total = (long long)n * (n + 1) / 2;

    return (int)(total - sum);
}