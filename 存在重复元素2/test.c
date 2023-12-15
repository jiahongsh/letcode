//给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。
//
//
//
//示例 1：
//
//输入：nums = [1, 2, 3, 1], k = 3
//输出：true
//示例 2：
//
//输入：nums = [1, 0, 1, 1], k = 1
//输出：true
//示例 3：
//
//输入：nums = [1, 2, 3, 1, 2, 3], k = 2
//输出：false




//力扣第219题
typedef struct arr {
    int num;//数据
    int val;//下标
}arr;

int cmp(const void* a, const void* b) {
    int A = (*(arr*)a).num;
    int B = (*(arr*)b).num;
    return A - B;
}
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    arr a[numsSize];
    int i = 0;
    //将数据放到结构体中，并记录下标
    for (i = 0; i < numsSize; i++) {
        a[i].num = nums[i];
        a[i].val = i;
    }

    //从大到小进行排序
    qsort(a, numsSize, sizeof(arr), cmp);
    //比较
    for (i = 0; i < numsSize - 1; i++) {
        if ((a[i].num == a[i + 1].num) && (abs(a[i].val - a[i + 1].val) <= k)) { //abs绝对值函数

            return true;
        }
    }

    return false;
}