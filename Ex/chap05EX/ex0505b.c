// 演習5-5 真に再帰的な関数recurをメモ化して実現

#include <stdio.h>

int counter = 0;	// 関数recurの呼び出し回数

static char memo[128][1024];		// メモ用文字列の配列

/*--- メモ化を導入した関数recur ---*/
void recur(int n) {
	counter++;
	if (memo[n + 1][0] != '\0')
		printf("%s", memo[n + 1]);				// メモを出力
	else {
		if (n > 0) {
			recur(n - 1);
			printf("%d\n", n);
			recur(n - 2);
			sprintf(memo[n + 1], "%s%d\n%s", memo[n], n, memo[n - 1]);
		}
		else {
			strcpy(memo[n + 1], "");
		}
	}
}

int main(void)
{
	int x;

	printf("整数を入力せよ：");
	scanf("%d", &x);

	recur(x);

	printf("関数recurは%d回呼び出されました。\n", counter);

	return 0;
}
