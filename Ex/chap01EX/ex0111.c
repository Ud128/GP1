// 演習1-11　正の整数値の桁数を求める

#include <stdio.h>

int main(void)
{
	int n;

	do {
		printf("正の整数値：");
		scanf("%d", &n);
	} while (n <= 0);

	int digits = 0;		// 桁数
	while (n > 0) {
		n /= 10;		// xを10で割る
		digits++;
	}

	printf("その数は%d桁です。\n", digits);

	return 0;
}
