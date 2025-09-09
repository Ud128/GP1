// 演習1-12　九九の表を表示（タイトル付き）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main( void ) {
	printf( "   |" );
	for( int i = 1; i <= 9; i++ )
		printf( "%3d" , i );				//最初の一列目
	printf( "\n---+---------------------------\n" );	//二列目の線

	for( int i = 1; i <= 9; i++ ) {
		printf( "%2d |" , i );				//最初の一行目になる数字と縦線
		for( int j = 1; j <= 9; j++ )
			printf( "%3d" , i * j );		//列の掛け算の答え
		putchar( '\n' );
	}

	while( 1 ) {
	}

	return 0;
}
