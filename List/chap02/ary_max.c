// �z��̗v�f�̍ő�l�����߂�i�v�f�̒l��ǂݍ��ށj
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- �v�f��n�̔z��a�̗v�f�̍ő�l�����߂� ---*/
int maxof( const int a[] , int n ) {  //int maxof( const int *a , int n ) {
	int max = a[0];				// �ő�l

	for( int i = 1; i < n; i++ )
		if( a[i] > max ) max = a[i];

	return max;
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

	printf( "�ő�l��%d�ł��B\n" , maxof( height , number ) );

	free( height );								// �z��height��j��

	while( 1 ) {
	}

	return 0;
}
