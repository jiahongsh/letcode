﻿//一个 /*句子 由一些 单词 以及它们之间的单个空格组成，句子的开头和结尾不会有多余空格。
//
//给你一个字符串数组 sentences ，其中 sentences[i] 表示单个 句子 。
//
//请你返回单个句子里 单词的最多数目 。
//
//
//
//示例 1：
//
//输入：sentences = ["alice and bob love leetcode", "i think so too", "this is great thanks very much"]
//输出：6
//解释：
//- 第一个句子 "alice and bob love leetcode" 总共有 5 个单词。
//- 第二个句子 "i think so too" 总共有 4 个单词。
//- 第三个句子 "this is great thanks very much" 总共有 6 个单词。
//所以，单个句子中有最多单词数的是第三个句子，总共有 6 个单词。
//示例 2：
//
//输入：sentences = ["please wait", "continue to fight", "continue to win"]
//输出：3
//解释：可能有多个句子有相同单词数。
//这个例子中，第二个句子和第三个句子（加粗斜体）有相同数目的单词数。*/


//力扣第2114题
int mostWordsFound(char** sentences, int sentencesSize) {
    int max = 1;
    for (int i = 0; i < sentencesSize; i++) {
        int count = 1;
        for (int j = 0; j < strlen(sentences[i]); j++) {

            if (sentences[i][j] == ' ') {
                count++;
            }

        }
        if (max < count) {
            max = count;
        }
    }
    return max;
}