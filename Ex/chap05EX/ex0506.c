// ���K5-6�@�֐�recur3���ċA�I�Ɏ���

// ���F�{�v���O�����̃R���p�C���ɂ�"IntStack.h"��"IntStack.c"���K�v�ł��B
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntStack.h"

/*--- �֐�recur3�i�ċA�������j---*/
void recur3( int n ) {

	/*
	if( n > 0 ) {
		recur3( n - 1 );
		recur3( n - 2 );
		printf( "%d\n" , n );
	} 
	*/
	//4����͂����Ƃ��̏o��:1213124

	int sw = 0;						// �X�e�[�g���[�N�@�����i�K�̖ڈ��Ƃ��Ďg���F0 = n-1������, 1 = n-2������, 2 = printf�o��
	IntStack nstk , sstk;			// �X�^�b�N

	Initialize( &nstk , 100 );
	Initialize( &sstk , 100 );

	while( 1 ) {
		if( n > 0 ) {
			Push( &nstk , n );		// ���݂�n��ۑ�
			Push( &sstk , sw );		// ���݂̏��sw���ۑ��i�ċA�̐[���E�i�K�j

			// sw�ɉ����Ď��̍ċA�I������"�͕�"
			if( sw == 0 )
				n = n - 1;			// �܂� n - 1 �ɐi��
			else if( sw == 1 ) {
				n = n - 2;			// ���� n - 2 �ɐi��
				sw = 0;				// �ċA�I�ɐi�ނƂ��͏�Ԃ����Z�b�g
			}
			continue;				//�ċA�I�ɏ�����i�߂�� loop�̓��ɖ߂�
		}
		// n <= 0 �ɓ��B�A�܂��͍ċA�̏����i�K�𕜌����Đi�s
		do {
			Pop( &nstk , &n );		// n �������o��
			Pop( &sstk , &sw );		// sw �������o��
			sw++;					// ���̏����i�K�ɐi�ށi0��1�A1��2�j

			if( sw == 2 ) {			// sw��2�̎�n���o�͂���
				printf( "%d\n" , n );
				if( IsEmpty( &nstk ) )
					return;			// �X�^�b�N���󁁑S��������
			}
		} while( sw == 2 );			// �o�͌�͂�����x�����i�K���m�F����i����printf�̉\��������j
	}

	Terminate( &nstk );				//�q�[�v�Ɋm�ۂ����X�^�b�N�����
	Terminate( &sstk );				//�q�[�v�Ɋm�ۂ����X�^�b�N�����
	
}

int main( void ) {
	int x;

	printf( "��������͂���F" );
	scanf( "%d" , &x );

	recur3( x );

	while( 1 ) {
	}

	return 0;
}
