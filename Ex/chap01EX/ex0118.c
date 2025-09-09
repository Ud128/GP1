// 演習1-18　数字文字を並べて逆向きピラミッドを表示

#include <stdio.h>

/*--- 数字文字を並べて逆向きピラミッドを表示 ---*/
void nrpira( int n ) {
	for( int i = 1; i <= n; i++ ) {					// i行（i = 1, 2, … ,n）
		for( int j = 1; j <= i - 1; j++ )			// i-1個の' 'を表示
			putchar( ' ' );
		for( int j = 1; j <= ( n - i ) * 2 + 1; j++ )	// (n-i)*2+1個の数字を表示
			printf( "%d" , i % 10 );
		putchar( '\n' );
	}
}

int main( void ) {
	int n;

	puts( "ピラミッドを表示します。" );
	do {
		printf( "段数は：" );
		scanf( "%d" , &n );
	} while( n <= 0 );

	nrpira( n );

	return 0;
}
