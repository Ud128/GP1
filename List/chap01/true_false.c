// 0が偽で0以外が真であることを確認
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a;

	printf("aの値：");
	scanf("%d", &a);

	if (a) printf("ABC");

	while( 1 ) {
	}

	return 0;
}
