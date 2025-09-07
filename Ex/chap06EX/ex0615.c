// 演習6-15　クイックソート（改良版：要素数9以下は単純挿入ソート）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- x[a], x[b], x[c]をソート（中央値のインデックスを返却）---*/
int sort3elem( int x[] , int a , int b , int c ) {
	if( x[b] < x[a] ) swap( int , x[b] , x[a] );
	if( x[c] < x[b] ) swap( int , x[c] , x[b] );
	if( x[b] < x[a] ) swap( int , x[b] , x[a] );
	return b;
}

/*--- 単純挿入ソート ---*/
void insertion( int a[] , int n ) {
	for( int i = 1; i < n; i++ ) {
		int tmp = a[i];
		int j;
		for( j = i; j > 0 && a[j - 1] > tmp; j-- )
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}

/*--- クイックソート ---*/
void quick( int a[] , int left , int right ) {
	if( right - left < 9 )//グループの要素が9以下
		insertion( &a[left] , right - left + 1 );		//単純挿入ソート
	else {
		int pl = left;									// 左カーソル
		int pr = right;									// 右カーソル
		int m = sort3elem( a , pl , ( pl + pr ) / 2 , pr );	// 先頭・末尾・中央をソート
		int x = a[m];									// 枢軸

		swap( int , a[m] , a[right - 1] );				// 中央と末尾から２番目を交換
		pl++;											// 左カーソルを１個右へ
		pr -= 2;										// 右カーソルを２個左へ

		do {
			while( a[pl] < x ) pl++;
			while( a[pr] > x ) pr--;
			if( pl <= pr ) {
				swap( int , a[pl] , a[pr] );
				pl++;
				pr--;
			}
		} while( pl <= pr );

		if( pr - left < right - pl ) {
			swap( int , pl , left );
			swap( int , pr , right );
		}
		if( left < pr )  quick( a , left , pr );
		if( pl < right ) quick( a , pl , right );
	}
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
