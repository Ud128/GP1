// 演習2-4　配列の要素の最大値を求める（人数と身長を乱数で生成）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*--- 要素数nの配列aの要素の最大値を求める ---*/
int maxof( const int a[] , int n ) {
	int max = a[0];				// 最大値

	for( int i = 1; i < n; i++ )
		if( a[i] > max ) max = a[i];

	return max;
}

int main( void ) {
	srand( time( NULL ) );							// 時刻から乱数の種を初期化

	int number = 5 + rand() % 16;				// 人数を5～20の乱数で決定

	int *height = calloc( number , sizeof( int ) );	// 要素数numberの配列を生成


	for( int i = 0; i < number; i++ ) {
		height[i] = 100 + rand() % 90;			// 100～189の乱数を生成・代入
		printf( "height[%d] = %d\n" , i , height[i] );
	}

	printf( "最大値は%dです。\n" , maxof( height , number ) );

	free( height );								// 配列heightを破棄

	while( 1 ) {
	}

	return 0;
}
