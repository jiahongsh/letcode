//给定由一些正数（代表长度）组成的数组 nums ，返回 由其中三个长度组成的、面积不为零的三角形的最大周长 。如果不能形成任何面积不为零的三角形，返回 0。
//
//
//
//示例 1：
//
//输入：nums = [2, 1, 2]
//输出：5
//解释：你可以用三个边长组成一个三角形 : 1 2 2。
//示例 2：
//
//输入：nums = [1, 2, 1, 10]
//输出：0
//解释：
//你不能用边长 1, 1, 2 来组成三角形。
//不能用边长 1, 1, 10 来构成三角形。
//不能用边长 1、2 和 10 来构成三角形。
//因为我们不能用任何三条边长来构成一个非零面积的三角形，所以我们返回 0。
//
//
//提示：
//
//3 <= nums.length <= 104
//1 <= nums[i] <= 106
//
//
//
// 
//力扣第976题
int cmp(int a, int b) {

    return a - b;
}




int largestPerimeter(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int i = 0;
    for (i = numsSize - 1; i >= 2; --i) {
        if ((nums[i - 2] + nums[i - 1]) > nums[i]) {
            return nums[i - 2] + nums[i - 1] + nums[i];
        }
    }

    return 0;
}