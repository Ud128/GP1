// ���K4-6 int�^�f�b�NIntDequeue�̗��p��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntDequeueEx0406.h"

int main( void ) {
	IntDequeue que;

	if( Initialize( &que , 64 ) == -1 ) {
		puts( "�L���[�̐����Ɏ��s���܂����B" );
		return 1;
	}

	while( 1 ) {
		int m , x;
		int idx;

		printf( "���݂̃f�[�^���F%d/%d\n" , Size( &que ) , Capacity( &que ) );
		printf( "(1)�擪�ɃG���L���[ (2)�擪���炩��f�L���[ (3)�擪����s�[�N (4)�\��\n"		//�ύX��
				"(5)�����ɃG���L���[ (6)�������炩��f�L���[ (7)��������s�[�N (8)�T��\n"
				"(9)�N���A          (10)��^���t�̔���       (0)�I��:" );
		scanf( "%d" , &m );

		if( m == 0 ) break;

		switch( m ) {
			case 1: /*--- �擪�ɃG���L���[ ---*/
				printf( "�f�[�^�F" );   scanf( "%d" , &x );
				if( EnqueFront( &que , x ) == -1 )				//�ύX��
					puts( "\a�G���[�F�G���L���[�Ɏ��s���܂����B" );
				break;

			case 2: /*--- �擪����f�L���[ ---*/
				if( DequeFront( &que , &x ) == -1 )				//�ύX��
					puts( "\a�G���[�F�f�L���[�Ɏ��s���܂����B" );
				else
					printf( "�f�L���[�����f�[�^��%d�ł��B\n" , x );
				break;

			case 3: /*--- �擪����s�[�N ---*/
				if( PeekFront( &que , &x ) == -1 )				//�ύX��
					puts( "\a�G���[�F�s�[�N�Ɏ��s���܂����B" );
				else
					printf( "�s�[�N�����f�[�^��%d�ł��B\n" , x );
				break;

			case 4: /*--- �\�� ---*/
				Print( &que );
				break;

			case 5: /*--- �����ɃG���L���[ ---*/
				printf( "�f�[�^�F" );   scanf( "%d" , &x );
				if( EnqueRear( &que , x ) == -1 )				//�ύX��
					puts( "\a�G���[�F�G���L���[�Ɏ��s���܂����B" );
				break;

			case 6: /*--- ��������f�L���[ ---*/
				if( DequeRear( &que , &x ) == -1 )				//�ύX��
					puts( "\a�G���[�F�f�L���[�Ɏ��s���܂����B" );
				else
					printf( "�f�L���[�����f�[�^��%d�ł��B\n" , x );
				break;

			case 7: /*--- ��������s�[�N ---*/
				if( PeekRear( &que , &x ) == -1 )				//�ύX��
					puts( "\a�G���[�F�s�[�N�Ɏ��s���܂����B" );
				else
					printf( "�s�[�N�����f�[�^��%d�ł��B\n" , x );
				break;

			case 8: /*--- �T�� ---*/
				printf( "�T������f�[�^�F" );
				scanf( "%d" , &x );
				if( ( idx = Search( &que , x ) ) == -1 )
					puts( "\a�G���|�F�T���Ɏ��s���܂����B" );
				else {
					printf( "���̃f�[�^�͓Y��%d�̈ʒu�ɂ���܂��B\n" , idx );
					printf( "�L���[�̐擪�v�f����%d���̈ʒu�ł��B\n" , Search2( &que , x ) );
				}
				break;

			case 9: /*--- �N���A ---*/
				Clear( &que );
				break;

			case 10: /*--- ��^���t�̔��� ---*/
				printf( "�L���[�͋�%s�B\n" , IsEmpty( &que ) ? "�ł�" : "�ł͂���܂���" );
				printf( "�L���[�͖��t%s�B\n" , IsFull( &que ) ? "�ł�" : "�ł͂���܂���" );
				break;
		}
	}

	Terminate( &que );

	return 0;
}
