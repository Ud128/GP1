// 単純挿入ソート
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- 単純挿入ソート ---*/
void insertion(int a[], int n)
{
	for (int i = 1; i < n; i++) {					//1添字1から一個づつ値をチェックしていく
		int tmp = a[i];								//調べる値を一時確保
		int j;
		for (j = i; j > 0 && a[j - 1] > tmp; j--)	//捕まえている値の左隣が大きいうちは数字を次々移動させていく
			a[j] = a[j - 1];
		a[j] = tmp;									//上のforが完了したら確保しておいた値を終了時点のjに代入する
	}
}

int main(void)
{
	int nx;

	puts("単純挿入ソート");
	printf("要素数 : ");
	scanf("%d", &nx);
	int* x = calloc(nx, sizeof(int));	// 要素数nxのint型配列xを生成

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	insertion(x, nx);					// 配列xを単純挿入ソート

	puts("昇順にソートしました。");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);							// 配列xを破棄

	while( 1 ) {
	}

	return 0;
}
