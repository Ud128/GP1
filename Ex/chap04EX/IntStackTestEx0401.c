// 演習4-1 int型スタックIntStackの利用例
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntStackEx0401.h"

int main( void ) {
	IntStack s;

	if( Initialize( &s , 64 ) == -1 ) {
		puts( "スタックの生成に失敗しました。" );
		return 1;
	}

	while( 1 ) {
		int menu , x;
		int idx;

		printf( "現在のデータ数：%d / %d\n" , Size( &s ) , Capacity( &s ) );
		printf( "1)プッシュ 2)ポップ 3)ピーク 4)表示 5)探索 6)クリア 7)空／満杯 0) 終了：" );//設定の種類をすべて表示★
		scanf( "%d" , &menu );

		if( menu == 0 ) break;

		switch( menu ) {
			case 1: /*--- プッシュ ---*/
			printf( "データ：" );
			scanf( "%d" , &x );
			if( Push( &s , x ) == -1 )
				puts( "\aエラ－：プッシュに失敗しました。" );
			break;

			case 2: /*--- ポップ ---*/
			if( Pop( &s , &x ) == -1 )
				puts( "\aエラ－：ポップに失敗しました。" );
			else
				printf( "ポップしたデータは%dです。\n" , x );
			break;

			case 3: /*--- ピーク ---*/
			if( Peek( &s , &x ) == -1 )
				puts( "\aエラ－：ピークに失敗しました。" );
			else
				printf( "ピークしたデータは%dです。\n" , x );
			break;

			case 4: /*--- 表示 ---*/
			Print( &s );
			break;

			case 5: /*--- 探索 ---*/				//追加で機能を使用可能にする★
			printf( "探索するデータ：" );
			scanf( "%d" , &x );
			if( ( idx = Search( &s , x ) ) == -1 )
				puts( "\aエラ－：探索に失敗しました。" );
			else
				printf( "そのデータは添字%dの位置にあります。\n" , idx );
			break;

			case 6: /*--- クリア ---*/				//追加で機能を使用可能にする★
			Clear( &s );
			break;

			case 7: /*--- 空／満杯の判定 ---*/		//追加で機能を使用可能にする★
			printf( "スタックは空%s。\n" , IsEmpty( &s ) ? "です" : "ではありません" );
			printf( "スタックは満杯%s。\n" , IsFull( &s ) ? "です" : "ではありません" );
			break;
		}
	}

	Terminate( &s );

	return 0;
}
