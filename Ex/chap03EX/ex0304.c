// 演習3-4　２分探索（探索過程を表示）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- 要素数nの配列aからkeyと一致する要素を２分探索 ---*/
int bin_search(const int a[], int n, int key)
{
	int pl = 0;						// 探索範囲の先頭の添字
	int pr = n - 1;					// 　　〃　　末尾の添字

	printf("   |");
	for (int i = 0; i < n; i++)
		printf("%4d", i);
	printf("\n---+");
	for (int i = 0; i < n; i++) 
		printf("----", i);
	printf("--\n");

	do {
		int pc = (pl + pr) / 2;			// 探索範囲の中央の添字

		printf("   |");
		for (int i = 0; i < 4 * pl; i++)//左の開始位置まで空白で埋める
			printf(" "); 

		// <- + -> 現在どこを探しているかの範囲を書く
		printf( " <-" );				//上の空白の隣に<矢印<-を書く
		for (int i = 0; i < 4 * (pc - pl); i++) //左からセンターの間を空白で埋める
			printf(" "); 
		printf("+");					//センターに+を書く
		for (int i = 0; i < 4 * (pr - pc) - 2; i++) //右からセンターの間を空白で埋める
			printf(" "); 
		printf("->\n");					//上の空白の隣に->を書く


		printf("%3d|", pc);
		for (int i = 0; i < n; i++)
			printf("%4d", a[i]);
		putchar('\n');

		if (a[pc] == key)			// 探索成功
			return pc;
		else if (a[pc] < key)
			pl = pc + 1;			// 探索範囲を後半に絞り込む
		else
			pr = pc - 1;			// 探索範囲を前半に絞り込む

		printf("   |\n");

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

	int idx = bin_search(x, nx, ky);	// 配列xから値がkyの要素を２分探索

	if (idx == -1)
		puts("探索に失敗しました。");
	else
		printf("%dはx[%d]にあります。\n", ky, idx);

	free(x);							// 配列xを破棄

	while( 1 ) {
	}

	return 0;
}
