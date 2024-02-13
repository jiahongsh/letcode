//自除数 是指可以被它包含的每一位数整除的数。
//
//例如，128 是一个 自除数 ，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
//自除数 不允许包含 0 。
//
//给定两个整数 left 和 right ，返回一个列表，列表的元素是范围[left, right] 内所有的 自除数 。
//
//
//
//示例 1：
//
//输入：left = 1, right = 22
//输出：[1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
//示例 2:
//
//输入：left = 47, right = 85
//输出：[48, 55, 66, 77]
//
//
//提示：
//
//1 <= left <= right <= 104



//力扣第728题
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize) {
    int* arr = (int*)malloc(sizeof(int) * (right - left + 1));
    int  pos = 0;
    int flag = 0;
    for (int i = left; i <= right; i++) {
        int tmp = i;


        while (tmp > 0)
        {
            int n = tmp % 10;

            if (n == 0)
            {
                flag = 1;
                break;
            }
            if (i % n != 0)
            {
                flag = 1;
            }
            tmp = tmp / 10;
        }

        if (flag == 0)
        {
            arr[pos] = i;
            pos++;
        }
        flag = 0;
    }
    *returnSize = pos;
    return arr;
}