// �P���I���\�[�g
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- �P���I���\�[�g ---*/
void selection( int a[] , int n ) {
	for( int i = 0; i < n - 1; i++ ) {
		int min = i;						//����ŏ��S�`�F�b�N����
		for( int j = i + 1; j < n; j++ )	//����`�F�b�N���邪�A��ɍs���قǐ擪�����ɓ���
			if( a[j] < a[min] )
				min = j;
		swap( int , a[i] , a[min] );
	}
}

int main( void ) {
	int nx;

	puts( "�P���I���\�[�g" );
	printf( "�v�f�� : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// �v�f��nx��int�^�z��x�𐶐�

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	selection( x , nx );					// �z��x��P���I���\�[�g

	puts( "�����Ƀ\�[�g���܂����B" );
	for( int i = 0; i < nx; i++ )
		printf( "x[%d] = %d\n" , i , x[i] );

	free( x );								// �z��x��j��

	while( 1 ) {
	}

	return 0;
}
