// 演習6-1　単純交換ソート（先頭側から走査）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 単純交換ソート ---*/
void bubble( int a[] , int n ) {

	/*
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				swap(int, a[j - 1], a[j]);
	}
	*/

	for( int i = n - 1; i > 0; i-- ) {		// i はソート済みの添字を示す（末尾から順にソートが完了）
		for( int j = 0; j < i; j++ )		// j は先頭から 隣接要素の比較と交換で i の直前まで逆方向にソートを進ませる
			if( a[j] > a[j + 1] )			// 隣接する2つの要素を比較し、最大値を末尾に進ませる
				swap( int , a[j] , a[j + 1] );
	}
}

int main( void ) {
	int nx;

	puts( "単純交換ソート" );
	printf( "要素数 : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// 要素数nxのint型配列xを生成

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	bubble( x , nx );						// 配列xを単純交換ソート

	puts( "昇順にソートしました。" );
	for( int i = 0; i < nx; i++ )
		printf( "x[%d] = %d\n" , i , x[i] );

	free( x );							// 配列xを破棄

	while( 1 ) {
	}

	return 0;
}
