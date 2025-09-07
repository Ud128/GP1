// 配列の要素の並びを反転する
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- type型のxとyの値を交換 ---*/
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0) // if 文で{}を使ってあげてるとdo while無しで問題ない { type t = x; x = y; y = t; } 

// void* 版 swap関数
void vt_swap( size_t size , void *a , void *b ) {//引数内では初期化が行われているので、*がついていても渡す物はアドレスである必要がある
	//※注意：swap( sizeof(int) , &a[i] , &a[n - i - 1]);と呼び出し部分を書きなおす
	void *t = malloc( size );	//この関数内で型を持たずに値を受け取るので、いったんマロックで型の大きさを指定して、オブジェクトtをヒープに確保
	if( t == NULL ) {
		printf( "Error: メモリ確保に失敗しました\n" );
	}
	else {

		memcpy( t , a , size);	//aをtにバイト単位で複製
		memcpy( a , b , size );	//bをaにバイト単位で複製
		memcpy( b , t , size );	//tをbにバイト単位で複製

		free( t );				//tのヒープを解放
	}
}


/*--- 要素数nの配列aの要素の並びを反転 ---*/
void ary_reverse(int a[], int n)
{
	for (int i = 0; i < n / 2; i++)
		swap( int , a[i] , a[n - i - 1]);
}

int main(void)
{
	int nx;		// 配列xの要素数

	printf("要素数：");
	scanf("%d", &nx);
	int *x = calloc(nx, sizeof(int));	// 要素数nxのint型配列xを生成

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	ary_reverse(x, nx);					// 配列xの要素の並びを反転

	printf("要素の並びを反転しました。\n");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);							// 配列xを破棄

	while( 1 ) {
	}

	return 0;
}
