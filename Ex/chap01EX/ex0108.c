// ���K1-8�@1, 2, �c, n�̑��a�����߂�i�K�E�X�̕��@�j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main( void ) {
	int n;

	puts( "1����n�܂ł̘a�����߂܂��B" );

	printf( "n�̒l�F" );
	scanf( "%d" , &n );

	int sum = ( n + 1 ) * ( n / 2 ) + ( n % 2 == 1 ? ( n + 1 ) / 2 : 0 );

	//int sum = ( n * ( n + 1 ) ) / 2;

	printf( "1����%d�܂ł̘a��%d�ł��B\n" , n , sum );

	while( 1 ) {
	}

	return 0;
}
