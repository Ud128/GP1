// 演習6-10　２分挿入ソート/

#include <stdio.h>
#include <stdlib.h>

/*--- ２分挿入ソート ---*/
void bin_insertion(int a[], int n)
{
	int i, j;

	for (i = 1; i < n; i++) {
		int key = a[i];
		int pl = 0;								// 探索範囲先頭の添字
		int pr = i - 1;							// 　 〃 　末尾の添字
		int pc;									// 　 〃 　中央の添字

		do {
			pc = (pl + pr) / 2;
			if (a[pc] == key)					// 探索成功
				break;
			else if (a[pc] < key)
				pl = pc + 1;
			else
				pr = pc - 1;
		} while (pl <= pr);
		int pd = (pl <= pr) ? pc + 1 : pr + 1;	// 挿入すべ位置の添字

		for (j = i; j > pd; j--)
			a[j] = a[j - 1];
		a[pd] = key;
	}
}

int main(void)
{
	int nx;

	puts("２分挿入ソート");
	printf("要素数 : ");
	scanf("%d", &nx);
	int *x = calloc(nx, sizeof(int));	// 要素数nxのint型配列xを生成

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	bin_insertion(x, nx);				// 配列xを単純挿入ソート

	puts("昇順にソートしました。");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);							// 配列xを破棄

	return 0;
}
