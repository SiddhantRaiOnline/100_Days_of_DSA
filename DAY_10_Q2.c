/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    
    int freq[1001] = {0};

    // Count elements in nums1
    for(int i = 0; i < nums1Size; i++) {
        freq[nums1[i]]++;
    }

    // Allocate result array (max possible size)
    int* result = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    
    int k = 0;

    // Check elements in nums2
    for(int i = 0; i < nums2Size; i++) {
        if(freq[nums2[i]] > 0) {
            result[k++] = nums2[i];
            freq[nums2[i]]--;
        }
    }

    *returnSize = k;
    return result;
}