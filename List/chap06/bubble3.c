// �P�������\�[�g�i��R�ŁF�����͈͂�����j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- �P�������\�[�g�i��R�ŁF�����͈͂�����j---*/
void bubble( int a[] , int n ) {
	int k = 0;								// a[k]���O�̓\�[�g����

	while( k < n - 1 ) {
		int last = n - 1;					// �Ō�Ɍ��������ʒu

		for( int j = n - 1; j > k; j-- )
			if( a[j - 1] > a[j] ) {
				swap( int , a[j - 1] , a[j] );
				last = j;
			}
		k = last;
	}
}

int main( void ) {
	int nx;

	puts( "�P�������\�[�g" );
	printf( "�v�f�� : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// �v�f��nx��int�^�z��x�𐶐�

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	bubble( x , nx );						// �z��x��P�������\�[�g

	puts( "�����Ƀ\�[�g���܂����B" );
	for( int i = 0; i < nx; i++ )
		printf( "x[%d] = %d\n" , i , x[i] );

	free( x );							// �z��x��j��

	while( 1 ) {
	}

	return 0;
}
