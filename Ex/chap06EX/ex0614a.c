// 演習6-14　クイックソート（要素数が小さい方のグループを優先的に分割：再帰版）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- クイックソート（要素数が小さい方のグループを優先的に分割）---*/
void quick( int a[] , int left , int right ) {
	int pl = left;				// 左カーソル
	int pr = right;				// 右カーソル
	int x = a[( pl + pr ) / 2];	// 枢軸は中央の要素

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
		// 左側が少ないので、先に左を処理
		if( left < pr ) quick( a , left , pr );		//if( left < pr ) でソートが終わっていないことを確認、実行
		if( pl < right ) quick( a , pl , right );	//if( pl < right )でソートが終わっていないことを確認、実行
	}
	else {
		// 右側が少ないので、先に右を処理
		if( pl < right ) quick( a , pl , right );	//if( pl < right )でソートが終わっていないことを確認、実行
		if( left < pr ) quick( a , left , pr );		//if( left < pr ) でソートが終わっていないことを確認、実行
	}

	/*
	//上のコードで説明すると　pl <-> left 　pl <-> left 関数の上下の引数を入れ替えてる、引数を縦に入れ替えて処理の順番を入れ替えてるような処理
	if( pr - left < right - pl ) {
		swap( int , pl , left );
		swap( int , pl , left  );
	}
	if( left < pr )  quick( a , left , pr );//実際のprカーソルが0に届くまで再帰的に繰り返す
	if( pl < right ) quick( a , pl , right );//実際のplカーソルがn-1に届くまで再帰的に繰り返す
	*/

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
