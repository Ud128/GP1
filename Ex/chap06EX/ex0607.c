// 演習6-7　単純選択ソート（ソート過程の詳細を表示）

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 単純選択ソート（ソート過程の詳細を表示）---*/
void selection(int a[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		for (int m = 0; m < n; m++)
			printf((m == i) ? "  * " : (m == min) ? "  + " : "    ");
		putchar('\n');

		for (int m = 0; m < n; m++)
			printf("%3d ", a[m]);
		putchar('\n');

		swap(int, a[i], a[min]);
	}
	putchar('\n');
	for (int m = 0; m < n; m++)
		printf("%3d ", a[m]);
	putchar('\n');
}

int main(void)
{
	int nx;

	puts("単純選択ソート");
	printf("要素数 : ");
	scanf("%d", &nx);
	int *x = calloc(nx, sizeof(int));	// 要素数nxのint型配列xを生成

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	selection(x, nx);					// 配列xを単純選択ソート

	puts("昇順にソートしました。");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);							// 配列xを破棄

	return 0;
}

