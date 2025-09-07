// �N�C�b�N�\�[�g�i��ċA�Łj
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- �N�C�b�N�\�[�g�i��ċA�Łj---*/
void quick( int a[] , int left , int right ) {

	IntStack lstack;		// �������ׂ��擪�v�f�̓Y���̃X�^�b�N
	IntStack rstack;		// �������ׂ������v�f�̓Y���̃X�^�b�N

	Initialize( &lstack , right - left + 1 );// �ʏ�ł����8-0+1=9�̃T�C�Y���m�ۂ����
	Initialize( &rstack , right - left + 1 );

	Push( &lstack , left );				// �擪�v�f�̓Y��
	Push( &rstack , right );			// �����v�f�̓Y��

	while( !IsEmpty( &lstack ) ) {
		int pl = ( Pop( &lstack , &left ) , left );		// Pop( &lstack , &left )�����left��pop���Aleft(���J�[�\��)��pl�ɑ��(�R���}���Z�q)
		int pr = ( Pop( &rstack , &right ) , right );	// Pop( &rstack , &right )�����right��pop���Aright(�E�J�[�\��)��pr�ɑ��(�R���}���Z�q)
		int x = a[( left + right ) / 2];				// �����͒����̗v�f

		do {
			while( a[pl] < x ) pl++;	// L�̒l�������̒l��艺��邤���͈ړ��𑱂���
			while( a[pr] > x ) pr--;	// R�̒l�������̒l�����邤���͈ړ��𑱂���
			if( pl <= pr ) {			// L��R�̓Y�����������ĂȂ����LR�̈ʒu�̒l�����ւ���
				swap( int , a[pl] , a[pr] );
				pl++;					// ����ւ��ς݂̈ʒu�����щz���A���������
				pr--;					// ����ւ��ς݂̈ʒu�����щz���A���������
			}
		} while( pl <= pr );			// L��R�̓Y�����������ĂȂ���΁A�������s��

		if( left < pr ) {
			Push( &lstack , left );		// ���O���[�v�͈̔͂�
			Push( &rstack , pr );		// �Y�����v�b�V���@
										// ������ p.239 �� Fig.6-22 �ɂ���B��G�c�Ɍ����ƁA
										// �傫�ȃO���[�v�����z��܂ň�x�\�[�g�I������pop�ő傫�ȕʂ̃O���[�v�ɖ߂�
										// ��z��܂Ń\�[�g���J��Ԃ��`���J��Ԃ�
		}
		if( pl < right ) {
			Push( &lstack , pl );		// �E�O���[�v�͈̔͂�
			Push( &rstack , right );	// �Y�����v�b�V��
		}
	}

	Terminate( &lstack );
	Terminate( &rstack );
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

	free( x );								// �z��x��j��

	while( 1 ) {
	}

	return 0;
}
