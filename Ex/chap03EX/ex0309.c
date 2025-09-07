// 演習3-9　bsearch関数を拡張した関数（最も先頭に位置する要素を探索）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- baseが指す要素の大きさがsizeで要素数がnmembの配列からkeyと一致する要素を
	  比較関数comparを用いて２分探索
	  ※ keyと等しい要素が複数存在する場合は最も先頭の要素を探す ---*/
void *bsearchx( const void *key , const void *base , size_t nmemb , size_t size ,
	int ( *compar )( const void * , const void * ) ) {
	char *x = (char *)base;
	size_t pl = 0;							// 探索範囲の先頭の添字
	size_t pr = nmemb - 1;					// 　　〃　　末尾の添字

	if( nmemb > 0 ) {
		while( 1 ) {
			size_t pc = ( pl + pr ) / 2;	// 　　〃　　中央の添字
			int comp = compar( (const void *)&x[pc * size] , key );//指定関数で0か1か-1は出るので...

			if( comp == 0 ) { 				// 探索成功
				
				for( ; pc > pl; pc-- )		// keyと等しい先頭の要素を探す
					if( compar( (const void *)&x[( pc - 1 ) * size] , key ) )
						break;
				return &x[pc * size];		//最終的に見つかった該当アドレスを返す
				/*
				//こちらでも行ける
				while( pc > pl ) {			// keyと等しい先頭の要素を探す
					if( compar( (const void *)&x[( pc - 1 ) * size] , key ) )
						break;
					pc--;
				}
				return &x[pc * size];		//最終的に見つかった該当アドレスを返す
				*/
			}
			else if( pl == pr )				//指定関数の結果に任せてp.102の要領で添字をずらす
				break;
			else if( comp < 0 )
				pl = pc + 1;				// 探索範囲を後半に絞り込む
			else
				pr = pc - 1;				// 探索範囲を前半に絞り込む
		}
	}

	return NULL;							// 探索失敗
}

/*--- 整数を比較する関数 ---*/
int int_cmp( const int *a , const int *b ) {
	if( *a < *b )
		return -1;
	else if( *a > *b )
		return 1;
	else
		return 0;
}

int main( void ) {
	int nx , ky;

	puts( "bsearchx関数による探索" );
	printf( "要素数 : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// 要素数nxのint型配列xを生成

	printf( "昇順に入力してください。\n" );
	printf( "x[0] : " );
	scanf( "%d" , &x[0] );

	for( int i = 1; i < nx; i++ ) {
		do {
			printf( "x[%d] : " , i );
			scanf( "%d" , &x[i] );
		} while( x[i] < x[i - 1] );		// 一つ前の値よりも小さければ再入力
	}

	printf( "探す値 : " );
	scanf( "%d" , &ky );

	int *p = bsearchx(
		&ky ,							// 探索値へのポインタ
		x ,								// 配列
		nx ,								// 要素数
		sizeof( int ) ,					// 要素の大きさ
		( int ( * )( const void * , const void * ) )int_cmp	// 比較関数
	);

	if( p == NULL )
		puts( "探索に失敗しました。" );
	else
		printf( "%dはx[%d]にあります。\n" , ky , (int)( p - x ) );

	free( x );							// 配列xを破棄

	while( 1 ) {
	}

	return 0;
}
