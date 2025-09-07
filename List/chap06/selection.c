// 単純選択ソート
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 単純選択ソート ---*/
void selection( int a[] , int n ) {
	for( int i = 0; i < n - 1; i++ ) {
		int min = i;						//毎回最小全チェックする
		for( int j = i + 1; j < n; j++ )	//毎回チェックするが、後に行くほど先頭が後ろに動く
			if( a[j] < a[min] )
				min = j;
		swap( int , a[i] , a[min] );
	}
}

int main( void ) {
	int nx;

	puts( "単純選択ソート" );
	printf( "要素数 : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// 要素数nxのint型配列xを生成

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	selection( x , nx );					// 配列xを単純選択ソート

	puts( "昇順にソートしました。" );
	for( int i = 0; i < nx; i++ )
		printf( "x[%d] = %d\n" , i , x[i] );

	free( x );								// 配列xを破棄

	while( 1 ) {
	}

	return 0;
}
