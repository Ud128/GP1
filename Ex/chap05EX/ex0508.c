// ���K5-8 �n�m�C�̓��i��ċA�j

// ���F�{�v���O�����̃R���p�C���ɂ�"IntStack.h"��"IntStack.c"���K�v�ł��B
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntStack.h"

/*--- �~��[1]�`�~��[no]��x������y���ֈړ� ---*/
void move( int no , int x , int y ) {

	/*
	if( no > 1 )
		move( no - 1 , x , 6 - x - y );			// �O���[�v���J�n�����璆�Ԏ���

	printf( "�~��[%d]��%d������%d���ֈړ�\n" , no , x , y );		// ���ړI����

	if( no > 1 )
		move( no - 1 , 6 - x - y , y );			// �O���[�v�𒆊Ԏ�����ړI����

	//�~�Ղ̖����F3
	//�~��[1]��1������3���ֈړ�
	//�~��[2]��1������2���ֈړ�
	//�~��[1]��3������2���ֈړ�
	//�~��[3]��1������3���ֈړ�
	//�~��[1]��2������1���ֈړ�
	//�~��[2]��2������3���ֈړ�
	//�~��[1]��1������3���ֈړ�
	*/

	
	int sw = 0;  // ���݂̏����i�K�i0:�����̍ċA������, 1:�E���̍ċA�����ցj
	IntStack xstk , ystk , sstk;		// �X�^�b�N

	// ���ꂼ��̏����L�����邽�߂̃X�^�b�N��������
	Initialize( &xstk , 100 );
	Initialize( &ystk , 100 );
	Initialize( &sstk , 100 );

	while( 1 ) {
		// �����̍ċA�I�ȏ����imove(no - 1, x, 6 - x - y)�j��͕�
		if( sw == 0 && no > 1 ) {
			Push( &xstk , x );		// ���݂�x��ۑ�
			Push( &ystk , y );		// ���݂�y��ۑ�
			Push( &sstk , sw );		// ���݂̏����i�K��ۑ��isw�j
			no = no - 1;			// �ċA�I�� move(no - 1, x, ���Ԏ�)
			y = 6 - x - y;			// ���Ԏ����v�Z�i1 + 2 + 3 = 6 ���g���j
			continue;
		}

		printf( "�~��[%d]��%d������%d���ֈړ�\n" , no , x , y );

		// �E���̍ċA�I�ȏ����imove(no - 1, ���Ԏ�, y)�j��͕�
		if( sw == 1 && no > 1 ) {
			Push( &xstk , x );		// �ċA�ɓ���O��x��ۑ�
			Push( &ystk , y );		// y���ۑ�
			Push( &sstk , sw );		// �����i�K��ۑ�

			no = no - 1;			// move(no - 1, ���Ԏ�, y) �ɓ���
			x = 6 - x - y;			// �V�����J�n���i���Ԏ��j���v�Z
			if( ++sw == 2 ) sw = 0;	// �����i�K���Z�b�g�i���̐[����0����n�߂�j
			continue;
		}

		// �����i�K�̕����i�ċA����߂�j
		do {
			if( IsEmpty( &xstk ) )	// �X�^�b�N����ɂȂ� �S�Ă̏������I������i���S�Ă̍ċA���߂����j
				return;
			Pop( &xstk , &x );		// �l��ۑ����Ă���x���|�b�v
			Pop( &ystk , &y );		// �l��ۑ����Ă���y���|�b�v
			Pop( &sstk , &sw );		// �l��ۑ����Ă���sw���|�b�v

			sw++;					// ���̏����i�K�ցi0 �� 1 �� 2�j
			no++;					// �Ή�����ċA�֐���͕킷�邽�߂�no��߂�
		} while( sw == 2 );			// sw == 2 �̂Ƃ��͎��̃��[�v�ŏ��������A��̃��x���֖߂�
	}

	// �g�p�����X�^�b�N��j��
	Terminate( &xstk );
	Terminate( &ystk );
	Terminate( &sstk );

}

int main( void ) {
	int n;		// �~�Ղ̖���

	printf( "�n�m�C�̓�\n�~�Ղ̖����F" );
	scanf( "%d" , &n );

	move( n , 1 , 3 );

	while( 1 ) {
	}

	return 0;
}
