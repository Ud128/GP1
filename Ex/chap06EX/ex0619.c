// 演習6-19　汎用マージソート
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *buff;			// 作業用配列

/*--- 汎用マージソート（メイン部）void で書くので常にポインターをsize掛けで書きなおしていく ---*/
void __mergesort( char *a , size_t left , size_t right , size_t size ,
				  int ( *compar )( const void * , const void * ) ) {
	if( left < right ) {
		size_t center = ( left + right ) / 2;
		size_t p = 0;
		size_t i;
		size_t j = 0;
		size_t k = left;

		__mergesort( a , left , center , size , compar );		// 前半部をマージソート 最後の引数に 比較関数m_sort を渡せるように書く
		__mergesort( a , center + 1 , right , size , compar );	// 後半部をマージソート 最後の引数に 比較関数m_sort を渡せるように書く

		for( i = left; i <= center; i++ )
			memcpy( &buff[p++ * size] , &a[i * size] , size );

		while( i <= right && j < p )
			memcpy( &a[k++ * size] , compar( (const void *)&buff[j * size] , (const void *)&a[i * size] ) <= 0 ?
					&buff[j++ * size] : &a[i++ * size] , size );

		while( j < p )
			memcpy( &a[k++ * size] , &buff[j++ * size] , size );
	}
}

/*--- 汎用マージソート ---*/
void m_sort( void *base , size_t nmemb , size_t size ,
			 int ( *compar )( const void * , const void * ) ) {
	if( nmemb > 0 ) {
		buff = calloc( nmemb , size );

		__mergesort( base , 0 , nmemb - 1 , size , compar );		// 配列全体をマージソート

		free( buff );
	}
}

/*--- int型の比較関数（昇順ソート用） ---*/
int int_cmp( const int *a , const int *b ) {
	return *a < *b ? -1 : *a > *b ? 1 : 0;
}

int main( void ) {
	int nx;

	printf( "m_sortによるソート\n" );
	printf( "要素数 : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// 要素数nxのint型配列xを生成

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	m_sort( x ,											// 配列
			nx ,										// 要素数
			sizeof( int ) ,								// 要素の大きさ
			( int ( * )( const void * , const void * ) )int_cmp	// 比較関数
	);

	puts( "昇順にソートしました。" );
	for( int i = 0; i < nx; i++ )
		printf( "x[%d] = %d\n" , i , x[i] );

	free( x );							// 配列xを破棄

	while( 1 ) {
	}

	return 0;
}
