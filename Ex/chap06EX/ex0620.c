// 演習6-20　ヒープソート（ソート過程の木を表示）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 2のn乗を求める ---*/
static int pow2( int n ) {
	int k = 1;

	while( n-- )
		k *= 2;
	return ( k );
}

/*--- ヒープを表示 ---*/
static void disp_heap( int a[] , int n ) {
	int i , w , level;
	int height = 1;		// 木の高さ

	i = n;
	while( i /= 2 )
		height++;

	i = 0;
	w = 1;
	for( level = 0; level < height; level++ ) {
		int k;
		printf( "%*s" , pow2( height - level ) - 2 , "" );
		for( k = 0; k < w; k++ ) {
			printf( "%02d" , a[i++] );
			if( i >= n ) goto Exit;
			printf( "%*s" , pow2( height - level + 1 ) - 2 , "" );
		}
		putchar( '\n' );

		printf( "%*s" , pow2( height - level ) - 3 , "" );
		for( k = 0; k < w; k++ ) {
			if( 2 * k + i < n ) printf( "／" );
			if( 2 * k + i + 1 < n ) printf( "＼" );
			printf( "%*s" , pow2( height - level + 1 ) - 4 , "" );
		}
		putchar( '\n' );
		w *= 2;
	}
Exit:
	putchar( '\n' );
	putchar( '\n' );
}

/*--- a[left]～a[right]をヒープ化 ---*/
static void downheap( int a[] , int left , int right ) {
	int temp = a[left];				// 根
	int child;
	int parent;

	for( parent = left; parent < ( right + 1 ) / 2; parent = child ) {
		int cl = parent * 2 + 1;	// 左の子
		int cr = cl + 1;			// 右の子
		child = ( cr <= right && a[cr] > a[cl] ) ? cr : cl;	// 大きいほうの子
		if( temp >= a[child] )
			break;
		a[parent] = a[child];
	}
	a[parent] = temp;
}

/*--- ヒープソート（ソート過程の木を表示）---*/
void heapsort( int a[] , int n ) {
	int i;

	puts( "配列をヒープ化します。\n" );
	for( i = ( n - 1 ) / 2; i >= 0; i-- ) {
		disp_heap( a , n );
		downheap( a , i , n - 1 );
	}

	// ★ 追加：ヒープ化完了後の表示
	puts( "ヒープ化が完了した配列 ：\n" );
	disp_heap( a , n );

	puts( "ヒープをもとにソートを行います。\n" );
	for( i = n - 1; i > 0; i-- ) {
		swap( int , a[0] , a[i] );
		disp_heap( a , n );
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
