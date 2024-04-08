#include<iostream>
#include<queue>
using namespace std;
//给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
//
//字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
//
//示例 1：
//
//输入：s = "abc", t = "ahbgdc"
//输出：true
//示例 2：
//
//输入：s = "axc", t = "ahbgdc"
//输出：false


//力扣第392题
//常规做法
bool isSubsequence(string s, string t) {
    int pos = 0;
    for (int i = 0; i < t.size(); i++) {
        if (s[pos] == t[i]) {
            pos++;
        }
        if (pos == t.size())break;
    }

    if (pos == s.size()) {
        return true;
    }
    return false;
}

//队列做法
bool isSubsequence(string s, string t) {
    queue<char>q;
    for (auto& c : s) {
        q.push(c);
    }

    for (auto& c : t) {
        if (q.front() == c)  q.pop();

    }
    if (q.empty())return true;

    return false;
}