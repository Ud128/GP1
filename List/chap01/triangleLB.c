// 左下側が直角の二等辺三角形を表示
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;

	do {
		printf("何段の三角形ですか：");
		scanf("%d", &n);
	} while (n <= 0);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			putchar('*');
		putchar('\n');
	}

	while( 1 ) {
	}

	return 0;
}
