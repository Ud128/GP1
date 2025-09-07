// 1,000以下の素数を列挙（第１版）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main( void ) {
	unsigned long counter = 0;	// 除算の回数

	
	for( int n = 2; n <= 1000; n++ ) {
		int i;
		for( i = 2; i < n; i++ ) {	//除算はnと同じになるまで行わくてもいい(同じまで行っても結果は同じ)
			counter++;
			if( n % i == 0 )		// 割り切れると素数ではない
				break;				// 割り切れる事が分かればそれ以上の繰返しは不要
		}
		if( n == i )				// 2まで加算し続け、最後まで割り切れなかった ★
			printf( "%d\n" , n );
	}
	
	/*
	紹介されてるのせ紹介はしなくていい
	for( int n = 2; n <= 1000; n++ ) {
		int isPrime = 1;  // 素数と仮定
		for( int i = 2; i * i <= n; i++ ) {
			counter++;
			if( n % i == 0 ) {
				isPrime = 0;  // 割り切れた → 素数じゃない
				break;
			}
		}
		if( isPrime )
			printf( "%d\n" , n );
	}
	*/
	/*
	//似た2個飛びを p.71 で紹介されてるのせ紹介はしなくていい
	printf( "2\n" );  // 最初に2を出力（唯一の偶数の素数）
	for( int n = 3; n <= 1000; n += 2 ) {  // 奇数のみチェック
		int i;
		for( i = 3; i < n; i += 2 ) {
			counter++;
			if( n % i == 0 )		// 割り切れると素数ではない①
				break;				// 割り切れる事が分かればそれ以上の繰返しは不要
		}
		if( n == i )				// 最後まで割り切れなかった②
			printf( "%d\n" , n );
	}
	*/
	printf( "除算を行った回数：%lu\n" , counter );

	while( 1 ) {
	}

	return 0;
}
