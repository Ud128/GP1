// ���K2-1�@�z��̗v�f�̍ŏ��l�����߂�i�v�f�̒l��ǂݍ��ށj
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- �v�f��n�̔z��a�̗v�f�̍ŏ��l�����߂� ---*/
int minof( const int a[] , int n ) {
	int min = a[0];				// �ŏ��l

	for( int i = 1; i < n; i++ )
		if( a[i] < min ) min = a[i];

	return min;
}

int main( void ) {
	int number;					// �l�����z��height�̗v�f��

	printf( "�l�� : " );
	scanf( "%d" , &number );

	int *height = calloc( number , sizeof( int ) );	// �v�f��number�̔z��𐶐� 

	printf( "%d�l�̐g������͂��Ă��������B\n" , number );
	for( int i = 0; i < number; i++ ) {
		printf( "height[%d] : " , i );
		scanf( "%d" , &height[i] );
	}

	printf( "�ŏ��l��%d�ł��B\n" , minof( height , number ) );

	free( height );								// �z��height��j��

	while( 1 ) {
	}

	return 0;
}
