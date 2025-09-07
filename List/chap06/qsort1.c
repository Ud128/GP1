// qsort関数を利用して整数配列の要素を値の昇順にソート
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//--- int型の比較関数（昇順ソート用）---
int int_cmp(const int *a, const int *b)
{
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;
}

/*
//--- int型の比較関数（降順ソート用）---
int int_cmp( const int *a , const int *b ) {
	if( *a < *b )
		return 1;
	else if( *a > *b )
		return -1;
	else
		return 0;
}
*/

int main(void)
{
	int nx;

	printf("qsortによるソート\n");
	printf("要素数 : ");
	scanf("%d", &nx);
	int *x = calloc(nx, sizeof(int));	// 要素数nxのint型配列xを生成

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	qsort(x,											// 配列
		  nx,											// 要素数
		  sizeof(int),									// 要素の大きさ
		  (int (*)(const void *, const void *))int_cmp	// 比較関数
		 );

	puts("昇順にソートしました。");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);							// 配列xを破棄

	while( 1 ) {
	}

	return 0;
}
