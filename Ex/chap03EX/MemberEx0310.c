// ����f�[�^Member�i�\�[�X���j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "MemberEx0310.h"

/*--- ����̔ԍ��̔�r�֐� ---*/
int MemberNoCmp( const Member *x , const Member *y ) {
	return x->no < y->no ? -1 : x->no > y->no ? 1 : 0;
}

/*--- ����̎����̔�r�֐� ---*/
int MemberNameCmp( const Member *x , const Member *y ) {
	return strcmp( x->name , y->name );
}

/*--- ����f�[�^�i�ԍ��Ǝ����j�̕\���i���s�Ȃ��j---*/
void PrintMember( const Member *x ) {
	printf( "%d %s" , x->no , x->name );
}

/*--- ����f�[�^�i�ԍ��Ǝ����j�̕\���i���s����j---*/
void PrintLnMember( const Member *x ) {
	printf( "%d %s\n" , x->no , x->name );
}

/*--- ����f�[�^�i�ԍ��Ǝ����j�̓Ǎ��� ---*/
Member ScanMember( const char *message , int sw ) {
	Member temp;

	printf( "%s����f�[�^����͂��Ă��������B\n" , message );

	if( sw & MEMBER_NO ) { printf( "�ԍ��F" );  scanf( "%d" , &temp.no ); }
	if( sw & MEMBER_NAME ) { printf( "�����F" );  scanf( "%s" , temp.name ); }

	return temp;
}
