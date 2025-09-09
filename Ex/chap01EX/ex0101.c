// 演習1-1　四つの整数値の最大値を求める
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*--- a, b, c, dの最大値を求める ---*/
int max4( int a , int b , int c , int d ) {
	int max = a;	// 最大値

	if( b > max ) max = b;
	if( c > max ) max = c;
	if( d > max ) max = d;

	return max;
}

int main( void ) {
	int a , b , c , d;

	printf( "四つの整数の最大値を求めます。\n" );
	printf( "aの値：" );   scanf( "%d" , &a );
	printf( "bの値：" );   scanf( "%d" , &b );
	printf( "cの値：" );   scanf( "%d" , &c );
	printf( "dの値：" );   scanf( "%d" , &d );

	printf( "最大値は%dです。\n" , max4( a , b , c , d ) );

	while( 1 ) {
	}

	return 0;
}

