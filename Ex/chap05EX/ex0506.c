// 演習5-6　関数recur3を非再帰的に実現

// 注：本プログラムのコンパイルには"IntStack.h"と"IntStack.c"が必要です。
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntStack.h"

/*--- 関数recur3（再帰を除去）---*/
void recur3( int n ) {

	/*
	if( n > 0 ) {
		recur3( n - 1 );
		recur3( n - 2 );
		printf( "%d\n" , n );
	} 
	*/
	//4を入力したときの出力:1213124

	int sw = 0;						// ステートワーク　処理段階の目安として使う：0 = n-1未処理, 1 = n-2未処理, 2 = printf出力
	IntStack nstk , sstk;			// スタック

	Initialize( &nstk , 100 );
	Initialize( &sstk , 100 );

	while( 1 ) {
		if( n > 0 ) {
			Push( &nstk , n );		// 現在のnを保存
			Push( &sstk , sw );		// 現在の状態swも保存（再帰の深さ・段階）

			// swに応じて次の再帰的処理を"模倣"
			if( sw == 0 )
				n = n - 1;			// まず n - 1 に進む
			else if( sw == 1 ) {
				n = n - 2;			// 次に n - 2 に進む
				sw = 0;				// 再帰的に進むときは状態をリセット
			}
			continue;				//再帰的に処理を進める為 loopの頭に戻る
		}
		// n <= 0 に到達、または再帰の処理段階を復元して進行
		do {
			Pop( &nstk , &n );		// n を引き出す
			Pop( &sstk , &sw );		// sw を引き出す
			sw++;					// 次の処理段階に進む（0→1、1→2）

			if( sw == 2 ) {			// swが2の時nを出力する
				printf( "%d\n" , n );
				if( IsEmpty( &nstk ) )
					return;			// スタックが空＝全処理完了
			}
		} while( sw == 2 );			// 出力後はもう一度処理段階を確認する（次のprintfの可能性がある）
	}

	Terminate( &nstk );				//ヒープに確保したスタックを解放
	Terminate( &sstk );				//ヒープに確保したスタックを解放
	
}

int main( void ) {
	int x;

	printf( "整数を入力せよ：" );
	scanf( "%d" , &x );

	recur3( x );

	while( 1 ) {
	}

	return 0;
}
