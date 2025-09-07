// 演習2-9　配列の全要素の並びをシャッフルする
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/*--- type型のxとyの値を交換 ---*/
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 要素数nの配列aの全要素の並びをシャッフル ---*/
void shuffle( int a[] , int n ) {
	srand( time( NULL ) );
	for( int i = n - 1; i > 0; i-- ) {	// 配列aをシャッフル
		int j = rand() % ( i + 1 );
		if( i != j )
			swap( int , a[i] , a[j] );
	}

	/*
	for (int i = 0; i < n - 1; i++) {	// 前から後ろへ ++ のバージョン
		int j = i + rand() % (n - i);	// i ～ n-1 の中から j を選ぶ
		if (i != j)
			swap(int, a[i], a[j]);
	}
	*/
}

int main( void ) {
	int nx;		// 配列xの要素数

	printf( "要素数：" );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// 要素数nxのint型配列xを生成

	printf( "%d個の整数を入力してください。\n" , nx );
	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	shuffle( x , nx );						// 配列xの要素の並びをシャッフル

	printf( "配列の要素の並びをシャッフルしました。\n" );
	for( int i = 0; i < nx; i++ )
		printf( "x[%d] = %d\n" , i , x[i] );

	free( x );							// 配列xを破棄

	while( 1 ) {
	}

	return 0;
}