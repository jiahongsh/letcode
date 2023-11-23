
//给你两个整数，被除数 dividend 和除数 divisor。将两数相除，要求 不使用 乘法、除法和取余运算。
//
//整数除法应该向零截断，也就是截去（truncate）其小数部分。例如，8.345 将被截断为 8 ， - 2.7335 将被截断至 - 2 。
//
//返回被除数 dividend 除以除数 divisor 得到的 商 。
//
//注意：假设我们的环境只能存储 32 位 有符号整数，其数值范围是[−231, 231 − 1] 。本题中，如果商 严格大于 231 − 1 ，则返回 231 − 1 ；如果商 严格小于 - 231 ，则返回 - 231 。
//
//
//
//示例 1:
//
//输入: dividend = 10, divisor = 3
//输出 : 3
//解释 : 10 / 3 = 3.33333..，向零截断后得到 3 。
//示例 2 :
//
//    输入 : dividend = 7, divisor = -3
//    输出 : -2
//    解释 : 7 / -3 = -2.33333..，向零截断后得到 - 2 。
//
//
//    提示：
//
//    - 231 <= dividend, divisor <= 231 - 1
//    divisor != 0



//力扣第29题
int divide(int dividend, int  divisor) {
    int count = 0;
    int flag = 0;

    if (dividend == 0)
        return 0;
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    if (dividend == INT_MIN && divisor == 1)
        return INT_MIN;
    if (dividend == INT_MIN && divisor == INT_MAX)
        return -1;
    if (dividend == divisor)
        return 1;
    if (divisor == INT_MIN)
        return 0;


    if (dividend < 0 && divisor > 0)
    {
        if (dividend == INT_MIN)
        {
            dividend += divisor;
            count++;
        }

        dividend = abs(dividend);
        flag = 1;
    }
    else if (dividend > 0 && divisor < 0)
    {
        divisor = abs(divisor);
        flag = 1;
    }
    else if (dividend < 0 && divisor < 0)
    {
        if (dividend == INT_MIN)
        {
            dividend -= divisor;
            count++;
        }

        dividend = abs(dividend);
        divisor = abs(divisor);
    }

    int a = abs(dividend);
    int b = abs(divisor);
    while (a >= b) {
        int c = 1;
        int s = b;
        // 需指数级快速逼近，以避免执行超时
        while (s < (a >> 1)) { // 逼近至一半，同时避免溢出
            s += s;
            c += c;
        }
        count += c;
        a -= s;
    }

    return flag ? -count : count;



}