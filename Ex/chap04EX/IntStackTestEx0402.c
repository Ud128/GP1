// 演習4-2 配列共有int型スタックIntStack2の利用例
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntStackEx0402.h"

int main( void ) {
	IntStack s;

	if( Initialize( &s , 64 ) == -1 ) {
		puts( "スタックの生成に失敗しました。" );
		return 1;
	}

	while( 1 ) {
		int menu , x;
		int idx;

		printf( "現在のデータ数：A:%d B:%d / %d\n" , Size( &s , StackA ) , Size( &s , StackB ) , Capacity( &s ) );
		printf( " 1)AにPush  2)AからPop  3)AからPeek  4)Aを表示  5)Aから探索  6)Aをクリア\n"
				" 7)BにPush  8)BからPop  9)BからPeek 10)Bを表示 11)Bから探索 12)Bをクリア\n"
				"13)空／満杯 0) 終了：" );
		scanf( "%d" , &menu );

		if( menu == 0 ) break;

		switch( menu ) {
			case 1: /*--- Aにプッシュ ---*/
			printf( "データ：" );
			scanf( "%d" , &x );
			if( Push( &s , StackA , x ) == -1 )
				puts( "\aエラ－：プッシュに失敗しました。" );
			break;

			case 2: /*--- Aからポップ ---*/
			if( Pop( &s , StackA , &x ) == -1 )
				puts( "\aエラ－：ポップに失敗しました。" );
			else
				printf( "ポップしたデータは%dです。\n" , x );
			break;

			case 3: /*--- Aからピーク ---*/
			if( Peek( &s , StackA , &x ) == -1 )
				puts( "\aエラ－：ピークに失敗しました。" );
			else
				printf( "ピークしたデータは%dです。\n" , x );
			break;

			case 4: /*--- Aを表示 ---*/
			Print( &s , StackA );
			break;

			case 5: /*--- Aから探索 ---*/
			printf( "探索するデータ：" );
			scanf( "%d" , &x );
			if( ( idx = Search( &s , StackA , x ) ) == -1 )
				puts( "\aエラ－：探索に失敗しました。" );
			else
				printf( "そのデータは添字%dの位置にあります。\n" , idx );
			break;

			case 6: /*--- Aをクリア ---*/
			Clear( &s , StackA );
			break;

			case 7: /*--- Bにプッシュ ---*/
			printf( "データ：" );
			scanf( "%d" , &x );
			if( Push( &s , StackB , x ) == -1 )
				puts( "\aエラ－：プッシュに失敗しました。" );
			break;

			case 8: /*--- Bからポップ ---*/
			if( Pop( &s , StackB , &x ) == -1 )
				puts( "\aエラ－：ポップに失敗しました。" );
			else
				printf( "ポップしたデータは%dです。\n" , x );
			break;

			case 9: /*--- Bからピーク ---*/
			if( Peek( &s , StackB , &x ) == -1 )
				puts( "\aエラ－：ピークに失敗しました。" );
			else
				printf( "ピークしたデータは%dです。\n" , x );
			break;

			case 10: /*--- Bを表示 ---*/
			Print( &s , StackB );
			break;

			case 11: /*--- Bから探索 ---*/
			printf( "探索するデータ：" );
			scanf( "%d" , &x );
			if( ( idx = Search( &s , StackB , x ) ) == -1 )
				puts( "\aエラ－：探索に失敗しました。" );
			else
				printf( "そのデータは添字%dの位置にあります。\n" , idx );
			break;

			case 12: /*--- Bをクリア ---*/
			Clear( &s , StackB );
			break;

			case 13: /*--- 空／満杯の判定 ---*/
			printf( "スタックＡは空%s。\n" , IsEmpty( &s , StackA ) ? "です" : "ではありません" );
			printf( "スタックＢは空%s。\n" , IsEmpty( &s , StackB ) ? "です" : "ではありません" );
			printf( "スタックは満杯%s。\n" , IsFull( &s ) ? "です" : "ではありません" );
			break;
		}
	}

	Terminate( &s );

	return 0;
}
