﻿#include<string>

using namespace std;

//一个字符串如果没有 三个连续 相同字符，那么它就是一个 好字符串 。
//
//给你一个字符串 s ，请你从 s 删除 最少 的字符，使它变成一个 好字符串 。
//
//请你返回删除后的字符串。题目数据保证答案总是 唯一的 。
//
//
//
//示例 1：
//
//输入：s = "leeetcode"
//输出："leetcode"
//解释：
//从第一组 'e' 里面删除一个 'e' ，得到 "leetcode" 。
//没有连续三个相同字符，所以返回 "leetcode" 。
//示例 2：
//
//输入：s = "aaabaaaa"
//输出："aabaa"
//解释：
//从第一组 'a' 里面删除一个 'a' ，得到 "aabaaaa" 。
//从第二组 'a' 里面删除两个 'a' ，得到 "aabaa" 。
//没有连续三个相同字符，所以返回 "aabaa" 。
//示例 3：
//
//输入：s = "aab"
//输出："aab"
//解释：没有连续三个相同字符，所以返回 "aab" 。


//力扣第1975题
string makeFancyString(string s) {
    string res;   // 删除后的字符串
    // 遍历 s 模拟删除过程
    for (char ch : s) {
        int n = res.size();
        if (n >= 2 && res[n - 1] == ch && res[n - 2] == ch) {
            // 如果 res 最后两个字符与当前字符均相等，则不添加
            continue;
        }
        // 反之则添加
        res.push_back(ch);
    }
    return res;


}