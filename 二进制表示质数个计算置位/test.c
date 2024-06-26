#include<stdbool.h>

//给你两个整数 left 和 right ，在闭区间[left, right] 范围内，统计并返回 计算置位位数为质数 的整数个数。
//
//计算置位位数 就是二进制表示中 1 的个数。
//
//例如， 21 的二进制表示 10101 有 3 个计算置位。
//
//
//示例 1：
//
//输入：left = 6, right = 10
//输出：4
//解释：
//6 -> 110 (2 个计算置位，2 是质数)
//7 -> 111 (3 个计算置位，3 是质数)
//9 -> 1001 (2 个计算置位，2 是质数)
//10-> 1010 (2 个计算置位，2 是质数)
//共计 4 个计算置位为质数的数字。
//示例 2：
//
//输入：left = 10, right = 15
//输出：5
//解释：
//10 -> 1010 (2 个计算置位, 2 是质数)
//11 -> 1011 (3 个计算置位, 3 是质数)
//12 -> 1100 (2 个计算置位, 2 是质数)
//13 -> 1101 (3 个计算置位, 3 是质数)
//14 -> 1110 (3 个计算置位, 3 是质数)
//15 -> 1111 (4 个计算置位, 4 不是质数)
//共计 5 个计算置位为质数的数字。
//
//
//提示：
//
//1 <= left <= right <= 106
//0 <= right - left <= 104



//力扣第762题


//注意到 right≤106 < 220\textit{ right } \le 10 ^ 6 < 2 ^ {20}right≤10
//    6
//    < 2
//    20
//    ，因此二进制中 111 的个数不会超过 191919，而不超过 191919 的质数只有
//
//    2, 3, 5, 7, 11, 13, 17, 192, 3, 5, 7, 11, 13, 17, 19
//    2, 3, 5, 7, 11, 13, 17, 19

   
int countPrimeSetBits(int left, int right) {
    int sum = 0;
    for (int x = left; x <= right; x++) {
        int pos = 0;
        pos = __builtin_popcount(x);
        if (pos == 2 || pos == 3 || pos == 5 || pos == 7 || pos == 11 || pos == 13 || pos == 17 || pos == 19) {
            sum++;
        }
    }

    return sum;
}


//mask = 665772 = 10100010100010101100(二进制)

int countPrimeSetBits(int left, int right) {
    int ans = 0;
    for (int x = left; x <= right; ++x) {
        if ((1 << __builtin_popcount(x)) & 665772) {
            ++ans;
        }
    }
    return ans;
}



//传统的判断质数的方法
bool isPrime(int x) {
    if (x < 2) {
        return false;
    }
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int countPrimeSetBits(int left, int right) {
    int ans = 0;
    for (int x = left; x <= right; ++x) {
        if (isPrime(__builtin_popcount(x))) {
            ++ans;
        }
    }
    return ans;
}

