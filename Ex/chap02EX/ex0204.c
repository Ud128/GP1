// ���K2-4�@�z��̗v�f�̍ő�l�����߂�i�l���Ɛg���𗐐��Ő����j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*--- �v�f��n�̔z��a�̗v�f�̍ő�l�����߂� ---*/
int maxof( const int a[] , int n ) {
	int max = a[0];				// �ő�l

	for( int i = 1; i < n; i++ )
		if( a[i] > max ) max = a[i];

	return max;
}

int main( void ) {
	srand( time( NULL ) );							// �������痐���̎��������

	int number = 5 + rand() % 16;				// �l����5�`20�̗����Ō���

	int *height = calloc( number , sizeof( int ) );	// �v�f��number�̔z��𐶐�


	for( int i = 0; i < number; i++ ) {
		height[i] = 100 + rand() % 90;			// 100�`189�̗����𐶐��E���
		printf( "height[%d] = %d\n" , i , height[i] );
	}

	printf( "�ő�l��%d�ł��B\n" , maxof( height , number ) );

	free( height );								// �z��height��j��

	while( 1 ) {
	}

	return 0;
}
