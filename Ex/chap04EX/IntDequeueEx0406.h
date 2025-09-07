// ���K4-6 int�^�f�b�NIntDequeue�i�w�b�_���j

#ifndef ___IntDequeue
#define ___IntDequeue

//IntQueue�ƒ��g�͑S�����������ǁAIntDequeue �ɖ��O��ύX��

/*--- �f�b�N����������\���� ---*/
typedef struct {
	int max;		// �f�b�N�̗e��
	int num;		// ���݂̃f�[�^��
	int front;		// �擪�v�f�J�[�\��
	int rear;		// �����v�f�J�[�\��
	int *que;		// �f�b�N�{�́i�̐擪�v�f�ւ̃|�C���^�j
} IntDequeue;

//�֐��̑������ŁA�^�� IntQueue �� IntDequeue �ɕύX��

/*--- �f�b�N�̏����� ---*/
int Initialize( IntDequeue *q , int max );

/*--- �f�b�N�̐擪�Ƀf�[�^���G���L���[ ---*/
int EnqueFront( IntDequeue *q , int x );

/*--- �f�b�N�̖����Ƀf�[�^���G���L���[ ---*/
int EnqueRear( IntDequeue *q , int x );

/*--- �f�b�N�̐擪����f�[�^���f�L���[ ---*/
int DequeFront( IntDequeue *q , int *x );

/*--- �f�b�N�̖�������f�[�^���f�L���[ ---*/
int DequeRear( IntDequeue *q , int *x );

/*--- �f�b�N�̐擪����f�[�^���s�[�N ---*/
int PeekFront( const IntDequeue *q , int *x );

/*--- �f�b�N�̖�������f�[�^���s�[�N ---*/
int PeekRear( const IntDequeue *q , int *x );

/*--- �S�f�[�^���폜 ---*/
void Clear( IntDequeue *q );

/*--- �f�b�N�̗e�� ---*/
int Capacity( const IntDequeue *q );

/*--- �f�b�N��̃f�[�^�� ---*/
int Size( const IntDequeue *q );

/*--- �f�b�N�͋� ---*/
int IsEmpty( const IntDequeue *q );

/*--- �f�b�N�͖��t�� ---*/
int IsFull( const IntDequeue *q );

/*--- �f�b�N����̒T�� ---*/
int Search( const IntDequeue *q , int x );

/*--- �f�b�N����̒T���i�_���I�Y����ԋp�j---*/
int Search2( const IntDequeue *q , int x );

/*--- �S�f�[�^�̕\�� ---*/
void Print( const IntDequeue *q );

/*--- �f�b�N�̌�n�� ---*/
void Terminate( IntDequeue *q );

#endif
