// 演習2-8　配列の全要素を逆順にコピー
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- 要素数nの配列bの全要素を配列aにコピー ---*/
void ary_rcopy( int a[] , const int b[] , int n ) {
	for( int i = 0; i < n; i++ )
		a[i] = b[n - i - 1];	//逆順でコピー
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

	ary_rcopy( y , x , n );					// 配列xの全要素を配列yに逆順にコピー

	printf( "配列xの全要素を配列yに逆順にコピーしました。\n" );
	for( int i = 0; i < n; i++ )
		printf( "y[%d] = %d\n" , i , y[i] );

	free( x );							// 配列xを破棄
	free( y );							// 配列yを破棄

	while( 1 ) {
	}

	return 0;
}