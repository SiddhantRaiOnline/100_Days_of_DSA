void moveZeroes(int* nums, int numsSize) {
    int k = 0;  // position for non-zero elements

    // Step 1: move non-zero elements forward
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != 0) {
            nums[k++] = nums[i];
        }
    }

    // Step 2: fill remaining with zeros
    while(k < numsSize) {
        nums[k++] = 0;
    }
}