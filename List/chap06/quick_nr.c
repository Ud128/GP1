// クイックソート（非再帰版）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- クイックソート（非再帰版）---*/
void quick( int a[] , int left , int right ) {

	IntStack lstack;		// 分割すべき先頭要素の添字のスタック
	IntStack rstack;		// 分割すべき末尾要素の添字のスタック

	Initialize( &lstack , right - left + 1 );// 通常であれば8-0+1=9のサイズが確保される
	Initialize( &rstack , right - left + 1 );

	Push( &lstack , left );				// 先頭要素の添字
	Push( &rstack , right );			// 末尾要素の添字

	while( !IsEmpty( &lstack ) ) {
		int pl = ( Pop( &lstack , &left ) , left );		// Pop( &lstack , &left )が先にleftへpopし、left(左カーソル)をplに代入(コンマ演算子)
		int pr = ( Pop( &rstack , &right ) , right );	// Pop( &rstack , &right )が先にrightへpopし、right(右カーソル)をprに代入(コンマ演算子)
		int x = a[( left + right ) / 2];				// 枢軸は中央の要素

		do {
			while( a[pl] < x ) pl++;	// Lの値が枢軸の値より下回るうちは移動を続ける
			while( a[pr] > x ) pr--;	// Rの値が枢軸の値より上回るうちは移動を続ける
			if( pl <= pr ) {			// LとRの添字が交差してなければLRの位置の値を入れ替える
				swap( int , a[pl] , a[pr] );
				pl++;					// 入れ替え済みの位置を一個飛び越え、続きをやる
				pr--;					// 入れ替え済みの位置を一個飛び越え、続きをやる
			}
		} while( pl <= pr );			// LとRの添字が交差してなければ、続きを行う

		if( left < pr ) {
			Push( &lstack , left );		// 左グループの範囲の
			Push( &rstack , pr );		// 添字をプッシュ　
										// 動きは p.239 の Fig.6-22 にあり。大雑把に言うと、
										// 大きなグループから二個配列まで一度ソート終えた後popで大きな別のグループに戻り
										// 二個配列までソートを繰り返す形を繰り返す
		}
		if( pl < right ) {
			Push( &lstack , pl );		// 右グループの範囲の
			Push( &rstack , right );	// 添字をプッシュ
		}
	}

	Terminate( &lstack );
	Terminate( &rstack );
}

int main( void ) {
	int nx;

	puts( "クイックソート" );
	printf( "要素数 : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// 要素数nxのint型配列xを生成

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	quick( x , 0 , nx - 1 );				// 配列xをクイックソート

	puts( "昇順にソートしました。" );
	for( int i = 0; i < nx; i++ )
		printf( "x[%d] = %d\n" , i , x[i] );

	free( x );								// 配列xを破棄

	while( 1 ) {
	}

	return 0;
}
