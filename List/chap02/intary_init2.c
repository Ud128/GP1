// int�^�̔z��̏������ƕ\���i�v�f����ύX�j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main( void ) {

	int a[] = { 1, 2, 3, 4, 5, 6 };
	int na = sizeof( a ) / sizeof( a[0] );	// �v�f��

	printf( "�z��a�̗v�f����%d�ł��B\n" , na );

	for( int i = 0; i < na; i++ )
		printf( "a[%d] = %d\n" , i , a[i] );

	while( 1 ) {

	}

	return 0;
}
