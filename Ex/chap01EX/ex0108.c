// 演習1-8　1, 2, …, nの総和を求める（ガウスの方法）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main( void ) {
	int n;

	puts( "1からnまでの和を求めます。" );

	printf( "nの値：" );
	scanf( "%d" , &n );

	int sum = ( n + 1 ) * ( n / 2 ) + ( n % 2 == 1 ? ( n + 1 ) / 2 : 0 );

	//int sum = ( n * ( n + 1 ) ) / 2;

	printf( "1から%dまでの和は%dです。\n" , n , sum );

	while( 1 ) {
	}

	return 0;
}
