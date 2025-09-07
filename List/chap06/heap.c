// ヒープソート
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- a[left]～a[right]をヒープ化 ---*/
static void downheap( int a[] , int left , int right ) {
	int temp = a[left];				// 根
	int child;
	int parent;

	// このループは、親から子へと下っていきます（downheap）
	for( parent = left; parent < ( right + 1 ) / 2; parent = child ) {
		// parent の左右の個の位置が この計算で割り出せる
		int cl = parent * 2 + 1;	// 左の子
		int cr = cl + 1;			// 右の子

		//printf( "p %d : l %d : r %d\n" , parent , cl , cr );// ここである程度配列をどのように木構造で追っているか見れます

		child = ( cr <= right && a[cr] > a[cl] ) ? cr : cl;	// cr <= right で配列内に収め、大きいほうの子を選びます（最大ヒープにするため）
		if( temp >= a[child] )	// 子の方が小さいなら、ループを終了
			break;
		a[parent] = a[child];	// 子の方が大きいなら、親に子の値をコピー
	}
	a[parent] = temp;// 最後に親の位置に元の値を格納を想定したもの（交換完了）
}

/*--- ヒープソート ---*/
void heapsort( int a[] , int n ) {

	// 最初に木構造をヒープ化させておく
	/*
	 完全二分木では、 ( n - 1 ) / 2 で親だけを指定、つぎに子のLRの添字を割り出している ( p.259で言うところの③のノードにあたる)
			[0]
		   /   |
		 [1]   [2]
		/ |    / |
	  [3][4] [5][6]
	*/
	for( int i = ( n - 1 ) / 2; i >= 0; i-- )
		downheap( a , i , n - 1 );

	// ヒープ化が済んでいるので、0番をn-1番に入れ替えながら、ヒープソートを行っていく
	for( int i = n - 1; i > 0; i-- ) {	// i > 0 は入れ替え済みの後ろを除外しながら処理していく書き方
		swap( int , a[0] , a[i] );
		downheap( a , 0 , i - 1 );
	}
}

int main( void ) {
	int nx;

	puts( "ヒープソート" );
	printf( "要素数 : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// 要素数nxのint型配列xを生成

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	heapsort( x , nx );	// 配列xをヒープソート

	puts( "昇順にソートしました。" );
	for( int i = 0; i < nx; i++ )
		printf( "x[%d] = %d\n" , i , x[i] );

	free( x );			// 配列xを破棄

	while( 1 ) {

	}

	return 0;
}
