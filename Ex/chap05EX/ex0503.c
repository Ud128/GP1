// 演習5-3　配列の全要素の最大公約数値を求める
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- 整数値x, yの最大公約数を返却する ---*/
int gcd( int x , int y ) {
	if( y == 0 )
		return ( x );
	else
		return ( gcd( y , x % y ) );
}

/*--- 要素数nの配列aの全要素の最大公約数を求める ---*/
int gcd_array( const int a[] , int n ) {
	
	if( n == 1 )
		return ( a[0] );
	else if( n == 2 )
		return ( gcd( a[0] , a[1] ) );
	else
		return ( gcd( a[0] , gcd_array( &a[1] , n - 1 ) ) );
		// n が 3 の場合　この部分は gcd_array( &a[1] , 2 ) が渡ってきて　if( n == 2 )の条件で gcd( a[0] , a[1] ) が使われる
		// その時内部で gcd( a[1] , a[2] ) として扱われている。 
		// 理由は &a[1] が先頭の配列として扱われるため、gcd( a[0] , a[1] )　が実際は gcd( a[1] , a[2] ) の場所を指してしまうため。
	
	/*
	int result = a[0];
    for (int i = 1; i < n; i++) {
        result = gcd(result, a[i]);
    }
    return result;
	*/

}

int main( void ) {
	int nx;

	printf( "要素数 : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// 要素数nxのint型配列xを生成

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	printf( "最大公約数は%dです。\n" , gcd_array( x , nx ) );

	free( x );								// 配列を破棄

	while( 1 ) {
	}

	return 0;
}
