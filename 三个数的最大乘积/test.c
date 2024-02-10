//给你一个整型数组 nums ，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
//
//
//
//示例 1：
//
//输入：nums = [1, 2, 3]
//输出：6
//示例 2：
//
//输入：nums = [1, 2, 3, 4]
//输出：24
//示例 3：
//
//输入：nums = [-1, -2, -3]
//输出： - 6
//
//
//提示：
//
//3 <= nums.length <= 104
//- 1000 <= nums[i] <= 1000



//力扣第628题
int cmp(int* a, int* b) {
    return *a - *b;
}
int maximumProduct(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int num1 = nums[0] * nums[1] * nums[numsSize - 1];
    int num2 = nums[numsSize - 3] * nums[numsSize - 2] * nums[numsSize - 1];


    return num1 > num2 ? num1 : num2;
}