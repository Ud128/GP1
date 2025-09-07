// ���K4-3 int�^�L���[ArrayIntQueue�i�\�[�X���j

#include <stdio.h>
#include <stdlib.h>
#include "ArrayIntQueue.h"

/*--- �L���[�̏����� ---*/
int Initialize(ArrayIntQueue *q, int max)
{
	q->num = 0;
	if ((q->que = calloc(max, sizeof(int))) == NULL) {
		q->max = 0;								// �z��̐����Ɏ��s
		return -1;
	}
	q->max = max;
	return 0;
}

/*--- �L���[�Ƀf�[�^���G���L���[ ---*/
int Enque(ArrayIntQueue *q, int x)
{
	if (q->num >= q->max)
		return -1;								// �L���[�͖��t
	else {
		q->que[q->num++] = x;
		return 0;
	}
}

/*--- �L���[����f�[�^���f�L���[ ---*/
int Deque(ArrayIntQueue *q, int *x)
{
	if (q->num <= 0)							// �L���[�͋�
		return -1;
	else {
		*x = q->que[0];
		for (int i = 0; i < q->num - 1; i++)
			q->que[i] = q->que[i + 1];
		q->num--;
		return 0;
	}
}

/*--- �L���[����f�[�^���s�[�N ---*/
int Peek(const ArrayIntQueue *q, int *x)
{
	if (q->num <= 0)							// �L���[�͋�
		return -1;
	*x = q->que[0];
	return 0;
}

/*--- �S�f�[�^���폜 ---*/
void Clear(ArrayIntQueue *q)
{
	q->num = 0;
}

/*--- �L���[�̗e�� ---*/
int Capacity(const ArrayIntQueue *q)
{
	return q->max;
}

/*--- �L���[�ɒ~�����Ă���f�[�^�� ---*/
int Size(const ArrayIntQueue *q)
{
	return q->num;
}

/*--- �L���[�͋� ---*/
int IsEmpty(const ArrayIntQueue *q)
{
	return q->num <= 0;
}

/*--- �L���[�͖��t�� ---*/
int IsFull(const ArrayIntQueue *q)
{
	return q->num >= q->max;
}

/*--- �L���[����̒T�� ---*/
int Search(const ArrayIntQueue *q, int x)
{
	for (int i = 0; i < q->num; i++) {
		if (q->que[i] == x)
			return i;		// �T������
	}
	return -1;				// �T�����s
}

/*--- �S�f�[�^�̕\�� ---*/
void Print(const ArrayIntQueue *q)
{
	for (int i = 0; i < q->num; i++)
		printf("%d ", q->que[i]);
	putchar('\n');
}

/*--- �L���[�̌�n�� ---*/
void Terminate(ArrayIntQueue *q)
{
	if (q->que != NULL)
		free(q->que);							// �z���j��
	q->max = q->num = 0;
}
