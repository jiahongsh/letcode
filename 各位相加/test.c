/*给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。返回这个结果。


示例 1:

输入: num = 38
输出 : 2
解释 : 各位相加的过程为：
38 -- > 3 + 8 -- > 11
11 -- > 1 + 1 -- > 2
由于 2 是一位数，所以返回 2。
示例 2:

输入: num = 0
输出 : 0


提示：

0 <= num <= 231 - 1


进阶：你可以不使用循环或者递归，在 O(1) 时间复杂度内解决这个问题吗？*/



//力扣第258题
#include<stdio.h>

int addDigits(int num) {
    int count = 0;
    int n = num;//使用n记录num计算后的数值

    //判断n是不是一位数
    while (n / 10) {
        //每次对num的每位数加起来
        while (num > 0) {
            int tmp = num % 10;
            count += tmp;
            num /= 10;
        }
        //num记录下来便于下一次的迭代
        num = count;

        //n记录计算后的数，进行判断是否满足数
        n = num;
        //每次循环后让count置0
        count = 0;
    }
    return n;
}


int main() {
    int num = 38;
   int ret= addDigits(num);
   printf("%d", ret);
    return 0;
}

//根据上述分析可知，当 num > 0\textit{ num } > 0num > 0 时，其数根的结果在范围[1, 9][1, 9][1, 9] 内，
//因此可以想到计算 num−1\textit{ num } - 1num−1 除以 999 的余数然后加 111。
//由于当 num > 0\textit{ num } > 0num > 0 时，num−1≥0\textit{ num } - 1 \ge 0num−1≥0，
//非负数除以 999 的余数一定也是非负数，因此计算 num−1\textit{ num } - 1num−1 除以 999 的余数然后加 111 的结果是正确的。
//
//当 num = 0\textit{ num } = 0num = 0 时，num−1 = −1 < 0\textit{ num } - 1 = -1 < 0num−1 = −1 < 0，
//负数对 999 取余或取模的结果的正负在不同语言中有所不同。
//
//对于取余的语言，结果的正负和左操作数相同，则 num−1\textit{ num } - 1num−1 对 999 取余的结果为 −1 - 1−1，
//加 111 后得到结果 000，可以得到正确的结果；
//
//对于取模的语言，结果的正负和右操作数相同，则 num−1\textit{ num } - 1num−1 对 999 取模的结果为 888，
//加 111 后得到结果 999，无法得到正确的结果，此时需要对 num = 0\textit{ num } = 0num = 0 的情况专门做处理。

int addDigits(int num) {
    return (num - 1) % 9 + 1;
}