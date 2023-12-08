//给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。
//
//例如：
//
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28
//...
//
//
//示例 1：
//
//输入：columnNumber = 1
//输出："A"
//示例 2：
//
//输入：columnNumber = 28
//输出："AB"
//示例 3：
//
//输入：columnNumber = 701
//输出："ZY"
//示例 4：
//
//输入：columnNumber = 2147483647
//输出："FXSHRXW"
//
//
//提示：
//
//1 <= columnNumber <= 231 - 1


char* convertToTitle(int columnNumber) {
    char* ret = (char*)malloc(sizeof(char) * 10);
    int i = 0;
    while (columnNumber)
    {

        int j = columnNumber % 26;  //对取余结果进行分类讨论
        if (j > 0)
        {
            ret[i++] = j - 1 + 'A';
            columnNumber /= 26;
        }
        else if (j == 0)
        {
            columnNumber = (columnNumber - 26) / 26;
            ret[i++] = 'Z';
        }
    }
    ret[i] = 0;

    //将结果反转
    int left = 0;
    int right = i - 1;
    while (left < right)
    {
        char temp = ret[left];
        ret[left] = ret[right];
        ret[right] = temp;
        ++left;
        --right;
    }

    return ret;



}