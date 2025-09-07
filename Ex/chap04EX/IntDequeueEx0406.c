// ���K4-6 int�^�f�b�NIntDequeue�i�\�[�X���j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntDequeueEx0406.h"

//�֐��̑������ŁA�^�� IntQueue �� IntDequeue ��(�^�̒��g�͓����Ȃ̂ŁADequeue ��p�ӂ������̂�)�ύX��

/*--- �f�b�N�̏����� ---*/
int Initialize( IntDequeue *q , int max ) {
	q->num = q->front = q->rear = 0;
	if( ( q->que = calloc( max , sizeof( int ) ) ) == NULL ) {
		q->max = 0;							// �z��̐����Ɏ��s
		return -1;
	}
	q->max = max;
	return 0;
}

/*--- �f�b�N�̐擪�Ƀf�[�^���G���L���[ ---*/
int EnqueFront( IntDequeue *q , int x ) {	//EnqueFront��V���ɒǉ���
	if( q->num >= q->max )
		return -1;							// �f�b�N�͖��t
	else {
		q->num++;
		if( --q->front < 0 )
			q->front = q->max - 1;			//�v�f�ԍ���max�������ɂ��炵�Ēl������
		q->que[q->front] = x;
		return 0;
	}
}

/*--- �f�b�N�̖����Ƀf�[�^���G���L���[ ---*/
int EnqueRear( IntDequeue *q , int x ) {	//Enque�̖��O��EnqueRear��(���g�͑O�Ɠ���)�ύX��
	if( q->num >= q->max )
		return -1;							// �f�b�N�͖��t
	else {
		q->num++;
		q->que[q->rear++] = x;
		if( q->rear == q->max )
			q->rear = 0;
		return 0;
	}
}

/*--- �f�b�N�̐擪����f�[�^���f�L���[ ---*/
int DequeFront( IntDequeue *q , int *x ) {	//Deque�̖��O��DequeFront��(���g�͑O�Ɠ���)�ύX��
	if( q->num <= 0 )						// �f�b�N�͋�
		return -1;
	else {
		q->num--;
		*x = q->que[q->front++];
		if( q->front == q->max )
			q->front = 0;
		return 0;
	}
}

/*--- �f�b�N�̖�������f�[�^���f�L���[ ---*/
int DequeRear( IntDequeue *q , int *x ) {	//DequeRear��V���ɒǉ���
	if( q->num <= 0 )						// �f�b�N�͋�
		return -1;
	else {
		q->num--;
		if( --q->rear < 0 )
			q->rear = q->max - 1;			//�v�f�ԍ���max�������ɂ��炵�āA�z��̒l��x�ɓn����
		*x = q->que[q->rear];
		return 0;
	}
}

/*--- �f�b�N�̐擪����f�[�^���s�[�N ---*/
int PeekFront( const IntDequeue *q , int *x ) {	//Peek�̖��O��PeekFront��(���g�͑O�Ɠ���)�ύX��
	if( q->num <= 0 )							// �f�b�N�͋�
		return -1;
	*x = q->que[q->front];
	return 0;
}

/*--- �f�b�N�̖�������f�[�^���s�[�N ---*/
int PeekRear( const IntDequeue *q , int *x ) {	//PeekRear��V���ɒǉ���
	if( q->num <= 0 )							// �f�b�N�͋�
		return -1;
	*x = q->que[q->rear];						//���A�̈ʒu�̔z��̒l��x�ɓn����
	return 0;
}

/*--- �S�f�[�^���폜 ---*/
void Clear( IntDequeue *q ) {
	q->num = q->front = q->rear = 0;
}

/*--- �f�b�N�̗e�� ---*/
int Capacity( const IntDequeue *q ) {
	return q->max;
}

/*--- �f�b�N�ɒ~�����Ă���f�[�^�� ---*/
int Size( const IntDequeue *q ) {
	return q->num;
}

/*--- �f�b�N�͋� ---*/
int IsEmpty( const IntDequeue *q ) {
	return q->num <= 0;
}

/*--- �f�b�N�͖��t�� ---*/
int IsFull( const IntDequeue *q ) {
	return q->num >= q->max;
}

/*--- �f�b�N����̒T�� ---*/
int Search( const IntDequeue *q , int x ) {
	int idx;

	for( int i = 0; i < q->num; i++ ) {
		if( q->que[idx = ( i + q->front ) % q->max] == x )
			return idx;		// �Y��(�C���f�b�N�X)�̒T������
	}
	return -1;				// �T�����s
}

/*--- �f�b�N����̒T���i�_���I�Y����ԋp�j---*/
int Search2( const IntDequeue *q , int x ) {
	for( int i = 0; i < q->num; i++ ) {
		if( q->que[( i + q->front ) % q->max] == x )
			return i;		// �T������
	}
	return -1;				// �T�����s
}

/*--- �S�f�[�^�̕\�� ---*/
void Print( const IntDequeue *q ) {
	for( int i = 0; i < q->num; i++ )
		printf( "%d " , q->que[( i + q->front ) % q->max] );
	putchar( '\n' );
}

/*--- �f�b�N�̌�n�� ---*/
void Terminate( IntDequeue *q ) {
	if( q->que != NULL )
		free( q->que );							// �z���j��
	q->max = q->num = q->front = q->rear = 0;
}
