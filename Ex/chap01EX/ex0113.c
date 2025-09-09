// 演習1-13　九九の足し算表を表示（タイトル付き）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main( void ) {
	printf( "   |" );
	for( int i = 1; i <= 9; i++ )
		printf( "%3d" , i );
	printf( "\n---+---------------------------\n" );

	for( int i = 1; i <= 9; i++ ) {
		printf( "%2d |" , i );
		for( int j = 1; j <= 9; j++ )
			printf( "%3d" , i + j );
		putchar( '\n' );
	}

	while( 1 ) {
	}

	return 0;
}
