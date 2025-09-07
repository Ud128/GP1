// 演習2-5　配列の要素の並びを反転する（途中経過を表示）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- type型のxとyの値を交換 ---*/
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 要素数nの配列aの要素の並びを表示 ---*/
void ary_print( const int a[] , int n ) {
	for( int i = 0; i < n; i++ )
		printf( "%d " , a[i] );				// 逐次入れ替えられた結果を出力 例:52341
	putchar( '\n' );
}

/*--- 要素数nの配列aの要素の並びを反転 ---*/
void ary_reverse( int a[] , int n ) {
	for( int i = 0; i < n / 2; i++ ) {
		ary_print( a , n );
		printf( "a[%d]とa[%d]を交換します。\n" , i , n - i - 1 );	// ここが逐次的に入れ替えを伝えてくれているところ 例:a[0]とa[4]を交換します
		swap( int , a[i] , a[n - i - 1] );
	}
	ary_print( a , n );
	puts( "反転が終了しました。" );
}

int main( void ) {
	int nx;		// 配列xの要素数

	printf( "要素数：" );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// 要素数nxのint型配列xを生成

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	ary_reverse( x , nx );					// 配列xの要素の並びを反転

	printf( "要素の並びを反転しました。\n" );
	for( int i = 0; i < nx; i++ )
		printf( "x[%d] = %d\n" , i , x[i] );

	free( x );								// 配列xを破棄


	while( 1 ) {
	}

	return 0;
}

