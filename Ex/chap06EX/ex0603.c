// ���K6-3�@�z�񂪃\�[�g���݂ł��邩�ǂ����𔻒�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- �z��̓\�[�g���݂� ---*/
int is_sorted( int a[] , int n ) {
	for( int i = n - 1; i > 0; i-- )
		if( a[i - 1] > a[i] )
			return 0;
	return 1;
}

int main( void ) {
	int nx , sorted;

	puts( "�\�[�g���݃`�F�b�N" );
	printf( "�v�f�� : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// �v�f��nx��int�^�z��x�𐶐�

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	sorted = is_sorted( x , nx );			// �z��x�̓\�[�g���݂�

	if( sorted )
		puts( "�z��̓\�[�g���݂ł��B" );
	else
		puts( "�z��̓\�[�g����Ă��܂���B" );

	free( x );								// �z��x��j��

	while( 1 ) {
	}

	return 0;
}
