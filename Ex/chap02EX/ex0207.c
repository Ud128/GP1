// 演習2-7　配列の全要素をコピー
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- 要素数nの配列bの全要素を配列aにコピー ---*/
void ary_copy( int a[] , const int b[] , int n ) {
	for( int i = 0; i < n; i++ )
		a[i] = b[i];
}

int main( void ) {
	int n;		// 配列xとyの要素数

	printf( "要素数：" );
	scanf( "%d" , &n );
	int *x = calloc( n , sizeof( int ) );	// 要素数nのint型配列xを生成
	int *y = calloc( n , sizeof( int ) );	// 要素数nのint型配列yを生成

	printf( "%d個の整数を入力してください。\n" , n );
	for( int i = 0; i < n; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	ary_copy( y , x , n );					// 配列xの全要素を配列yにコピー

	printf( "配列xの全要素を配列yにコピーしました。\n" );
	for( int i = 0; i < n; i++ )
		printf( "y[%d] = %d\n" , i , y[i] );

	free( x );							// 配列xを破棄
	free( y );							// 配列yを破棄

	while( 1 ) {
	}

	return 0;
}