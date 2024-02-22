//给你一个字符串 s ，将该字符串中的大写字母转换成相同的小写字母，返回新的字符串。
//
//
//
//示例 1：
//
//输入：s = "Hello"
//输出："hello"
//示例 2：
//
//输入：s = "here"
//输出："here"
//示例 3：
//
//输入：s = "LOVELY"
//输出："lovely"
//
//
//提示：
//
//1 <= s.length <= 100
//s 由 ASCII 字符集中的可打印字符组成



//力扣第709题
char* toLowerCase(char* s) {
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] <= 'Z' && s[i] >= 'A') {
            s[i] = s[i] + 'a' - 'A';
        }
    }
    return s;


}


char* toLowerCase(char* s) {
    int i = 0;
    for (i = 0; i < strlen(s); i++) {
        s[i] = tolower(s[i]);
    }
    return s;


}