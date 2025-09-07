// int型の配列の初期化と表示（要素数を変更）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main( void ) {

	int a[] = { 1, 2, 3, 4, 5, 6 };
	int na = sizeof( a ) / sizeof( a[0] );	// 要素数

	printf( "配列aの要素数は%dです。\n" , na );

	for( int i = 0; i < na; i++ )
		printf( "a[%d] = %d\n" , i , a[i] );

	while( 1 ) {

	}

	return 0;
}
