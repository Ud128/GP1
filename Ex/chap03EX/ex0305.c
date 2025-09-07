// 演習3-5　２分探索（最も先頭に位置する要素を探索）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- 要素数nの配列aからkeyと一致する要素を２分探索（最も先頭に位置する要素を探索）---*/
int bin_search2(const int a[], int n, int key)
{
	int pl = 0;						// 探索範囲の先頭の添字
	int pr = n - 1;					// 　　〃　　末尾の添字


	do {
		int pc = (pl + pr) / 2;		// 　　〃　　中央の添字
		if (a[pc] == key) {			// 探索成功
			while (pc > pl && a[pc - 1] == key)//cよりも前の方に同じ数字がいないかインデックスをa[pc - 1]で巻き戻す　※昇順なのでこれで成功する
				pc--;
			return pc;
		} else if (a[pc] < key)
			pl = pc + 1;			// 探索範囲を後半に絞り込む
		else
			pr = pc - 1;			// 探索範囲を前半に絞り込む
	} while (pl <= pr);

	return -1;						// 探索失敗
}

int main(void)
{
	int nx, ky;

	puts("２分探索");
	printf("要素数 : ");
	scanf("%d", &nx);

	int *x = calloc(nx, sizeof(int));	// 要素数nxのint型配列xを生成

	printf("昇順に入力してください。\n");
	printf("x[0] : ");
	scanf("%d", &x[0]);

	for (int i = 1; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while (x[i] < x[i - 1]);		// 一つ前の値よりも小さければ再入力
	}
	printf("探す値 : ");
	scanf("%d", &ky);

	int idx = bin_search2(x, nx, ky);	// 配列xから値がkyの要素を２分探索

	if (idx == -1)
		puts("探索に失敗しました。");
	else
		printf("%dはx[%d]にあります。\n", ky, idx);

	free(x);							// 配列xを破棄

	while( 1 ) {
	}

	return 0;
}
