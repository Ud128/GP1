// ���K6-14�@�N�C�b�N�\�[�g�i�v�f�������������̃O���[�v��D��I�ɕ����F��ċA�Łj

// �{�v���O�����̃R���p�C���ɂ�"IntStack.h"�����"IntStack.c"���K�v�ł�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- �N�C�b�N�\�[�g�i��ċA�ŁF�v�f�������������̃O���[�v��D��I�ɕ����j---*/
void quick( int a[] , int left , int right ) {
	IntStack lstack;		// �������ׂ��擪�v�f�̓Y���̃X�^�b�N
	IntStack rstack;		// �������ׂ������v�f�̓Y���̃X�^�b�N

	Initialize( &lstack , right - left + 1 );
	Initialize( &rstack , right - left + 1 );

	Push( &lstack , left );
	Push( &rstack , right );

	while( !IsEmpty( &lstack ) ) {
		int pl = ( Pop( &lstack , &left ) , left );		// ���J�[�\��
		int pr = ( Pop( &rstack , &right ) , right );	// �E�J�[�\��
		int x = a[( left + right ) / 2];				// �����͒����̗v�f

		do {
			while( a[pl] < x ) pl++;	// L�̒l�������̒l��艺��邤���͈ړ��𑱂���
			while( a[pr] > x ) pr--;	// R�̒l�������̒l�����邤���͈ړ��𑱂���
			if( pl <= pr ) {			//L��R�̓Y�����������ĂȂ����LR�̈ʒu�̒l�����ւ���
				swap( int , a[pl] , a[pr] );
				pl++;					//����ւ��ς݂̈ʒu�����щz���A���������
				pr--;					//����ւ��ς݂̈ʒu�����щz���A���������
			}
		} while( pl <= pr );			//L��R�̓Y�����������ĂȂ���΁A�������s��


		//left ~ pr �� �����̃O���[�v:pl ~ right �� �E���̃O���[�v
		//�����O���[�v�̕����v�f�������Ȃ����H
		if( pr - left < right - pl ) {
			// ���̕����v�f�������Ȃ��̂�...
			if( pl < right ) {//�\�[�g���I����Ă��Ȃ������m�F���A�E���̏����ŕK�v�ȕ����Ƀv�b�V��
				Push( &lstack , pl );
				Push( &rstack , right );
			}
			if( left < pr ) {//�\�[�g���I����Ă��Ȃ������m�F���A�����̏����ŕK�v�ȕ�����Ƀv�b�V��
				Push( &lstack , left );
				Push( &rstack , pr );
			}
		}
		else {
			// �E�̕����v�f�������Ȃ��̂�...
			if( left < pr ) {//�\�[�g���I����Ă��Ȃ������m�F���A�����̏����ŕK�v�ȕ����Ƀv�b�V��
				Push( &lstack , left );
				Push( &rstack , pr );
			}
			if( pl < right ) {//�\�[�g���I����Ă��Ȃ������m�F���A�E���̏����ŕK�v�ȕ�����Ƀv�b�V��
				Push( &lstack , pl );
				Push( &rstack , right );
			}
		}
		//���̌�̏����Ō�ɓ��ꂽ�������Pop�����̂ŁA�v�f�����Ȃ�������ɏ��������

		/*
		//pl <-> left �@pl <-> left �Ɠ���ւ��邱�ƂŁA�ϐ����̈Ӑ}�͂����Ă����āA�����̏��Ԃ����ւ��邱�Ƃ��ł���
		if( pr - left < right - pl ) {
			swap( int , pl , left );
			swap( int , pr , right );
		}
		if( left < pr ) {
			Push( &lstack , left );	// ���O���[�v�͈̔͂�
			Push( &rstack , pr );		// �Y�����v�b�V��
		}
		if( pl < right ) {
			Push( &lstack , pl );		// �E�O���[�v�͈̔͂�
			Push( &rstack , right );	// �Y�����v�b�V��
		}
		*/
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

	free( x );							// �z��x��j��

	while( 1 ) {
	}

	return 0;
}
