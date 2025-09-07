// int型の配列の初期化と表示

#include <stdio.h>

int main(void)
{
	int a[5] = {1, 2, 3, 4, 5};
	int na = sizeof(a) / sizeof(a[0]);	// 要素数

	printf("配列aの要素数は%dです。\n", na);

	for (int i = 0; i < na; i++)
		printf("a[%d] = %d\n", i, a[i]);

	return 0;
}
