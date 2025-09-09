// 演習1-6　1, 2, …, nの和を求める（while文終了時の変数iの値を確認）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main( void ) {
	int n;

	puts( "1からnまでの総和を求めます。" );

	printf( "nの値：" );
	scanf( "%d" , &n );

	int sum = 0;		// 総和
	int i = 1;

	while( i <= n ) {	// iがn以下であれば繰り返す
		sum += i;		// sumにiを加える
		i++;			// iの値をインクリメント
	}
	printf( "1から%dまでの総和は%dです。\n" , n , sum );

	printf( "変数iの値は%dで、n + 1と%s。\n" ,
			i , ( i == n + 1 ) ? "等しいです" : "等しくありません" );

	while( 1 ) {
	}

	return 0;
}
