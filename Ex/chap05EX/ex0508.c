// 演習5-8 ハノイの塔（非再帰）

// 注：本プログラムのコンパイルには"IntStack.h"と"IntStack.c"が必要です。
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntStack.h"

/*--- 円盤[1]～円盤[no]をx軸からy軸へ移動 ---*/
void move( int no , int x , int y ) {

	/*
	if( no > 1 )
		move( no - 1 , x , 6 - x - y );			// グループを開始軸から中間軸へ

	printf( "円盤[%d]を%d軸から%d軸へ移動\n" , no , x , y );		// 底を目的軸へ

	if( no > 1 )
		move( no - 1 , 6 - x - y , y );			// グループを中間軸から目的軸へ

	//円盤の枚数：3
	//円盤[1]を1軸から3軸へ移動
	//円盤[2]を1軸から2軸へ移動
	//円盤[1]を3軸から2軸へ移動
	//円盤[3]を1軸から3軸へ移動
	//円盤[1]を2軸から1軸へ移動
	//円盤[2]を2軸から3軸へ移動
	//円盤[1]を1軸から3軸へ移動
	*/

	
	int sw = 0;  // 現在の処理段階（0:左側の再帰処理へ, 1:右側の再帰処理へ）
	IntStack xstk , ystk , sstk;		// スタック

	// それぞれの情報を記憶するためのスタックを初期化
	Initialize( &xstk , 100 );
	Initialize( &ystk , 100 );
	Initialize( &sstk , 100 );

	while( 1 ) {
		// 左側の再帰的な処理（move(no - 1, x, 6 - x - y)）を模倣
		if( sw == 0 && no > 1 ) {
			Push( &xstk , x );		// 現在のxを保存
			Push( &ystk , y );		// 現在のyを保存
			Push( &sstk , sw );		// 現在の処理段階を保存（sw）
			no = no - 1;			// 再帰的に move(no - 1, x, 中間軸)
			y = 6 - x - y;			// 中間軸を計算（1 + 2 + 3 = 6 を使う）
			continue;
		}

		printf( "円盤[%d]を%d軸から%d軸へ移動\n" , no , x , y );

		// 右側の再帰的な処理（move(no - 1, 中間軸, y)）を模倣
		if( sw == 1 && no > 1 ) {
			Push( &xstk , x );		// 再帰に入る前のxを保存
			Push( &ystk , y );		// yも保存
			Push( &sstk , sw );		// 処理段階を保存

			no = no - 1;			// move(no - 1, 中間軸, y) に入る
			x = 6 - x - y;			// 新しい開始軸（中間軸）を計算
			if( ++sw == 2 ) sw = 0;	// 処理段階リセット（次の深さで0から始める）
			continue;
		}

		// 処理段階の復元（再帰から戻る）
		do {
			if( IsEmpty( &xstk ) )	// スタックが空になり 全ての処理が終わった（＝全ての再帰が戻った）
				return;
			Pop( &xstk , &x );		// 値を保存していたxをポップ
			Pop( &ystk , &y );		// 値を保存していたyをポップ
			Pop( &sstk , &sw );		// 値を保存していたswをポップ

			sw++;					// 次の処理段階へ（0 → 1 → 2）
			no++;					// 対応する再帰関数を模倣するためにnoを戻す
		} while( sw == 2 );			// sw == 2 のときは次のループで処理せず、上のレベルへ戻る
	}

	// 使用したスタックを破棄
	Terminate( &xstk );
	Terminate( &ystk );
	Terminate( &sstk );

}

int main( void ) {
	int n;		// 円盤の枚数

	printf( "ハノイの塔\n円盤の枚数：" );
	scanf( "%d" , &n );

	move( n , 1 , 3 );

	while( 1 ) {
	}

	return 0;
}
