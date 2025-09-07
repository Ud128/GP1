// 演習3-3　配列中の任意の値と一致する全要素の添字を抽出
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- 配列a中の値がkeyである全要素の添字をidxに格納 ---*/
int search_idx( const int a[] , int n , int key , int idx[] ) {
	int count = 0;

	for( int i = 0; i < n; i++ )
		if( a[i] == key )
			idx[count++] = i;
	return count;
}

int main( void ) {
	int nx , ky;

	puts( "線形探索（全要素を探索）" );
	printf( "要素数 : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );		// 要素数nxのint型配列xを生成
	int *idx = calloc( nx , sizeof( int ) );		// 要素数nxのint型配列idxを生成

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}
	printf( "探す値 : " );
	scanf( "%d" , &ky );

	int no = search_idx( x , nx , ky , idx );	// 配列xから値がkyの全要素を線形探索

	if( no == -1 )
		puts( "一致する要素は存在しません。" );
	else {
		printf( "一致する要素は以下の%d個です。\n" , no );
		for( int i = 0; i < no; i++ )
			printf( "x[%d] " , idx[i] );
		putchar( '\n' );
	}

	free( x );								// 配列xを破棄
	free( idx );								// 配列idxを破棄

	while( 1 ) {
	}

	return 0;
}
