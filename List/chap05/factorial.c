// �K��l���ċA�I�ɋ��߂�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*--- �����ln�̊K���ԋp ---*/
int factorial( int n ) {
	if( n > 0 )
		return n * factorial( n - 1 );
	else
		return 1;
}

int main( void ) {
	int x;

	printf( "��������͂���F" );
	scanf( "%d" , &x );

	printf( "%d�̊K���%d�ł��B\n" , x , factorial( x ) );

	while( 1 ) {
	}

	return 0;
}
