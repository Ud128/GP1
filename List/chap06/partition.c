// 配列の分割
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 配列を分割する ---*/
void partition( int a[] , int n ) {
	int pl = 0;			// 左カーソル
	int pr = n - 1;		// 右カーソル
	int x = a[n / 2];	// 枢軸は中央の要素

	do {
		while( a[pl] < x ) pl++;	// Lの値が枢軸の値より下回るうちは移動を続ける
		while( a[pr] > x ) pr--;	// Rの値が枢軸の値より上回るうちは移動を続ける
		if( pl <= pr ) {			//LとRの添字が交差してなければLRの位置の値を入れ替える
			swap( int , a[pl] , a[pr] );
			pl++;					//入れ替え済みの位置を一個飛び越え、続きをやる
			pr--;					//入れ替え済みの位置を一個飛び越え、続きをやる
		}
	} while( pl <= pr );			//LとRの添字が交差してなければ、続きを行う

	printf( "枢軸の値は%dです。\n" , x );

	printf( "枢軸以下のグループ\n" );			// 枢軸以下のグループ
	for( int i = 0; i <= pl - 1; i++ )			// a[0] ～ a[pl - 1]
		printf( "%d " , a[i] );
	putchar( '\n' );

	if( pl > pr + 1 ) {
		printf( "枢軸と一致するグループ\n" );	// 枢軸と同じグループ
		for( int i = pr + 1; i <= pl - 1; i++ )	// a[pr + 1] ～ a[pl - 1]
			printf( "%d " , a[i] );
		putchar( '\n' );
	}

	printf( "枢軸以上のグループ\n" );			// 枢軸以上のグループ
	for( int i = pr + 1; i < n; i++ )			// a[pr + 1] ～ a[n - 1]
		printf( "%d " , a[i] );
	putchar( '\n' );
}

int main( void ) {
	int nx;

	puts( "配列を分割します。" );
	printf( "要素数 : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// 要素数nxのint型配列xを生成

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	partition( x , nx );					// 配列xを分割

	free( x );							// 配列xを破棄

	while( 1 ) {
	}

	return 0;
}
