// ���K2-2�@�z��̗v�f�̍��v�l�����߂�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*--- �v�f��n�̔z��a�̗v�f�̍��v�l�����߂� ---*/
int sumof( const int a[] , int n ) {
	int sum = 0;				// ���v�l

	for( int i = 0; i < n; i++ )
		sum += a[i];

	return sum;
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

	printf( "���v�l��%d�ł��B\n" , sumof( height , number ) );

	free( height );								// �z��height��j��

	while( 1 ) {
	}

	return 0;
}
