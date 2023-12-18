//给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n / 2 ⌋ 的元素。
//
//你可以假设数组是非空的，并且给定的数组总是存在多数元素。

//
//力扣第169题
#include<stdio.h>
int cmp(const void* _a, const void* _b) {

    return *(int*)_a - *(int*)_b;
}
int main() {

    int nums[7] = { 2,2,1,1,1,2,2 };
    int numsSize = 7;
    int k = numsSize / 2;
 //从小到大依次排序
    qsort(nums, numsSize, sizeof(int), cmp);
   
  // int* arr = (int*)malloc(sizeof(int) * numsSize);
   int i = 0;
   int fast = 0;
   int slow = 0;
   for (i = 0; i <=numsSize; i++) {
    if (nums[fast] != nums[slow]||fast==numsSize) {
        if (k < fast - slow) {
            int ret=nums[slow]; 
            printf("%d", ret);
        }
        slow = fast;
    }
    fast++;
 }
  
   return 0;
}


//int cmp(const void* _a, const void* _b) {
//
//    return *(int*)_a - *(int*)_b;
//}
//int majorityElement(int* nums, int numsSize) {
//
//    //从小到大依次排序
//    qsort(nums, numsSize, sizeof(int), cmp);
//    return nums[(numsSize - 1) / 2];
//}