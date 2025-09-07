// 1, 2, …, nの総和を求める（while文）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;

	puts("1からnまでの総和を求めます。");

	printf("nの値：");
	scanf("%d", &n);

	int sum = 0;		// 総和
	int i = 1;

	while (i <= n) {	// iがn以下であれば繰り返す
		sum += i;		// sumにiを加える
		i++;			// iの値をインクリメント
	}
	printf("1から%dまでの総和は%dです。\n", n, sum);

	while( 1 ) {
	}

	return 0;
}
