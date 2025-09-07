// int�^�L���[IntQueue�i�\�[�X���j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntQueueEx0404.h"

/*--- �L���[�̏����� ---*/
int Initialize( IntQueue *q , int max ) {
	q->num = q->front = q->rear = 0;
	if( ( q->que = calloc( max , sizeof( int ) ) ) == NULL ) {
		q->max = 0;								// �z��̐����Ɏ��s
		return -1;
	}
	q->max = max;
	return 0;
}

/*--- �L���[�Ƀf�[�^���G���L���[ ---*/
int Enque( IntQueue *q , int x ) {
	if( q->num >= q->max )
		return -1;								// �L���[�͖��t
	else {
		q->num++;
		q->que[q->rear++] = x;
		if( q->rear == q->max )
			q->rear = 0;
		return 0;
	}
}

/*--- �L���[����f�[�^���f�L���[ ---*/
int Deque( IntQueue *q , int *x ) {
	if( q->num <= 0 )							// �L���[�͋�
		return -1;
	else {
		q->num--;
		*x = q->que[q->front++];
		if( q->front == q->max )
			q->front = 0;
		return 0;
	}
}

/*--- �L���[����f�[�^���s�[�N ---*/
int Peek( IntQueue *q , int *x ) {
	if( q->num <= 0 )							// �L���[�͋�
		return -1;
	*x = q->que[q->front];
	return 0;
}

/*--- �S�f�[�^���폜 ---*/
void Clear( IntQueue *q ) {
	q->num = q->front = q->rear = 0;
}

/*--- �L���[�̗e�� ---*/
int Capacity( const IntQueue *q ) {
	return q->max;
}

/*--- �L���[�ɒ~�����Ă���f�[�^�� ---*/
int Size( const IntQueue *q ) {
	return q->num;
}

/*--- �L���[�͋� ---*/
int IsEmpty( const IntQueue *q ) {
	return q->num <= 0;
}

/*--- �L���[�͖��t�� ---*/
int IsFull( const IntQueue *q ) {
	return q->num >= q->max;
}

/*--- �L���[����̒T�� ---*/
int Search( const IntQueue *q , int x ) {
	for( int i = 0; i < q->num; i++ ) {
		int idx;
		if( q->que[idx = ( i + q->front ) % q->max] == x )//�����͑�����Ă��Ȃ��z��̌���������邽�߁Afront��i�̑����Z����@mod max �Ŕz�������������
			return idx;		// �Y��(�C���f�b�N�X)�̒T������
	}
	return -1;				// �T�����s
}

/*--- �L���[����̒T���i�_���I�Y����ԋp�j---*/
int Search2( const IntQueue *q , int x ) {			//���K4-4�ǉ���
	for( int i = 0; i < q->num; i++ ) {
		if( q->que[( i + q->front ) % q->max] == x )//�����̂������͏��Search�ƑS��������������i�ŉ��񌟍���������front���牽�Ԗڂ������߂Ă���
			return i;		// �T������
	}
	return -1;				// �T�����s
}

/*--- �S�f�[�^�̕\�� ---*/
void Print( const IntQueue *q ) {
	for( int i = 0; i < q->num; i++ )
		printf( "%d " , q->que[( i + q->front ) % q->max] );
	putchar( '\n' );
}

/*--- �L���[�̌�n�� ---*/
void Terminate( IntQueue *q ) {
	if( q->que != NULL )
		free( q->que );							// �z���j��
	q->max = q->num = q->front = q->rear = 0;
}
