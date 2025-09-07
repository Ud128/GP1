// 演習4-6 int型デックIntDequeueの利用例
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntDequeueEx0406.h"

int main( void ) {
	IntDequeue que;

	if( Initialize( &que , 64 ) == -1 ) {
		puts( "キューの生成に失敗しました。" );
		return 1;
	}

	while( 1 ) {
		int m , x;
		int idx;

		printf( "現在のデータ数：%d/%d\n" , Size( &que ) , Capacity( &que ) );
		printf( "(1)先頭にエンキュー (2)先頭からからデキュー (3)先頭からピーク (4)表示\n"		//変更★
				"(5)末尾にエンキュー (6)末尾からからデキュー (7)末尾からピーク (8)探索\n"
				"(9)クリア          (10)空／満杯の判定       (0)終了:" );
		scanf( "%d" , &m );

		if( m == 0 ) break;

		switch( m ) {
			case 1: /*--- 先頭にエンキュー ---*/
				printf( "データ：" );   scanf( "%d" , &x );
				if( EnqueFront( &que , x ) == -1 )				//変更★
					puts( "\aエラー：エンキューに失敗しました。" );
				break;

			case 2: /*--- 先頭からデキュー ---*/
				if( DequeFront( &que , &x ) == -1 )				//変更★
					puts( "\aエラー：デキューに失敗しました。" );
				else
					printf( "デキューしたデータは%dです。\n" , x );
				break;

			case 3: /*--- 先頭からピーク ---*/
				if( PeekFront( &que , &x ) == -1 )				//変更★
					puts( "\aエラー：ピークに失敗しました。" );
				else
					printf( "ピークしたデータは%dです。\n" , x );
				break;

			case 4: /*--- 表示 ---*/
				Print( &que );
				break;

			case 5: /*--- 末尾にエンキュー ---*/
				printf( "データ：" );   scanf( "%d" , &x );
				if( EnqueRear( &que , x ) == -1 )				//変更★
					puts( "\aエラー：エンキューに失敗しました。" );
				break;

			case 6: /*--- 末尾からデキュー ---*/
				if( DequeRear( &que , &x ) == -1 )				//変更★
					puts( "\aエラー：デキューに失敗しました。" );
				else
					printf( "デキューしたデータは%dです。\n" , x );
				break;

			case 7: /*--- 末尾からピーク ---*/
				if( PeekRear( &que , &x ) == -1 )				//変更★
					puts( "\aエラー：ピークに失敗しました。" );
				else
					printf( "ピークしたデータは%dです。\n" , x );
				break;

			case 8: /*--- 探索 ---*/
				printf( "探索するデータ：" );
				scanf( "%d" , &x );
				if( ( idx = Search( &que , x ) ) == -1 )
					puts( "\aエラ－：探索に失敗しました。" );
				else {
					printf( "そのデータは添字%dの位置にあります。\n" , idx );
					printf( "キューの先頭要素から%d個後ろの位置です。\n" , Search2( &que , x ) );
				}
				break;

			case 9: /*--- クリア ---*/
				Clear( &que );
				break;

			case 10: /*--- 空／満杯の判定 ---*/
				printf( "キューは空%s。\n" , IsEmpty( &que ) ? "です" : "ではありません" );
				printf( "キューは満杯%s。\n" , IsFull( &que ) ? "です" : "ではありません" );
				break;
		}
	}

	Terminate( &que );

	return 0;
}
