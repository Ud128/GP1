// 演習2-6　整数を2進数～36進数に基数変換（変換過程を表示）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*--- type型のxとyの値を交換 ---*/
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 整数値xをn進数に変換して配列dに下位桁から格納 ---*/
int card_conv( unsigned x , int n , char d[] ) {//unsigned は unsigned int の略の書き方. d[] は進数結果の出力先を受け取ってる
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int  digits = 0;						// 変換後の桁数

	if( x == 0 )								// 0であれば
		d[digits++] = dchar[0];				// 変換後も0
	else {
		while( x ) {
			printf( "%2d  |%7d   … %c\n" , n , x , dchar[x % n] );//%2d  %7d の2や7は書式指定子のスベース　それをd(decimlで出せ)という意味 
			printf( "    +----------\n" );
			d[digits++] = dchar[x % n];		// nで割った剰余を格納
			x /= n;
		}
		printf( "       %5d\n" , x );		//計算の終わりで0になったことを出力(この0は進数に含まない)
	}

	for( int i = 0; i < digits / 2; i++ )	// 配列dの並びを反転(上の計算から並びを反転させ、正しく並べる)
		swap( char , d[i] , d[digits - i - 1] );

	return digits;
}

int main( void ) {
	puts( "10進数を基数変換します。" );

	int retry;				// もう一度？

	do {
		unsigned no;		// 変換する整数
		int      cd;		// 基数
		char     cno[512];	// 変換後の数値の各桁の数字を格納する文字の配列 

		printf( "変換する非負の整数：" );//正の整数
		scanf( "%u" , &no );

		do {
			printf( "何進数に変換しますか（2-36）：" );
			scanf( "%d" , &cd );
		} while( cd < 2 || cd > 36 );

		int dno = card_conv( no , cd , cno );	// noをdno桁のcd進数に変換

		printf( "%d進数では" , cd );
		for( int i = 0; i < dno; i++ )		// 各桁の文字を順に表示
			printf( "%c" , cno[i] );
		printf( "です。\n" );

		printf( "もう一度しますか（1…はい／0…いいえ）：" );
		scanf( "%d" , &retry );
	} while( retry == 1 );

	while( 1 ) {
	}

	return 0;
}
