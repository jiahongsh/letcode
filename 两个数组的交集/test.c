//给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
//
//
//
//示例 1：
//
//输入：nums1 = [1, 2, 2, 1], nums2 = [2, 2]
//输出：[2]
//示例 2：
//
//输入：nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
//输出：[9, 4]
//解释：[4, 9] 也是可通过的
//
//
//提示：
//
//1 <= nums1.length, nums2.length <= 1000
//0 <= nums1[i], nums2[i] <= 1000


#include<stdio.h>
//力扣第349题
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    //空数组的情况
    if (nums1Size == 0 || nums2Size == 0) {
        *returnSize = 0;
        return 0;
    }
    *returnSize = 0;
    int n1 = 0;
    int n2 = 0;
    int ret = (nums1Size < nums2Size) ? nums1Size : nums2Size;
    int* arr = (int*)malloc(sizeof(int) * ret);

    for (n1 = 0; n1 < nums1Size; n1++) {
        for (n2 = 0; n2 < nums2Size; n2++) {
            int flag = 0;
            if (nums1[n1] == nums2[n2]) {
                for (int i = 0; i < ret; i++) {
                    if (arr[i] == nums1[n1]) {
                        flag = 1;
                    }
                }
                if (flag != 1) {
                    arr[*returnSize] = nums1[n1];
                    *returnSize++;
                }
            }
        }
    }
    return arr;
}

int main() {
    int nums1[4] = { 1,2,2,1 };
    int nums2[2] = { 2,2 };
    int* ret = intersection(nums1, 4, nums2, 2, 0);
    return 0;
}