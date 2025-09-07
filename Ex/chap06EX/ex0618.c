// 演習6-18　汎用クイックソート（qsort関数に準じた仕様）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- x, yの指すnバイトの領域を交換 ---*/
static void memswap( void *x , void *y , size_t n ) {
	unsigned char *a = (unsigned char *)x;
	unsigned char *b = (unsigned char *)y;

	for( ; n--/*0になるまで繰り返す*/; a++ , b++ ) {
		unsigned char c = *a;
		*a = *b;
		*b = c;
	}
}

/*--- 汎用クイックソート（qsort関数に準じた仕様）---*/
void q_sort( void *base , size_t nmemb , size_t size ,
			 int ( *compar )( const void * , const void * ) ) {
	if( nmemb > 0 ) {
		size_t pl = 0;					// 左カーソル
		size_t pr = nmemb - 1;			// 右カーソル
		size_t pv = nmemb;				// 枢軸
		size_t pt = ( pl + pr ) / 2;	// 枢軸の更新値
		char *v = (char *)base;			// 先頭要素へのポインタ

		do {
			char *x = &v[( pv = pt ) * size];		// pv = pt の代入を果たし pt × size で枢軸へのポインタを求める(上の時にpv = ptしててもいい気がする)
			while( compar( (const void *)&v[pl * size] , x ) < 0 ) pl++;// comparはここで決めた引数内の名前で int_cmpを上書きして処理される。
																		//int_cmp で比較され -1か1が変えさえるので、それをもとに <0 で比較し
																		// 左カーソルが枢軸より小さい間は進める
			
			while( compar( (const void *)&v[pr * size] , x ) > 0 ) pr--;// 詳細は上と同じで　右カーソルが枢軸より大きい間は戻す
			if( pl <= pr ) {
				pt = ( pl == pv ) ? pr : ( pr == pv ) ? pl : pv;
				memswap( &v[pl * size] , &v[pr * size] , size );//いつもの swap( int , a[pl] , a[pr] ); の関数版 で void 版の swap
				pl++;
				if( pr == 0 )	// 符号無し整数0からのデクリメントを避ける(0を超えて小さくなることはないのでgotoで強制避難)
					goto QuickRight;
				pr--;
			}
		} while( pl <= pr );

		if( 0 < pr )		q_sort( &v[0] , pr + 1 , size , compar );
	QuickRight:
		if( pl < nmemb - 1 ) q_sort( &v[pl * size] , nmemb - pl , size , compar );
	}
}

/*--- int型の比較関数（昇順ソート用） ---*/
int int_cmp( const int *a , const int *b ) {
	if( *a < *b )
		return -1;
	else if( *a > *b )
		return 1;
	else
		return 0;
}

int main( void ) {
	int nx;

	printf( "q_sortによるソート\n" );
	printf( "要素数 : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// 要素数nxのint型配列xを生成

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	q_sort( x ,											// 配列
			nx ,										// 要素数
			sizeof( int ) ,								// 要素の大きさ
			( int ( * )( const void * , const void * ) )int_cmp	// 比較関数
	);

	puts( "昇順にソートしました。" );
	for( int i = 0; i < nx; i++ )
		printf( "x[%d] = %d\n" , i , x[i] );

	free( x );							// 配列xを破棄

	while( 1 ) {
	}

	return 0;
}
