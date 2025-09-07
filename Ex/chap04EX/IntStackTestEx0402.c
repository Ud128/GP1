// ���K4-2 �z�񋤗Lint�^�X�^�b�NIntStack2�̗��p��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntStackEx0402.h"

int main( void ) {
	IntStack s;

	if( Initialize( &s , 64 ) == -1 ) {
		puts( "�X�^�b�N�̐����Ɏ��s���܂����B" );
		return 1;
	}

	while( 1 ) {
		int menu , x;
		int idx;

		printf( "���݂̃f�[�^���FA:%d B:%d / %d\n" , Size( &s , StackA ) , Size( &s , StackB ) , Capacity( &s ) );
		printf( " 1)A��Push  2)A����Pop  3)A����Peek  4)A��\��  5)A����T��  6)A���N���A\n"
				" 7)B��Push  8)B����Pop  9)B����Peek 10)B��\�� 11)B����T�� 12)B���N���A\n"
				"13)��^���t 0) �I���F" );
		scanf( "%d" , &menu );

		if( menu == 0 ) break;

		switch( menu ) {
			case 1: /*--- A�Ƀv�b�V�� ---*/
			printf( "�f�[�^�F" );
			scanf( "%d" , &x );
			if( Push( &s , StackA , x ) == -1 )
				puts( "\a�G���|�F�v�b�V���Ɏ��s���܂����B" );
			break;

			case 2: /*--- A����|�b�v ---*/
			if( Pop( &s , StackA , &x ) == -1 )
				puts( "\a�G���|�F�|�b�v�Ɏ��s���܂����B" );
			else
				printf( "�|�b�v�����f�[�^��%d�ł��B\n" , x );
			break;

			case 3: /*--- A����s�[�N ---*/
			if( Peek( &s , StackA , &x ) == -1 )
				puts( "\a�G���|�F�s�[�N�Ɏ��s���܂����B" );
			else
				printf( "�s�[�N�����f�[�^��%d�ł��B\n" , x );
			break;

			case 4: /*--- A��\�� ---*/
			Print( &s , StackA );
			break;

			case 5: /*--- A����T�� ---*/
			printf( "�T������f�[�^�F" );
			scanf( "%d" , &x );
			if( ( idx = Search( &s , StackA , x ) ) == -1 )
				puts( "\a�G���|�F�T���Ɏ��s���܂����B" );
			else
				printf( "���̃f�[�^�͓Y��%d�̈ʒu�ɂ���܂��B\n" , idx );
			break;

			case 6: /*--- A���N���A ---*/
			Clear( &s , StackA );
			break;

			case 7: /*--- B�Ƀv�b�V�� ---*/
			printf( "�f�[�^�F" );
			scanf( "%d" , &x );
			if( Push( &s , StackB , x ) == -1 )
				puts( "\a�G���|�F�v�b�V���Ɏ��s���܂����B" );
			break;

			case 8: /*--- B����|�b�v ---*/
			if( Pop( &s , StackB , &x ) == -1 )
				puts( "\a�G���|�F�|�b�v�Ɏ��s���܂����B" );
			else
				printf( "�|�b�v�����f�[�^��%d�ł��B\n" , x );
			break;

			case 9: /*--- B����s�[�N ---*/
			if( Peek( &s , StackB , &x ) == -1 )
				puts( "\a�G���|�F�s�[�N�Ɏ��s���܂����B" );
			else
				printf( "�s�[�N�����f�[�^��%d�ł��B\n" , x );
			break;

			case 10: /*--- B��\�� ---*/
			Print( &s , StackB );
			break;

			case 11: /*--- B����T�� ---*/
			printf( "�T������f�[�^�F" );
			scanf( "%d" , &x );
			if( ( idx = Search( &s , StackB , x ) ) == -1 )
				puts( "\a�G���|�F�T���Ɏ��s���܂����B" );
			else
				printf( "���̃f�[�^�͓Y��%d�̈ʒu�ɂ���܂��B\n" , idx );
			break;

			case 12: /*--- B���N���A ---*/
			Clear( &s , StackB );
			break;

			case 13: /*--- ��^���t�̔��� ---*/
			printf( "�X�^�b�N�`�͋�%s�B\n" , IsEmpty( &s , StackA ) ? "�ł�" : "�ł͂���܂���" );
			printf( "�X�^�b�N�a�͋�%s�B\n" , IsEmpty( &s , StackB ) ? "�ł�" : "�ł͂���܂���" );
			printf( "�X�^�b�N�͖��t%s�B\n" , IsFull( &s ) ? "�ł�" : "�ł͂���܂���" );
			break;
		}
	}

	Terminate( &s );

	return 0;
}
