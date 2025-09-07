// 演習5-5 再帰に対する理解を深めるための真に再帰的な関数（呼び出し回数をカウント）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int counter = 0;	// 関数recurの呼び出し回数★

/*--- 真に再帰的な関数recur ---*/
void recur(int n)
{
	counter++;		//実際のカウントを取る部分★
	if (n > 0) {
		recur(n - 1);
		printf("%d\n", n);
		recur(n - 2);
	}
}

int main(void)
{
	int x;

	printf("整数を入力せよ：");
	scanf("%d", &x);

	recur(x);

	printf("関数recurは%d回呼び出されました。\n", counter);

	while( 1 ) {
	}

	return 0;
}
