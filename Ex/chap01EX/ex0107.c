// 演習1-7　1, 2, …, nの総和を求める（for文：式を表示）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main( void ) {
	int n;

	puts( "1からnまでの総和を求めます。" );

	printf( "nの値：" );
	scanf( "%d" , &n );

	int sum = 0;		// 総和

	for( int i = 1; i <= n; i++ )	// i = 1, 2, …, n
		sum += i;					// sumにiを加える

	for( int i = 1; i < n; i++ )
		printf( "%d + " , i );
	printf( "%d = %d\n" , n , sum );

	while( 1 ) {
	}

	return 0;
}
