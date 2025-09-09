// 演習1-2　三つの整数値の最小値を求める
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*--- a, b, cの最小値を求める ---*/
int min3( int a , int b , int c ) {
	int min = a;	// 最小値

	if( b < min ) min = b;
	if( c < min ) min = c;

	return min;
}

int main( void ) {
	int a , b , c;

	printf( "三つの整数の最小値を求めます。\n" );
	printf( "aの値：" );   scanf( "%d" , &a );
	printf( "bの値：" );   scanf( "%d" , &b );
	printf( "cの値：" );   scanf( "%d" , &c );

	printf( "最小値は%dです。\n" , min3( a , b , c ) );

	while( 1 ) {
	}

	return 0;
}
