// 演習3-2　線形探索（第１版：探索過程を表示）*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- 要素数nの配列aからkeyと一致する要素を線形探索 ---*/
int search(const int a[], int n, int key)
{
	printf("   |");
	for (int i = 0; i < n; i++)
		printf("%3d", i);		//添字(インデックス)を並べる
	printf("\n---+");
	for (int i = 0; i < n; i++)
		printf("---", i);
	printf("--\n");

	for (int i = 0; i < n; i++) {
		printf("   |");
		printf("%*s", 3 * (i - 1) + 5, "");//"%*s" は "可変幅"の文字列出力を行う指定子 例：printf("%*s", 10, "");　「幅10の空文字列を出力する」。"" は空文字列（長さ0）です
		printf("*\n");			// * を打つ
		printf("%3d|", i);
		for (int j = 0; j < n; j++)
			printf("%3d", a[j]);//配列の中身を並べる
		putchar('\n');

		if (a[i] == key)
			return i;			// 探索成功

		printf("   |\n");
	}

	return -1;					// 探索失敗
}

int main(void)
{
	int nx, ky;

	puts("線形探索（番兵法）");
	printf("要素数 : ");
	scanf("%d", &nx);
	int *x = calloc(nx + 1, sizeof(int));	// 要素数(nx + 1)のint型配列xを生成

	for (int i = 0; i < nx; i++) {			// 注意：値を読み込むのはnx個
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}
	printf("探す値 : ");
	scanf("%d", &ky);

	int idx = search(x, nx, ky);			// 配列xから値がkyの要素を線形探索

	if (idx == -1)
		puts("探索に失敗しました。");
	else
		printf("%dはx[%d]にあります。\n", ky, idx);

	free(x);								// 配列xを破棄

	while( 1 ) {
	}

	return 0;
}
