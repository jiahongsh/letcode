﻿//键盘出现了一些故障，有些字母键无法正常工作。而键盘上所有其他键都能够正常工作。
//
//给你一个由若干单词组成的字符串 text ，单词间由单个空格组成（不含前导和尾随空格）；另有一个字符串 brokenLetters ，由所有已损坏的不同字母键组成，返回你可以使用此键盘完全输入的 text 中单词的数目。
//
//
//
//示例 1：
//
//输入：text = "hello world", brokenLetters = "ad"
//输出：1
//解释：无法输入 "world" ，因为字母键 'd' 已损坏。
//示例 2：
//
//输入：text = "leet code", brokenLetters = "lt"
//输出：1
//解释：无法输入 "leet" ，因为字母键 'l' 和 't' 已损坏。
//示例 3：
//
//输入：text = "leet code", brokenLetters = "e"
//输出：0
//解释：无法输入任何单词，因为字母键 'e' 已损坏。



//力扣第1935题
int canBeTypedWords(char* text, char* brokenLetters) {
    int i = 0;
    int sum = 0;
    int n = strlen(brokenLetters);
    while (text[i] != '\0') {
        int flag = 0;
        while (text[i] != ' ' && text[i] != '\0')
        {
            for (int j = 0; j < n; j++)
            {
                if (text[i] == brokenLetters[j])
                {
                    flag = 1;
                }
            }
            i++;

        }

        if (flag == 0)
            sum++;
       

        if (text[i] != '\0')
            i++;
       
    }
    return sum;
}