// 演習6-8　単純挿入ソート（挿入過程の詳細を表示）

#include <stdio.h>
#include <stdlib.h>

/*--- 単純挿入ソート（挿入過程の詳細を表示）---*/
void insertion(int a[], int n)
{
	for (int i = 1; i < n; i++) {
		int tmp = a[i];
		int j;

		for (int m = 0; m < n; m++)
			printf("%3d ", a[m]);
		putchar('\n');

		for (j = i; j > 0 && a[j - 1] > tmp; j--)
			a[j] = a[j - 1];
		a[j] = tmp;

		printf("%*s%s", 4 * j , "", (i != j) ? "^-" : "  ");
		for (int m = 0; m < 4*(i-j); m++)
			putchar('-');
		printf("+\n\n");
	}
	for (int m = 0; m < n; m++)
		printf("%3d ", a[m]);
	putchar('\n');
}

int main(void)
{
	int nx;

	puts("単純挿入ソート");
	printf("要素数 : ");
	scanf("%d", &nx);
	int *x = calloc(nx, sizeof(int));	// 要素数nxのint型配列xを生成

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	insertion(x, nx);					// 配列xを単純挿入ソート

	puts("昇順にソートしました。");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);							// 配列xを破棄

	return 0;
}
