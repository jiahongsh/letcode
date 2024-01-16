//编写一个函数来查找字符串数组中的最长公共前缀。
//
//如果不存在公共前缀，返回空字符串 ""。
//
//
//
//示例 1：
//
//输入：strs = ["flower", "flow", "flight"]
//输出："fl"
//示例 2：
//
//输入：strs = ["dog", "racecar", "car"]
//输出：""
//解释：输入不存在公共前缀。
//
//
//提示：
//
//1 <= strs.length <= 200
//0 <= strs[i].length <= 200
//strs[i] 仅由小写英文字母组成


//力扣第14题
char* longestCommonPrefix(char** strs, int strsSize) {


    int i = 0;

    int length = strlen(strs[0]);
    for (i = 0; i < length; i++) {
        int j = 1;
        for (j = 1; j < strsSize; j++) {
            if (strs[0][i] != strs[j][i]) {
                strs[0][i] = '\0';
                return strs[0];
            }

        }

    }
    return strs[0];
}


