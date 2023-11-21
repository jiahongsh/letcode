//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
//
//算法的时间复杂度应该为 O(log(m + n)) 。
//
//
//
//示例 1：
//
//输入：nums1 = [1, 3], nums2 = [2]
//输出：2.00000
//解释：合并数组 = [1, 2, 3] ，中位数 2
//示例 2：
//
//输入：nums1 = [1, 2], nums2 = [3, 4]
//输出：2.50000
//解释：合并数组 = [1, 2, 3, 4] ，中位数(2 + 3) / 2 = 2.5
//
//
//
//
//提示：
//
//nums1.length == m
//nums2.length == n
//0 <= m <= 1000
//0 <= n <= 1000
//1 <= m + n <= 2000
//- 106 <= nums1[i], nums2[i] <= 106


#include<stdio.h>
//力扣第4题
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size == 0 && nums2Size == 1) {
        return nums2[0];
    }
    if (nums1Size == 1 && nums2Size == 0) {
        return nums1[0];
    }
    int size = nums1Size + nums2Size;
    int arr[1000];
    int count1 = 0, count2 = 0, count = 0;
    //将两个数组合并成为一个数组
    while (count1 < nums1Size && count2 < nums2Size) {
        if (nums1[count1] < nums2[count2]) {
            arr[count] = nums1[count1];
            count1++;
        }
        else {
            arr[count] = nums2[count2];
            count2++;
        }
        count++;
    }
    while (count1 < nums1Size) {
        arr[count++] = nums1[count1++];
    }
    while (count2 < nums2Size) {
        arr[count++] = nums2[count2++];
    }
    //找到中位数
    double sum;
    if (size % 2 == 0) {
        sum = (arr[size / 2] + arr[(size / 2) - 1]) / 2.0;
    }
    else {
        sum = arr[size / 2];
    }
    return sum;
}



int main() {
    int nums1[2] = { 1,2 };
    int nums2[2] = { 3,4 };
    int nums1Size = 2;
    int nums2Size = 2;
    double sum=findMedianSortedArrays( nums1, nums1Size,  nums2,  nums2Size);
    printf("%f", sum);
    return 0;
}