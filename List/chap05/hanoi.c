// ハノイの塔
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*--- 円盤[1]～円盤[no]をx軸からy軸へ移動 ---*/
void move( int no , int x , int y ) {
	if( no > 1 )
		move( no - 1 , x , 6 - x - y );			// グループを開始軸から中間軸へ

	printf( "円盤[%d]を%d軸から%d軸へ移動\n" , no , x , y );		// 底を目的軸へ

	if( no > 1 )
		move( no - 1 , 6 - x - y , y );			// グループを中間軸から目的軸へ
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

/*
* 円盤の枚数：3

move(3, 1, 3)
└─ move(2, 1, 2)
	└─ move(1, 1, 3)
		└─ ★Print: 円盤[1]を1軸から3軸へ移動
	└─ ★Print: 円盤[2]を1軸から2軸へ移動
	└─ move(1, 3, 2)
		└─ ★Print: 円盤[1]を3軸から2軸へ移動
└─ ★Print: 円盤[3]を1軸から3軸へ移動
└─ move(2, 2, 3)
	└─ move(1, 2, 1)
		└─ ★Print: 円盤[1]を2軸から1軸へ移動
	└─ ★Print: 円盤[2]を2軸から3軸へ移動
	└─ move(1, 1, 3)
		└─ ★Print: 円盤[1]を1軸から3軸へ移動

*/
