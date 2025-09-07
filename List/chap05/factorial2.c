// 階乗値を再帰的に求める（条件演算子）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*--- 整数値nの階乗を返却（条件演算子） ---*/
int factorial(int n)
{
	return (n > 0) ? n * factorial(n - 1) : 1;
}

int main(void)
{
	int x;

	printf("整数を入力せよ：");
	scanf("%d", &x);

	printf("%dの階乗は%dです。\n", x, factorial(x));

	return 0;
}
