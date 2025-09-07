// 演習2-3　配列の要素の平均値を求める
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- 要素数nの配列aの要素の平均値を求める ---*/
double aveof( const int a[] , int n ) {
	double sum = 0;				// 合計値

	for( int i = 0; i < n; i++ )
		sum += a[i];

	return sum / n;
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

	printf( "平均値は%fです。\n" , aveof( height , number ) );

	free( height );								// 配列heightを破棄

	while( 1 ) {
	}

	return 0;
}
