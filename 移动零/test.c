﻿//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//
//请注意 ，必须在不复制数组的情况下原地对数组进行操作。
//
//
//
//示例 1:
//
//输入: nums = [0, 1, 0, 3, 12]
//输出 : [1, 3, 12, 0, 0]
//示例 2 :
//
//    输入 : nums = [0]
//    输出 : [0]
//
//
//    提示 :
//
//    1 <= nums.length <= 104
//    - 231 <= nums[i] <= 231 - 1
//
//
//    进阶：你能尽量减少完成的操作次数吗？




//力扣第283题
//一次遍历，交换0和有效数字
void moveZeroes(int* nums, int numsSize) {
    if (numsSize == 1) {
        return;
    }
    int fast = 0;
    int slow = 0;
    for (fast = 0; fast < numsSize; fast++) {
        //每次遇到非零数字，就会与前面的零或者自己交换，最后所有的0都在最后
        if (nums[fast] != 0) {
            int tmp = nums[slow];
            nums[slow] = nums[fast];
            nums[fast] = tmp;
            slow++;
        }

    }
}