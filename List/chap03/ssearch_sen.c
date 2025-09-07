// 線形探索（番兵法）

#include <stdio.h>
#include <stdlib.h>

/*--- 要素数nの配列aからkeyと一致する要素を線形探索（番兵法）---*/
int search(int a[], int n, int key)
{
	int i = 0;

	a[n] = key;			// 番兵を追加

	while (1) {
		if (a[i] == key)
			break;		// 見つけた
		i++;
	}

	return i == n ? -1 : i;
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

	return 0;
}
