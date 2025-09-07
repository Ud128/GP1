// 演習6-5　配単純交換ソート（第３版：ソート過程の詳細を表示）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 単純交換ソート（第３版：走査範囲を限定）---*/
void bubble(int a[], int n)
{
	int ccnt = 0;		// 比較回数
	int scnt = 0;		// 交換回数
	int i = 0;			// パス
	int k = 0;			// a[k]より前はソートずみ

	while (k < n - 1) {
		int j;
		int last = n - 1;			// 最後に交換した位置

		printf("パス%d：\n", ++i);
		for (int j = n - 1; j > k; j--) {
			for (int m = 0; m < n - 1; m++)
				printf("%3d %c" , 
				a[m] , ( m != j - 1 /*チェック範囲外*/ ) ? ' ' : ( a[j - 1] > a[j] /*交換必要*/ ) ? '+' : '-' );
			printf("%3d\n", a[n - 1]);

			ccnt++;
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				last = j;
				scnt++;
			}
		}
		k = last;
		for (int m = 0; m < n; m++)
			printf("%3d  " , a[m]);
		putchar('\n');
	}
	printf("比較は%d回でした。\n", ccnt);
	printf("交換は%d回でした。\n", scnt);
}

int main(void)
{
	int nx;

	puts("単純交換ソート");
	printf("要素数 : ");
	scanf("%d", &nx);
	int *x = calloc(nx, sizeof(int));	// 要素数nxのint型配列xを生成

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	bubble(x, nx);						// 配列xを単純交換ソート

	puts("昇順にソートしました。");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);							// 配列xを破棄

	while( 1 ) {
	}

	return 0;
}
