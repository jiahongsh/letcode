//给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
//
//回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
//
//例如，121 是回文，而 123 不是。
//
//
//示例 1：
//
//输入：x = 121
//输出：true
//示例 2：
//
//输入：x = -121
//输出：false
//解释：从左向右读, 为 - 121 。 从右向左读, 为 121 - 。因此它不是一个回文数。
//示例 3：
//
//输入：x = 10
//输出：false
//解释：从右向左读, 为 01 。因此它不是一个回文数。
//
//
//提示：
//
//- 231 <= x <= 231 - 1
//
//
//进阶：你能不将整数转为字符串来解决这个问题吗？


//力扣第9题
bool isPalindrome(int x) {
    int max = 2147483647;

    if (x > max || x * 10 > max) {
        return false;
    }
    if (x < 0) {
        return false;
    }
    int arr[1000];
    int i = 0;
    int count = x;
    int flag = 0;
    while (count != 0) {
        int tmp = count % 10;
        arr[i++] = tmp;
        count /= 10;
        flag++;
    }
    long sum = 0;
    for (i = 0; i < flag; i++) {
        sum = sum * 10 + arr[i];
    }

    if (sum == x) {
        return true;
    }
    return false;

}

