// 1,000以下の素数を列挙（第２版）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main( void ) {
	int prime[500];							// 素数を格納する配列
	int ptr = 0;							// 既に得られた素数の個数
	unsigned long counter = 0;				// 除算の回数

	prime[ptr++] = 2;						// ２は素数である

	for( int n = 3; n <= 1000; n += 2 ) {	// 奇数のみを対象としてprime配列をforで一気に作る
		int i;
		for( i = 1; i < ptr; i++ ) {		// 既に得られた素数で割る
			counter++;
			if( n % prime[i] == 0 )			// 割り切れると素数ではない
				break;						// それ以上の繰返しは不要
		}
		if( ptr == i )						// 最後まで割り切れなかった
			prime[ptr++] = n;				// 配列に登録
	}

	for( int i = 0; i < ptr; i++ )			//最後にprim配列の中身を一気に出力
		printf( "%d\n" , prime[i] );

	printf( "除算を行った回数：%lu\n" , counter );

	while( 1 ) {
	}

	return 0;
}
