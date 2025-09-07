// 演習6-21　度数ソート（ソート過程の詳細を表示）

#include <stdio.h>
#include <stdlib.h>

/*--- 度数ソート（配列要素の値は0以上max以下）---*/
void counting(int a[], int n, int max)
{
	int *f = calloc(max + 1, sizeof(int));		// 累積度数
	int *b = calloc(n,       sizeof(int));		// 作業用目的配列

	puts("\nソート前配列");
	for (int i = 0; i < n; i++) printf("%3d", i);		putchar('\n');
	for (int i = 0; i < n; i++) printf("---", i);		putchar('\n');
	for (int i = 0; i < n; i++) printf("%3d", a[i]);	putchar('\n');

	for (int i = 0;		i <= max; i++) f[i] = 0;			// [Step0]
	for (int i = 0;		i < n;	  i++) f[a[i]]++;			// [Step1]

	puts("\n度数分布");
	for (int i = 0; i < max; i++) printf("%3d", i);		putchar('\n');
	for (int i = 0; i < max; i++) printf("---", i);		putchar('\n');
	for (int i = 0; i < max; i++) printf("%3d", f[i]);	putchar('\n');

	for (int i = 1;		i <= max; i++) f[i] += f[i - 1];	// [Step2]

	puts("\n累積度数分布");
	for (int i = 0; i < max; i++) printf("%3d", i);		putchar('\n');
	for (int i = 0; i < max; i++) printf("---", i);		putchar('\n');
	for (int i = 0; i < max; i++) printf("%3d", f[i]);	putchar('\n');

	putchar('\n');
	for (int i = n - 1; i >= 0;	  i--) {					// [Step3]
		b[--f[a[i]]] = a[i];
		printf("a[%2d]の%2dをb[%2d]に格納。\n", i, a[i], f[a[i]]);
	}

	for (int i = 0;		i < n;	  i++) a[i] = b[i];			// [Step4]

	puts("\nソート後配列");
	for (int i = 0; i < n; i++) printf("%3d", i);		putchar('\n');
	for (int i = 0; i < n; i++) printf("---", i);		putchar('\n');
	for (int i = 0; i < n; i++) printf("%3d", a[i]);	putchar('\n');
	free(b);
	free(f);
}

int main(void)
{
	int nx;
	const int max = 100;			// 最大値

	puts("度数ソート");
	printf("要素数 : ");
	scanf("%d", &nx);
	int *x = calloc(nx, sizeof(int));

	printf("0～%dの整数を入力せよ。\n", max);
	for (int i = 0; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while (x[i] < 0 || x[i] > max);
	}

	counting(x, nx, max);		// 配列xを度数ソート

	puts("昇順にソートしました。");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);					// 配列xを破棄

	return 0;
}
