// 演習6-3　配列がソートずみであるかどうかを判定
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- 配列はソートずみか ---*/
int is_sorted( int a[] , int n ) {
	for( int i = n - 1; i > 0; i-- )
		if( a[i - 1] > a[i] )
			return 0;
	return 1;
}

int main( void ) {
	int nx , sorted;

	puts( "ソートずみチェック" );
	printf( "要素数 : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// 要素数nxのint型配列xを生成

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	sorted = is_sorted( x , nx );			// 配列xはソートずみか

	if( sorted )
		puts( "配列はソートずみです。" );
	else
		puts( "配列はソートされていません。" );

	free( x );								// 配列xを破棄

	while( 1 ) {
	}

	return 0;
}
