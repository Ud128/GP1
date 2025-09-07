// ���K4-3 int�^�L���[ArrayIntQueue�i�w�b�_���j

#ifndef ___ArrayIntQueue
#define ___ArrayIntQueue

/*--- �L���[����������\���� ---*/
typedef struct {
	int max;		// �L���[�̗e��
	int num;		// ���݂̃f�[�^��
	int *que;		// �L���[�{�́i�̐擪�v�f�ւ̃|�C���^�j
} ArrayIntQueue;

/*--- �L���[�̏����� ---*/
int Initialize(ArrayIntQueue *q, int max);

/*--- �L���[�Ƀf�[�^���G���L���[ ---*/
int Enque(ArrayIntQueue *q, int x);

/*--- �L���[����f�[�^���f�L���[ ---*/
int Deque(ArrayIntQueue *q, int *x);

/*--- �L���[����f�[�^���s�[�N ---*/
int Peek(const ArrayIntQueue *q, int *x);

/*--- �S�f�[�^���폜 ---*/
void Clear(ArrayIntQueue *q);

/*--- �L���[�̗e�� ---*/
int Capacity(const ArrayIntQueue *q);

/*--- �L���[��̃f�[�^�� ---*/
int Size(const ArrayIntQueue *q);

/*--- �L���[�͋� ---*/
int IsEmpty(const ArrayIntQueue *q);

/*--- �L���[�͖��t�� ---*/
int IsFull(const ArrayIntQueue *q);

/*--- �L���[����̒T�� ---*/
int Search(const ArrayIntQueue *q, int x);

/*--- �S�f�[�^�̕\�� ---*/
void Print(const ArrayIntQueue *q);

/*--- �L���[�̌�n�� ---*/
void Terminate(ArrayIntQueue *q);

#endif
