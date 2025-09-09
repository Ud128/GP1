// 演習1-17　記号文字を並べてピラミッドを表示
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*--- 記号文字を並べてピラミッドを表示 ---*/
void spira( int n ) {
	for( int i = 1; i <= n; i++ ) {						// i行（i = 1, 2, … ,n）
		for( int j = 1; j <= n - i; j++ )				// n-i個の' 'を表示
			putchar( ' ' );								//一文字づつ文字を打っていく(わざと文字を入れていくと動きが見えやすくなる)
		for( int j = 1; j <= ( i - 1 ) * 2 + 1; j++ )	// (i-1)*2+1個の'*'を表示
			putchar( '*' );								//上のforの続きを打っていく
		putchar( '\n' );									//段の改行を行う
	}
}


int main( void ) {
	int n;

	puts( "ピラミッドを表示します。" );
	do {
		printf( "段数は：" );
		scanf( "%d" , &n );
	} while( n <= 0 );

	spira( n );

	while( 1 ) {
	}

	return 0;
}

