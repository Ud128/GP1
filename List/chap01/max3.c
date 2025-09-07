// 三つの整数値を読み込んで最大値を求める
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a, b, c;

	printf("三つの整数の最大値を求めます。\n");
	printf("aの値：");   scanf("%d", &a);
	printf("bの値：");   scanf("%d", &b);
	printf("cの値：");   scanf("%d", &c);

	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;

	printf("最大値は%dです。\n", max);

	while( 1 ) {
	}

	return 0;
}
