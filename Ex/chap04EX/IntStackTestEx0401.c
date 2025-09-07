// ���K4-1 int�^�X�^�b�NIntStack�̗��p��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntStackEx0401.h"

int main( void ) {
	IntStack s;

	if( Initialize( &s , 64 ) == -1 ) {
		puts( "�X�^�b�N�̐����Ɏ��s���܂����B" );
		return 1;
	}

	while( 1 ) {
		int menu , x;
		int idx;

		printf( "���݂̃f�[�^���F%d / %d\n" , Size( &s ) , Capacity( &s ) );
		printf( "1)�v�b�V�� 2)�|�b�v 3)�s�[�N 4)�\�� 5)�T�� 6)�N���A 7)��^���t 0) �I���F" );//�ݒ�̎�ނ����ׂĕ\����
		scanf( "%d" , &menu );

		if( menu == 0 ) break;

		switch( menu ) {
			case 1: /*--- �v�b�V�� ---*/
			printf( "�f�[�^�F" );
			scanf( "%d" , &x );
			if( Push( &s , x ) == -1 )
				puts( "\a�G���|�F�v�b�V���Ɏ��s���܂����B" );
			break;

			case 2: /*--- �|�b�v ---*/
			if( Pop( &s , &x ) == -1 )
				puts( "\a�G���|�F�|�b�v�Ɏ��s���܂����B" );
			else
				printf( "�|�b�v�����f�[�^��%d�ł��B\n" , x );
			break;

			case 3: /*--- �s�[�N ---*/
			if( Peek( &s , &x ) == -1 )
				puts( "\a�G���|�F�s�[�N�Ɏ��s���܂����B" );
			else
				printf( "�s�[�N�����f�[�^��%d�ł��B\n" , x );
			break;

			case 4: /*--- �\�� ---*/
			Print( &s );
			break;

			case 5: /*--- �T�� ---*/				//�ǉ��ŋ@�\���g�p�\�ɂ��遚
			printf( "�T������f�[�^�F" );
			scanf( "%d" , &x );
			if( ( idx = Search( &s , x ) ) == -1 )
				puts( "\a�G���|�F�T���Ɏ��s���܂����B" );
			else
				printf( "���̃f�[�^�͓Y��%d�̈ʒu�ɂ���܂��B\n" , idx );
			break;

			case 6: /*--- �N���A ---*/				//�ǉ��ŋ@�\���g�p�\�ɂ��遚
			Clear( &s );
			break;

			case 7: /*--- ��^���t�̔��� ---*/		//�ǉ��ŋ@�\���g�p�\�ɂ��遚
			printf( "�X�^�b�N�͋�%s�B\n" , IsEmpty( &s ) ? "�ł�" : "�ł͂���܂���" );
			printf( "�X�^�b�N�͖��t%s�B\n" , IsFull( &s ) ? "�ł�" : "�ł͂���܂���" );
			break;
		}
	}

	Terminate( &s );

	return 0;
}
