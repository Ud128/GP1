// 演習6-14　クイックソート（要素数が小さい方のグループを優先的に分割：非再帰版）

// 本プログラムのコンパイルには"IntStack.h"および"IntStack.c"が必要です
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- クイックソート（非再帰版：要素数が小さい方のグループを優先的に分割）---*/
void quick( int a[] , int left , int right ) {
	IntStack lstack;		// 分割すべき先頭要素の添字のスタック
	IntStack rstack;		// 分割すべき末尾要素の添字のスタック

	Initialize( &lstack , right - left + 1 );
	Initialize( &rstack , right - left + 1 );

	Push( &lstack , left );
	Push( &rstack , right );

	while( !IsEmpty( &lstack ) ) {
		int pl = ( Pop( &lstack , &left ) , left );		// 左カーソル
		int pr = ( Pop( &rstack , &right ) , right );	// 右カーソル
		int x = a[( left + right ) / 2];				// 枢軸は中央の要素

		do {
			while( a[pl] < x ) pl++;	// Lの値が枢軸の値より下回るうちは移動を続ける
			while( a[pr] > x ) pr--;	// Rの値が枢軸の値より上回るうちは移動を続ける
			if( pl <= pr ) {			//LとRの添字が交差してなければLRの位置の値を入れ替える
				swap( int , a[pl] , a[pr] );
				pl++;					//入れ替え済みの位置を一個飛び越え、続きをやる
				pr--;					//入れ替え済みの位置を一個飛び越え、続きをやる
			}
		} while( pl <= pr );			//LとRの添字が交差してなければ、続きを行う


		//left ~ pr が 左側のグループ:pl ~ right が 右側のグループ
		//左側グループの方が要素数が少ないか？
		if( pr - left < right - pl ) {
			// 左の方が要素数が少ないので...
			if( pl < right ) {//ソートが終わっていない事を確認し、右側の処理で必要な方を先にプッシュ
				Push( &lstack , pl );
				Push( &rstack , right );
			}
			if( left < pr ) {//ソートが終わっていない事を確認し、左側の処理で必要な方を後にプッシュ
				Push( &lstack , left );
				Push( &rstack , pr );
			}
		}
		else {
			// 右の方が要素数が少ないので...
			if( left < pr ) {//ソートが終わっていない事を確認し、左側の処理で必要な方を先にプッシュ
				Push( &lstack , left );
				Push( &rstack , pr );
			}
			if( pl < right ) {//ソートが終わっていない事を確認し、右側の処理で必要な方を後にプッシュ
				Push( &lstack , pl );
				Push( &rstack , right );
			}
		}
		//この後の処理で後に入れた方が先にPopされるので、要素が少ない方が先に処理される

		/*
		//pl <-> left 　pl <-> left と入れ替えることで、変数名の意図はおいておいて、処理の順番を入れ替えることができる
		if( pr - left < right - pl ) {
			swap( int , pl , left );
			swap( int , pr , right );
		}
		if( left < pr ) {
			Push( &lstack , left );	// 左グループの範囲の
			Push( &rstack , pr );		// 添字をプッシュ
		}
		if( pl < right ) {
			Push( &lstack , pl );		// 右グループの範囲の
			Push( &rstack , right );	// 添字をプッシュ
		}
		*/
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

	free( x );							// 配列xを破棄

	while( 1 ) {
	}

	return 0;
}
