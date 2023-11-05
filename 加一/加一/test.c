//给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
//
//最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//
//你可以假设除了整数 0 之外，这个整数不会以零开头。
//
//
//
//示例 1：
//
//输入：digits = [1, 2, 3]
//输出：[1, 2, 4]
//解释：输入数组表示数字 123。
//示例 2：
//
//输入：digits = [4, 3, 2, 1]
//输出：[4, 3, 2, 2]
//解释：输入数组表示数字 4321。
//示例 3：
//
//输入：digits = [0]
//输出：[1]



//Note: The returned array must be malloced, assume caller calls free().
//力扣66
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int x = digitsSize - 1;
    for (int i = digitsSize; i > 0; i--)
    {
        if (digits[x] == 9)
        {
            digits[x] = 0;
            x--;
        }
        else
        {
            digits[x]++;
            *returnSize = digitsSize;
            return digits;
        }
    }
    *returnSize = digitsSize + 1;
    int* tmp = (int*)malloc(sizeof(int) * (digitsSize + 1));
    if (!tmp) return 0;
    *tmp = 1;
    for (int i = 1; i < digitsSize + 1; i++) tmp[i] = digits[i - 1];
    return tmp;


}

