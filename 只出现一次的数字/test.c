//给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
//
//你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。
//
//
//
//示例 1 ：
//
//输入：nums = [2, 2, 1]
//输出：1
//示例 2 ：
//
//输入：nums = [4, 1, 2, 1, 2]
//输出：4
//示例 3 ：
//
//输入：nums = [1]
//输出：1
//
//
//提示：
//
//1 <= nums.length <= 3 * 104
//- 3 * 104 <= nums[i] <= 3 * 104
//除了某个元素只出现一次以外，其余每个元素均出现两次。



//力扣第136题

//排序后比较思想
int cmp(const void* a, const void* b) {
    int A = *(int*)a;
    int B = *(int*)b;
    return B - A;
}
int singleNumber(int* nums, int numsSize) {
    //只有一个数的情况
    if (numsSize == 1) {
        return nums[0];
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int slow = 0;
    int fast = 1;
    while (1) {
        //最大数是唯一数字的情况
        if ((fast + 2) == numsSize) {
            return nums[fast + 1];
        }
        //若前后数相同，跳过这一组数
        if (nums[slow] == nums[fast]) {
            slow += 2;
            fast += 2;
        }
        //若前后数不同，slow位置指向的数为唯一数
        if (nums[slow] != nums[fast])
            return nums[slow];
    }
    return 0;
}


//异或思想

int singleNumber(int* nums, int numsSize) {
    int n = nums[0];
    int i = 0;
    for (i = 1; i < numsSize; i++) {
        n = n ^ nums[i];
    }
    return n;
}
