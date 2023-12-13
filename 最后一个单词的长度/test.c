//给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。
//
//单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
//
//
//
//示例 1：
//
//输入：s = "Hello World"
//输出：5
//解释：最后一个单词是“World”，长度为5。
//示例 2：
//
//输入：s = "   fly me   to   the moon  "
//输出：4
//解释：最后一个单词是“moon”，长度为4。
//示例 3：
//
//输入：s = "luffy is still joyboy"
//输出：6
//解释：最后一个单词是长度为6的“joyboy”。
//
//
//提示：
//
//1 <= s.length <= 104
//s 仅有英文字母和空格 ' ' 组成
//s 中至少存在一个单词


//力扣第58题
int lengthOfLastWord(char* s) {
    //计算整个字符串的长度
    int ret = strlen(s);
    int i = 0;
    //数组下标
    int sum = ret - 1;
    int count = 0;//记录字符数
    //倒序找第一个完整单词

    //最后为空的情况，跳过
    while (s[sum] == ' ') {
        sum--;
    }
    //找到第一个字符进行循环，直遇到下一个空格
    while (s[sum] != ' ') {

        i++;
        sum--;
        count++;
        //只有一个单词时，sum会小于0，循环无法结束，但count已是正确答案
        if (sum < 0) {
            return count;
        }
    }


    return count;

}