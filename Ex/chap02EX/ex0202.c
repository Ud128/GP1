// 演習2-2　配列の要素の合計値を求める
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*--- 要素数nの配列aの要素の合計値を求める ---*/
int sumof( const int a[] , int n ) {
	int sum = 0;				// 合計値

	for( int i = 0; i < n; i++ )
		sum += a[i];

	return sum;
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

	printf( "合計値は%dです。\n" , sumof( height , number ) );

	free( height );								// 配列heightを破棄

	while( 1 ) {
	}

	return 0;
}
