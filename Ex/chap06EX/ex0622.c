// 演習6-22　度数ソート（最小値と最大値を指定）

#include <stdio.h>
#include <stdlib.h>

/*--- 度数ソート（配列要素の値はmin以上max以下） ---*/
void counting(int a[], int n, int min, int max)
{
	int *f = calloc(max - min + 2, sizeof(int));	// 累積度数
	int *b = calloc(n, sizeof(int));				// 作業用目的配列

	for (int i=0;	i <= max-min+1;	i++) f[i] = 0;					// [Step0]
	for (int i=0;	i < n;			i++) f[a[i]-min]++;				// [Step1]
	for (int i=1;	i <= max-min+1; i++) f[i] += f[i - 1];			// [Step2]
	for (int i=n-1; i >= 0;			i--) b[--f[a[i]-min]] = a[i];	// [Step3]
	for (int i=0;	i < n;			i++) a[i] = b[i];				// [Step4]

	free(b);
	free(f);
}
int main(void)
{
	int nx;
	int min, max;			// 最小値と最大値

	puts("度数ソート");
	printf("要素数 : ");
	scanf("%d", &nx);
	int *x = calloc(nx, sizeof(int));	// 要素数nxのint型配列xを生成

	printf("最小値：");
	scanf("%d", &min);

	while (1) {
		printf("最大値：");
		scanf("%d", &max);
		if (max > min) break;
		printf("%dより大きな値を入力してください。\n", min);
	}

	printf("%d～%dの整数を入力せよ。\n", min, max);
	for (int i = 0; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while (x[i] < min || x[i] > max);
	}

	counting(x, nx, min, max);			// 配列xを度数ソート

	puts("昇順にソートしました。");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);							// 配列xを破棄

	return 0;
}
