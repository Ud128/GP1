// ���K4-2 �z�񋤗Lint�^�X�^�b�NIntStack2�i�\�[�X���j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntStackEx0402.h"

/*--- �X�^�b�N�̏����� ---*/
int Initialize( IntStack *s , int max ) {
	s->ptrA = 0;
	if( ( s->stk = calloc( max , sizeof( int ) ) ) == NULL ) {
		s->max = 0;								// �z��̐����Ɏ��s
		s->ptrB = 0;							//���s���A�g�p���鎖���Ȃ��̂�0��ǉ���
		return -1;
	}
	s->ptrB = max - 1;							//�z��̐����ɐ��������̂Ŕz��̌���B�̓Y��(�C���f�b�N�X)���w�聚
	s->max = max;
	return 0;
}

/*--- �X�^�b�N�Ƀf�[�^���v�b�V�� ---*/
int Push( IntStack *s , int sw , int x ) {
	if( s->ptrA >= s->ptrB + 1 )				// �X�^�b�N�͖��t�@if( s->ptr >= s->max ) --> if( s->ptrA >= s->ptrB + 1 ) B�̈ʒu��max�ɂȂ�̂ł��̂悤�Ɏw�聚
		return -1;

	switch( sw ) {
		case StackA: s->stk[s->ptrA++] = x;  break;//�X�^�b�NA���w�肳�ꂽ�Ƃ��A�����炪������
		case StackB: s->stk[s->ptrB--] = x;  break;//�X�^�b�NB���w�肳�ꂽ�Ƃ��A�����炪����(�f�N�������g�œY�����X���C�h������)��
	}
	return 0;
}

/*--- �X�^�b�N����f�[�^���|�b�v ---*/
int Pop( IntStack *s , int sw , int *x ) {
	switch( sw ) {								// �ǉ���
		case StackA:
		if( s->ptrA <= 0 )						// �X�^�b�N�͋�
			return -1;
		*x = s->stk[--s->ptrA];
		break;

		case StackB:
		if( s->ptrB >= s->max - 1 )				// �X�^�b�N�͋�
			return -1;
		*x = s->stk[++s->ptrB];
		break;
	}
	return 0;
}

/*--- �X�^�b�N����f�[�^���s�[�N ---*/
int Peek( const IntStack *s , int sw , int *x ) {
	switch( sw ) {								// �ύX��
		case StackA:
		if( s->ptrA <= 0 )						// �X�^�b�N�͋�
			return -1;
		*x = s->stk[s->ptrA - 1];
		break;

		case StackB:			//�X�^�b�NB�̋@�\��ǉ���
		if( s->ptrB >= s->max - 1 )				// �X�^�b�N�͋�
			return -1;
		*x = s->stk[s->ptrB + 1];
		break;
	}
	return 0;
}

/*--- �X�^�b�N����ɂ��� ---*/
void Clear( IntStack *s , int sw ) {
	switch( sw ) {								// �ύX��
		case StackA: s->ptrA = 0;			break;
		case StackB: s->ptrB = s->max - 1;	break;//�X�^�b�NB�̋@�\��ǉ���
	}
}

/*--- �X�^�b�N�̗e�� ---*/
int Capacity( const IntStack *s ) {
	return s->max;
}

/*--- �X�^�b�N�ɐς܂�Ă���f�[�^�� ---*/
int Size( const IntStack *s , int sw ) {
	return ( sw == StackA ) ? s->ptrA : s->max - s->ptrB - 1;// �ύX��
}

/*--- �X�^�b�N�͋� ---*/
int IsEmpty( const IntStack *s , int sw ) {
	return ( sw == StackA ) ? ( s->ptrA <= 0 ) : ( s->ptrB >= s->max - 1 );// �ύX��
}

/*--- �X�^�b�N�͖��t�� ---*/
int IsFull( const IntStack *s ) {
	return s->ptrA >= s->ptrB + 1;	// �ύX��
}

/*--- �X�^�b�N����̒T�� ---*/
int Search( const IntStack *s , int sw , int x ) {
	switch( sw ) {				// �ύX��
		case StackA:
		for( int i = s->ptrA - 1; i >= 0; i-- )		// ���と��ɐ��`�T��
			if( s->stk[i] == x )
				return i;		// �T������
		return -1;				// �T�����s

		case StackB:			//�X�^�b�NB�̋@�\��ǉ���
		for( int i = s->ptrB + 1; i < s->max; i++ )	// ���と��ɐ��`�T��
			if( s->stk[i] == x )
				return i;		// �T������
		return -1;				// �T�����s
	}
}

/*--- �S�f�[�^�̕\�� ---*/
void Print( const IntStack *s , int sw ) {
	switch( sw ) {				// �ύX��
		case StackA:
		for( int i = 0; i < s->ptrA; i++ )			// �ꁨ����ɑ���
			printf( "%d " , s->stk[i] );
		break;

		case StackB:			//�X�^�b�NB�̋@�\��ǉ���
		for( int i = s->max - 1; i > s->ptrB; i-- )	// �ꁨ����ɑ���
			printf( "%d " , s->stk[i] );
		break;
	}
	putchar( '\n' );
}

/*--- �X�^�b�N�̌�n�� ---*/
void Terminate( IntStack *s ) {
	if( s->stk != NULL )
		free( s->stk );				// �z���j��
	s->max = s->ptrA = s->ptrB = 0;	// �ύX��
}
