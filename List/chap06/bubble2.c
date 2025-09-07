// 単純交換ソート（第２版：交換回数による打切り）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 単純交換ソート（第２版：交換回数による打切り）---*/
void bubble( int a[] , int n ) {
	for( int i = 0; i < n - 1; i++ ) {
		int exchg = 0;				// パスにおける交換回数
		for( int j = n - 1; j > i; j-- )
			if( a[j - 1] > a[j] ) {
				swap( int , a[j - 1] , a[j] );
				exchg++;
			}
		if( exchg == 0 ) break;		// 交換が行われなかったら終了
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
