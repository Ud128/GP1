/// 演習5-7 ハノイの塔（軸名を文字列で表示）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*--- 円盤[1]～円盤[no]をx軸からy軸へ移動 ---*/
void move( int no , int x , int y ) {
	char *name[] = { "Ａ軸", "Ｂ軸", "Ｃ軸" };

	if( no > 1 )
		move( no - 1 , x , 6 - x - y );		//グループを開始軸から中間軸へ

	printf( "円盤[%d]を%sから%sへ移動\n" , no , name[x - 1] , name[y - 1] );	// 底を目的軸へ

	if( no > 1 )
		move( no - 1 , 6 - x - y , y );		// グルーブを中間軸から目的軸へ
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
