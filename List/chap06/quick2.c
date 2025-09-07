// クイックソート（改良版）比較的ムラのない（偏りにくい）枢軸を選ぶための工夫　*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- x[a], x[b], x[c]をソート（中央値の添字を返却）---*/
int sort3elem( int x[] , int a , int b , int c ) {
	// x[a] と x[b] (pL,pC)を比較し、x[a] <= x[b] になるように並べ替える
	if( x[b] < x[a] ) swap( int , x[b] , x[a] );
	// x[b] と x[c] (pC,pR)を比較し、x[b] <= x[c] になるように並べ替える
	if( x[c] < x[b] ) swap( int , x[c] , x[b] );
	// 再度 x[a] と x[b] (pL,pC)を比較し、x[a] <= x[b] になるように調整（必要な場合のみ）
	if( x[b] < x[a] ) swap( int , x[b] , x[a] );
	// ここまでで x[a], x[b], x[c] (pL,pC,pR)の3要素は昇順に並んでいる（x[a] <= x[b] <= x[c]）
	// 中央の値は x[b] (pC)なので、添字 b を返す
	return b;
}

/*--- クイックソート ---*/
void quick( int a[] , int left , int right ) {
	int pl = left;								// 左カーソル
	int pr = right;								// 右カーソル
	int m = sort3elem( a , pl , ( pl + pr ) / 2 , pr );  // 先頭・末尾・中央をソート
	int x = a[m];								// 枢軸(pL,pC,pRを比較したうえで中央の値をもった枢軸)

	swap( int , a[m] , a[right - 1] );			// 中央と末尾から２番目を交換
	pl++;										// 左カーソルを１個右へ
	pr -= 2;									// 右カーソルを２個左へ

	do {
		while( a[pl] < x ) pl++;	// Lの値が枢軸の値より下回るうちは移動を続ける
		while( a[pr] > x ) pr--;	// Rの値が枢軸の値より上回るうちは移動を続ける
		if( pl <= pr ) {			//LとRの添字が交差してなければLRの位置の値を入れ替える
			swap( int , a[pl] , a[pr] );
			pl++;					//入れ替え済みの位置を一個飛び越え、続きをやる
			pr--;					//入れ替え済みの位置を一個飛び越え、続きをやる
		}
	} while( pl <= pr );			//LとRの添字が交差してなければ、続きを行う

	if( left < pr )  quick( a , left , pr );
	if( pl < right ) quick( a , pl , right );
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

	quick( x , 0 , nx - 1 );	// 配列xをクイックソート

	puts( "昇順にソートしました。" );
	for( int i = 0; i < nx; i++ )
		printf( "x[%d] = %d\n" , i , x[i] );

	free( x );					// 配列xを破棄

	while( 1 ) {
	}

	return 0;
}
