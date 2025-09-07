// 演習5-2　ユークリッドの互除法によって最大公約数値を非再帰的に求める
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*--- 整数値x, yの最大公約数を返却する ---*/
int gcd( int x , int y ) {
	while( y != 0 ) {
		int temp = y;
		y = x % y;
		x = temp;
	}
	return x;
}

int main( void ) {
	int x , y;

	puts( "二つの整数の最大公約数を求めます。" );

	printf( "整数を入力せよ：" );
	scanf( "%d" , &x );

	printf( "整数を入力せよ：" );
	scanf( "%d" , &y );

	printf( "最大公約数は%dです。\n" , gcd( x , y ) );

	while( 1 ) {
	}

	return 0;
}
