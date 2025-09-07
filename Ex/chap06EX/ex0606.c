// 演習6-6　双方向バブルソート（シェーカーソート）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 双方向バブルソート（シェーカーソート）---*/
void shaker( int a[] , int n ) {
	int left = 0;			// 左側の未ソート範囲の先頭の添字
	int right = n - 1;		// 右側の未ソート範囲の末尾の添字
	int last = right;		// 最後に交換が発生した位置を記録する

	while( left < right ) { //右から全配列チェックして入れ替えが起きた位置、左から全配列チェックして入れ替えが起きた位置が交差していなかったら、
							//互いに前方のソートチェックが済んでしまってるという事なので、それ以上の処理が不要となり、ソートが完了する

		// ↓↓↓ 右から左へ( <-- )の比較・交換（大きい値を後ろへ）
		for( int j = right; j > left; j-- ) {
			if( a[j - 1] > a[j] ) {
				swap( int , a[j - 1] , a[j] );	// 隣接要素を比較して交換
				last = j;						// 最後に交換が発生した位置を記録
			}
		}
		left = last;							// 左側の境界を更新（それ以前の部分はすでに整列済み）

		// ↓↓↓ 左から右へ( --> )の比較・交換（小さい値を前へ）
		for( int j = left; j < right; j++ ) {
			if( a[j] > a[j + 1] ) {
				swap( int , a[j] , a[j + 1] );	// 隣接要素を比較して交換
				last = j;						// 最後に交換が発生した位置を記録
			}
		}
		right = last;							// 右側の境界を更新（それ以降の部分はすでに整列済み）
	}

}

int main( void ) {
	int nx;

	puts( "双方向バブルソート" );
	printf( "要素数 : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// 要素数nxのint型配列xを生成

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	shaker( x , nx );						// 配列xを双方向バブルソート

	puts( "昇順にソートしました。" );
	for( int i = 0; i < nx; i++ )
		printf( "x[%d] = %d\n" , i , x[i] );

	free( x );							// 配列xを破棄

	while( 1 ) {
	}

	return 0;
}
