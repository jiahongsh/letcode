//给你一个整数数组 nums ，请计算数组的 中心下标 。
//
//数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。
//
//如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。
//
//如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回 - 1 。
//
//
//
//示例 1：
//
//输入：nums = [1, 7, 3, 6, 5, 6]
//输出：3
//解释：
//中心下标是 3 。
//左侧数之和 sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11 ，
//右侧数之和 sum = nums[4] + nums[5] = 5 + 6 = 11 ，二者相等。
//示例 2：
//
//输入：nums = [1, 2, 3]
//输出： - 1
//解释：
//数组中不存在满足此条件的中心下标。
//示例 3：
//
//输入：nums = [2, 1, -1]
//输出：0
//解释：
//中心下标是 0 。
//左侧数之和 sum = 0 ，（下标 0 左侧不存在元素），
//右侧数之和 sum = nums[1] + nums[2] = 1 + -1 = 0 。
//
//
//提示：
//
//1 <= nums.length <= 104




//力扣第742题
//负数有bug
int pivotIndex(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;
    int numl = nums[left];
    int numr = nums[numsSize - 1];
    while (left < right) {
        if (numl <= numr) {
            left++;
            numl += nums[left];
        }
        else {
            right--;
            numr += nums[right];
        }
    }
    if (numl == numr) {
        return left;
    }
    return -1;
}

//暴力加和
int pivotIndex(int* nums, int numsSize) {
    int sum = 0;
    int i = 0;
    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    for (i = 0; i < numsSize; i++) {
        int j = 0;
        int numl = 0;
        int numr = 0;
        for (j = 0; j < i; j++) {
            numl += nums[j];
        }

        for (j = numsSize - 1; j > i; j--) {
            numr += nums[j];
        }
        if (numl == numr) {
            return i;
        }

    }
    return -1;
}

//利用题目求出等式
int pivotIndex(int* nums, int numsSize) {
    int sum = 0;
    int i = 0;
    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    int numl = 0;
    for (i = 0; i < numsSize; i++) {

        if (numl * 2 + nums[i] == sum) {
            return i;
        }
        numl += nums[i];
    }
    return -1;
}