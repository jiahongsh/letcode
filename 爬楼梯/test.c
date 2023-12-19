//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//
//
//
//示例 1：
//
//输入：n = 2
//输出：2
//解释：有两种方法可以爬到楼顶。
//1. 1 阶 + 1 阶
//2. 2 阶
//示例 2：
//
//输入：n = 3
//输出：3
//解释：有三种方法可以爬到楼顶。
//1. 1 阶 + 1 阶 + 1 阶
//2. 1 阶 + 2 阶
//3. 2 阶 + 1 阶



//力扣第70题
//递归算法
int fib(int n){
    if(n==2){
        return 2;
    }
    if(n==1){
        return 1;
    }else{
        return fib(n-1)+fib(n-2);
    }

}


int climbStairs(int n) {
   int ret= fib(n);
   return ret;
}


//根据规律直接递推
int climbStairs(int n) {
    int val = 1;
    int next = 2;
    int sum = 0;
    if (n == 1) {
        return val;
    }
    if (n == 2) {
        return next;
    }

    int i = 0;
    for (i = 2; i < n; i++) {
        sum = val + next;
        val = next;
        next = sum;
    }
    return sum;
}