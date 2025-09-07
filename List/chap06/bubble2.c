// �P�������\�[�g�i��Q�ŁF�����񐔂ɂ��Ő؂�j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- �P�������\�[�g�i��Q�ŁF�����񐔂ɂ��Ő؂�j---*/
void bubble( int a[] , int n ) {
	for( int i = 0; i < n - 1; i++ ) {
		int exchg = 0;				// �p�X�ɂ����������
		for( int j = n - 1; j > i; j-- )
			if( a[j - 1] > a[j] ) {
				swap( int , a[j - 1] , a[j] );
				exchg++;
			}
		if( exchg == 0 ) break;		// �������s���Ȃ�������I��
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
