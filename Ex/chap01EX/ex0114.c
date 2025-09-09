// 演習1-14　正方形を表示
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main( void ) {
	int n;					// 段数

	puts( "正方形を表示します。" );
	do {
		printf( "段数は：" );
		scanf( "%d" , &n );
	} while( n <= 0 );

	for( int i = 1; i <= n; i++ ) {
		for( int j = 1; j <= n; j++ )
			putchar( '*' );
		putchar( '\n' );
	}

	while( 1 ) {
	}

	return 0;
}
