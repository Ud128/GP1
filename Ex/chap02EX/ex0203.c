// ���K2-3�@�z��̗v�f�̕��ϒl�����߂�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- �v�f��n�̔z��a�̗v�f�̕��ϒl�����߂� ---*/
double aveof( const int a[] , int n ) {
	double sum = 0;				// ���v�l

	for( int i = 0; i < n; i++ )
		sum += a[i];

	return sum / n;
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

	printf( "���ϒl��%f�ł��B\n" , aveof( height , number ) );

	free( height );								// �z��height��j��

	while( 1 ) {
	}

	return 0;
}
