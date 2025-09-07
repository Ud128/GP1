// 再帰に対する理解を深めるための真に再帰的な関数（末尾再帰を除去）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*--- 関数recur（末尾再帰を除去）---*/
void recur( int n ) {
Top:
	if( n > 0 ) {
		recur( n - 1 );
		printf( "%d\n" , n );
		n = n - 2;
		goto Top;
	}
}

int main( void ) {
	int x;

	printf( "整数を入力せよ：" );
	scanf( "%d" , &x );

	recur( x );

	while( 1 ) {

	}

	return 0;
}
