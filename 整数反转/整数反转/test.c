﻿//给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
//
//如果反转后整数超过 32 位的有符号整数的范围[−231, 231 − 1] ，就返回 0。
//
//假设环境不允许存储 64 位整数（有符号或无符号）。
//
//
//示例 1：
//
//输入：x = 123
//输出：321
//示例 2：
//
//输入：x = -123
//输出： - 321
//示例 3：
//
//输入：x = 120
//输出：21
//示例 4：
//
//输入：x = 0
//输出：0
#include<stdio.h>
int reverse(int x){  
  long ret = 0;
  while (x != 0) {
      ret = ret * 10 + x % 10;
       x /= 10;
}
  if ((int)ret != ret) {
      return 0;
  }
   return (int)ret;

  }


int main() {
    int x;
    scanf_s("%d", &x);
    int ret=reverse(x);
    if (ret == 0) {
        printf("超过整数范围\n");
    }
    else {
          printf("%d", ret);
    }
    
	return 0;
}