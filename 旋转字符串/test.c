#include<stdbool.h>

//给定两个字符串, s 和 goal。如果在若干次旋转操作之后，s 能变成 goal ，那么返回 true 。
//
//s 的 旋转操作 就是将 s 最左边的字符移动到最右边。
//
//例如, 若 s = 'abcde'，在旋转一次之后结果就是'bcdea' 。
//
//
//示例 1:
//
//输入: s = "abcde", goal = "cdeab"
//输出 : true
//示例 2 :
//
//    输入 : s = "abcde", goal = "abced"
//    输出 : false
//
//
//    提示 :
//
//    1 <= s.length, goal.length <= 100
//    s 和 goal 由小写英文字母组成


//力扣第796题
void left_move(char* s, int length1) {
    char tmp = s[0];
    int i = 0;
    for (i = 0; i < length1 - 1; i++) {
        s[i] = s[i + 1];
    }
    s[length1 - 1] = tmp;
}

bool rotateString(char* s, char* goal) {
    int length = strlen(s);
    int length1 = length;
    int flag = 0;
    while (length--) {
        left_move(s, length1);
        if (strcmp(s, goal) == 0) {
            flag = 1;
        }
    }

    if (flag == 1) {
        return true;
    }

    return false;
}


