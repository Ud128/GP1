// ���K3-10�@�`�F�C���n�b�V��ChainHash�̗��p��i�L�[�͎����j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "MemberEx0310.h"
#include "ChainHashEx0310.h"

/*--- ���j���[ ---*/
typedef enum {
	TERMINATE , ADD , DELETE , SEARCH , CLEAR , DUMP
} Menu;

/*--- ���j���[�I�� ---*/
Menu SelectMenu( void ) {
	int ch;

	do {
		printf( "(1)�ǉ� (2)�폜 (3)�T�� (4)�S�폜 (5)�_���v (0)�I���F" );
		scanf( "%d" , &ch );
	} while( ch < TERMINATE || ch > DUMP );
	return (Menu)ch;
}

/*--- ���C�� ---*/
int main( void ) {
	Menu menu;				// ���j���[
	ChainHash hash;			// �n�b�V���\

	Initialize( &hash , 13 );	// �n�b�V���\�̏�����

	do {
		int result;
		Member x;
		Node *temp;

		switch( menu = SelectMenu() ) {
			case ADD: /*--- �f�[�^�̒ǉ� ---*/
			x = ScanMember( "�ǉ�" , MEMBER_NO | MEMBER_NAME );
			result = Add( &hash , &x );
			if( result )
				printf( "\a�G���[�F�ǉ��Ɏ��s���܂����i%s�j�B\n" ,
						( result == 1 ) ? "�o�^����" : "�������s��" );
			break;

			case DELETE: /*--- �f�[�^�̍폜 ---*/	//�ς�������
			x = ScanMember( "�폜" , MEMBER_NAME );	//MEMBER_NO --> MEMBER_NAME��
			result = Remove( &hash , &x );
			if( result == 1 )
				printf( "\a�G���[�F���̔ԍ��̃f�[�^�͑��݂��܂���B\n" );
			break;

			case SEARCH: /*--- �f�[�^�̒T�� ---*/	//�ς�������
			x = ScanMember( "�T��" , MEMBER_NAME );	//MEMBER_NO --> MEMBER_NAME��
			temp = Search( &hash , &x );
			if( temp == NULL )
				printf( "\a�T���Ɏ��s���܂����B\n" );
			else {
				printf( "�T���ɐ������܂����F" );
				PrintLnMember( &temp->data );
			}
			break;

			case CLEAR: /*--- �S�f�[�^�̍폜 ---*/
			Clear( &hash );
			break;

			case DUMP: /*--- �n�b�V���\�̃_���v ---*/
			Dump( &hash );
			break;
		}
	} while( menu != TERMINATE );

	Terminate( &hash );							// �n�b�V���\�̌�n��

	return 0;
}
