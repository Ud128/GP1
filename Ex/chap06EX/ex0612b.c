// 演習6-12　シェルソート（第２版：要素の移動回数を表示）

#include <stdio.h>
#include <stdlib.h>

/*--- シェルソート（第２版：要素の移動回数を返却）---*/
int shell(int a[], int n)
{
	int h;
	int count = 0;					// 移動回数

	for (h = 1; h < n; h = h * 3 + 1)
		;

	for ( ; h > 0; h /= 3)
		for (int i = h; i < n; i++) {
			int	tmp = a[i];
			int j;
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {
				a[j + h] = a[j];
				count++;
			}
			a[j + h] = tmp;
			count++;
		}
	return count;
}

int main(void)
{
	int nx;

	puts("シェルソート");
	printf("要素数：");
	scanf("%d", &nx);
	int *x = calloc(nx, sizeof(int));	// 要素数nxのint型配列xを生成

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	int count = shell(x, nx);			// 配列xをシェルソート

	puts("昇順にソートしました。");
	for (int i =0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	printf("要素の移動回数は%d回でした。\n", count);

	free(x);							// 配列xを破棄

	return 0;
}
