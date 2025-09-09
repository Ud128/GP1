// 演習1-5　三つの整数値の中央値を求める（すべての大小関係に対して確認）

#include <stdio.h>

/*
　最初のif文の判定
	if ((b >= a && c<= a) || (b <= a && c >= a)
に着目します。ここでb >= aおよびb <= aの判定を裏返した判定（実質的に同一の判定）が、続くelse以降で
	else if ((a > b && c < b) || (a < b && c > b)
と行われます。つまり、最初のifが成立しなかった場合、2番目のifでも（実質的に）同じ判定を行っているため、効率が悪くなるのです。
*/

/*--- a, b, cの中央値を求める ---*/
int med3( int a , int b , int c ) {
	if( ( b >= a && c <= a ) || ( b <= a && c >= a ) )
		return a;
	else if( ( a > b && c < b ) || ( a < b && c > b ) )
		return b;
	return c;
}

int main( void ) {
	printf( "med3(%d,%d,%d) = %d\n" , 3 , 2 , 1 , med3( 3 , 2 , 1 ) );	/* [A] a＞b＞c */
	printf( "med3(%d,%d,%d) = %d\n" , 3 , 2 , 2 , med3( 3 , 2 , 2 ) );	/* [B] a＞b＝c */
	printf( "med3(%d,%d,%d) = %d\n" , 3 , 1 , 2 , med3( 3 , 1 , 2 ) );	/* [C] a＞c＞b */
	printf( "med3(%d,%d,%d) = %d\n" , 3 , 2 , 3 , med3( 3 , 2 , 3 ) );	/* [D] a＝c＞b */
	printf( "med3(%d,%d,%d) = %d\n" , 2 , 1 , 3 , med3( 2 , 1 , 3 ) );	/* [E] c＞a＞b */
	printf( "med3(%d,%d,%d) = %d\n" , 3 , 3 , 2 , med3( 3 , 3 , 2 ) );	/* [F] a＝b＞c */
	printf( "med3(%d,%d,%d) = %d\n" , 3 , 3 , 3 , med3( 3 , 3 , 3 ) );	/* [G] a＝b＝c */
	printf( "med3(%d,%d,%d) = %d\n" , 2 , 2 , 3 , med3( 2 , 2 , 3 ) );	/* [H] c＞a＝b */
	printf( "med3(%d,%d,%d) = %d\n" , 2 , 3 , 1 , med3( 2 , 3 , 1 ) );	/* [I] b＞a＞c */
	printf( "med3(%d,%d,%d) = %d\n" , 2 , 3 , 2 , med3( 2 , 3 , 2 ) );	/* [J] b＞a＝c */
	printf( "med3(%d,%d,%d) = %d\n" , 1 , 3 , 2 , med3( 1 , 3 , 2 ) );	/* [K] b＞c＞a */
	printf( "med3(%d,%d,%d) = %d\n" , 2 , 3 , 3 , med3( 2 , 3 , 3 ) );	/* [L] b＝c＞a */
	printf( "med3(%d,%d,%d) = %d\n" , 1 , 2 , 3 , med3( 1 , 2 , 3 ) );	/* [M] c＞b＞a */

	while( 1 ) {
	}

	return 0;
}
