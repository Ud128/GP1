// 演習6-9　単純挿入ソート（データはa[1]以降に格納されている）

#include <stdio.h>
#include <stdlib.h>

/*--- 単純挿入ソート（データはa[1]以降に格納されている）---*/
void insertion(int a[], int n)
{
	for (int i = 2; i <= n; i++) {
		int tmp = a[0] = a[i];
		int j;
		for (j = i; a[j - 1] > tmp; j--)
			a[j] = a[j - 1];
		if (j > 0) a[j] = tmp;
	}
}

int main(void)
{
	int nx;

	puts("単純挿入ソート");
	printf("要素数 : ");
	scanf("%d", &nx);
	int *x = calloc(nx + 1, sizeof(int));	// 要素数(nx+1)のint型配列xを生成

	for (int i = 1; i < nx + 1; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	insertion(x, nx);					// 配列xを単純挿入ソート

	puts("昇順にソートしました。");
	for (int i = 1; i < nx + 1; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);							// 配列xを破棄

	return 0;
}
