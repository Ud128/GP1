// シェルソート（第１版）

#include <stdio.h>
#include <stdlib.h>

/*--- シェルソート（第１版）---*/
void shell(int a[], int n)
{
	for (int h = n / 2; h > 0; h /= 2)
		for (int i = h; i < n; i++) {
			int tmp = a[i];
			int j;
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
				a[j + h] = a[j];
			a[j + h] = tmp;
		}
}

int main(void)
{
	int nx;

	puts("シェルソート");
	printf("要素数 : ");
	scanf("%d", &nx);
	int* x = calloc(nx, sizeof(int));	// 要素数nxのint型配列xを生成

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	shell(x, nx);				// 配列xをシェルソート

	puts("昇順にソートしました。");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);					// 配列xを破棄

	return 0;
}
