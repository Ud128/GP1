// 演習5-1　階乗値を非再帰的に求める
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*--- 整数値nの階乗を返却 ---*/
int factorial( int n ) {
	int fact = 1;

	while( n > 1 )
		fact *= n--;

	/*
	4の階乗を求める例
	while(n > 1) {
		fact *= n;  // 1回目: fact = 1 * 4 = 4
		n--;        // n = 3
		fact *= n;  // 2回目: fact = 4 * 3 = 12
		n--;        // n = 2
		fact *= n;  // 3回目: fact = 12 * 2 = 24
		n--;        // n = 1 → ループ終了
	}
	return fact;  // → 24
	*/


	/*
	//下から上にかけるやりかた
	for (int i = 1; i <= n; i++) {
		fact *= i;  // fact = fact × i;
	}
	*/

	return fact;
}

int main( void ) {
	int x;

	printf( "整数を入力せよ：" );
	scanf( "%d" , &x );

	printf( "%dの階乗は%dです。\n" , x , factorial( x ) );

	while( 1 ) {
	}

	return 0;
}
