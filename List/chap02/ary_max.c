// 配列の要素の最大値を求める（要素の値を読み込む）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- 要素数nの配列aの要素の最大値を求める ---*/
int maxof( const int a[] , int n ) {  //int maxof( const int *a , int n ) {
	int max = a[0];				// 最大値

	for( int i = 1; i < n; i++ )
		if( a[i] > max ) max = a[i];

	return max;
}

int main( void ) {
	int number;					// 人数＝配列heightの要素数

	printf( "人数 : " );
	scanf( "%d" , &number );

	int *height = calloc( number , sizeof( int ) );	// 要素数numberの配列を生成 

	printf( "%d人の身長を入力してください。\n" , number );
	for( int i = 0; i < number; i++ ) {
		printf( "height[%d] : " , i );
		scanf( "%d" , &height[i] );
	}

	printf( "最大値は%dです。\n" , maxof( height , number ) );

	free( height );								// 配列heightを破棄

	while( 1 ) {
	}

	return 0;
}
