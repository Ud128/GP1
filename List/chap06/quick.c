// �N�C�b�N�\�[�g
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- �N�C�b�N�\�[�g ---*/
void quick( int a[] , int left , int right ) {
	int pl = left;				// ���J�[�\��
	int pr = right;				// �E�J�[�\��
	int x = a[( pl + pr ) / 2];	// �����͒����̗v�f

	do {
		while( a[pl] < x ) pl++;	// L�̒l�������̒l��艺��邤���͈ړ��𑱂���
		while( a[pr] > x ) pr--;	// R�̒l�������̒l�����邤���͈ړ��𑱂���
		if( pl <= pr ) {			//L��R�̓Y�����������ĂȂ����LR�̈ʒu�̒l�����ւ���
			swap( int , a[pl] , a[pr] );
			pl++;					//����ւ��ς݂̈ʒu�����щz���A���������
			pr--;					//����ւ��ς݂̈ʒu�����щz���A���������
		}
	} while( pl <= pr );			//L��R�̓Y�����������ĂȂ���΁A�������s��

	if( left < pr )  quick( a , left , pr );//���ۂ�pr�J�[�\����0�ɓ͂��܂ōċA�I�ɌJ��Ԃ�
	if( pl < right ) quick( a , pl , right );//���ۂ�pl�J�[�\����n-1�ɓ͂��܂ōċA�I�ɌJ��Ԃ�
}

int main( void ) {
	int nx;

	puts( "�N�C�b�N�\�[�g" );
	printf( "�v�f�� : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// �v�f��nx��int�^�z��x�𐶐�

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	quick( x , 0 , nx - 1 );				// �z��x���N�C�b�N�\�[�g

	puts( "�����Ƀ\�[�g���܂����B" );
	for( int i = 0; i < nx; i++ )
		printf( "x[%d] = %d\n" , i , x[i] );

	free( x );							// �z��x��j��

	while( 1 ) {
	}

	return 0;
}
