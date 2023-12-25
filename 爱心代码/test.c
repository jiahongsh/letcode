
//以笛卡尔函数为基础，数学解决实际问题
#include<stdio.h>
#include<Windows.h>


int main() {
	system("color 0c");
	float x, y;                   

		for (y = 1.5f; y > -1; y -= 0.1f) { 
			for (x = -1.5f; x < 1.5f; x +=0.05f) {
               float a = x * x + y * y - 1;
			     printf(a * a * a - x * x * y * y* y <0.0f ? "x" : " ");
			}
			Sleep(150);
		  printf("\n");
			
		}

	return 0;
}