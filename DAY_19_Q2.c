#include <stdio.h>

int maxSubarraySumCircular(int* nums, int n) {
    int total = 0;

    int max_sum = nums[0], cur_max = 0;
    int min_sum = nums[0], cur_min = 0;

    for (int i = 0; i < n; i++) {
        cur_max = (cur_max > 0 ? cur_max : 0) + nums[i];
        max_sum = (cur_max > max_sum) ? cur_max : max_sum;

        cur_min = (cur_min < 0 ? cur_min : 0) + nums[i];
        min_sum = (cur_min < min_sum) ? cur_min : min_sum;

        total += nums[i];
    }

    // If all numbers are negative
    if (max_sum < 0)
        return max_sum;

    return (max_sum > total - min_sum) ? max_sum : total - min_sum;
}