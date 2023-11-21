//����������С�ֱ�Ϊ m �� n �����򣨴�С�������� nums1 �� nums2�������ҳ���������������������� ��λ�� ��
//
//�㷨��ʱ�临�Ӷ�Ӧ��Ϊ O(log(m + n)) ��
//
//
//
//ʾ�� 1��
//
//���룺nums1 = [1, 3], nums2 = [2]
//�����2.00000
//���ͣ��ϲ����� = [1, 2, 3] ����λ�� 2
//ʾ�� 2��
//
//���룺nums1 = [1, 2], nums2 = [3, 4]
//�����2.50000
//���ͣ��ϲ����� = [1, 2, 3, 4] ����λ��(2 + 3) / 2 = 2.5
//
//
//
//
//��ʾ��
//
//nums1.length == m
//nums2.length == n
//0 <= m <= 1000
//0 <= n <= 1000
//1 <= m + n <= 2000
//- 106 <= nums1[i], nums2[i] <= 106


#include<stdio.h>
//���۵�4��
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
    //����������ϲ���Ϊһ������
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
    //�ҵ���λ��
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