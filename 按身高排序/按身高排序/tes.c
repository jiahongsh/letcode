//给你一个字符串数组 names ，和一个由 互不相同 的正整数组成的数组 heights 。两个数组的长度均为 n 。
//
//对于每个下标 i，names[i] 和 heights[i] 表示第 i 个人的名字和身高。
//
//请按身高 降序 顺序返回对应的名字数组 names 。
//
//
//
//示例 1：
//
//输入：names = ["Mary", "John", "Emma"], heights = [180, 165, 170]
//输出：["Mary", "Emma", "John"]
//解释：Mary 最高，接着是 Emma 和 John 。
//示例 2：
//
//输入：names = ["Alice", "Bob", "Bob"], heights = [155, 185, 150]
//输出：["Bob", "Alice", "Bob"]
//解释：第一个 Bob 最高，然后是 Alice 和第二个 Bob 。
//


//力扣第2413题
//数组
int cmp(const void* a, const void* b) {
    int* A = (int*)a;
    int* B = (int*)b;
    return B[0] - A[0];
}
char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    int arr[heightsSize][2];
    for (int i = 0; i < heightsSize; i++) {
        arr[i][0] = heights[i];
        arr[i][1] = i;
    }
    qsort(arr, heightsSize, sizeof(arr[0]), cmp);
    char** name = (char**)malloc(sizeof(char*) * heightsSize);
    for (int i = 0; i < heightsSize; i++) {
        int ret = arr[i][1];
        name[i] = names[ret];

    }
    *returnSize = heightsSize;
    return name;
}


//结构体
typedef struct {
    char* name;
    int hight;
}people;
int cmp(const void* a, const void* b) {
    people* A = (people*)a;
    people* B = (people*)b;
    return B->hight - A->hight;
}
char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    people ans[1000] = { 0 };

    for (int i = 0; i < heightsSize; i++) {
        ans[i].hight = heights[i];
        ans[i].name = names[i];
    }
    qsort(ans, heightsSize, sizeof(people), cmp);
    char** res = (char**)malloc(sizeof(char*) * heightsSize);
    for (int i = 0; i < heightsSize; i++) {
        res[i] = ans[i].name;

    }
    *returnSize = heightsSize;
    return res;
}