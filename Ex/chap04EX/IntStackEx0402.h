// ���K4-2 �z�񋤗Lint�^�X�^�b�NIntStack2�i�w�b�_���j

#ifndef ___IntStack2
#define ___IntStack2

enum {StackA, StackB};		//�ǉ� ��

/*--- �z�񋤗L�X�^�b�N����������\���� ---*/
typedef struct {
	int max;		// �X�^�b�N�̗e��
	int ptrA;		// �X�^�b�N�|�C���^�`
	int ptrB;		// �X�^�b�N�|�C���^�a ��
	int *stk;		// �X�^�b�N�{�́i�̐擪�v�f�ւ̃|�C���^�j
} IntStack;

/*--- �X�^�b�N�̏����� ---*/
int Initialize(IntStack *s, int max);

/*--- �X�^�b�N�Ƀf�[�^���v�b�V�� ---*/
int Push(IntStack *s, int sw, int x);

/*--- �X�^�b�N����f�[�^���|�b�v ---*/
int Pop(IntStack *s, int sw, int *x);

/*--- �X�^�b�N����f�[�^���s�[�N ---*/
int Peek(const IntStack *s, int sw, int *x);

/*--- �X�^�b�N����ɂ��� ---*/
void Clear(IntStack *s, int sw);

/*--- �X�^�b�N�̗e�� ---*/
int Capacity(const IntStack *s);

/*--- �X�^�b�N�ɐς܂�Ă���f�[�^�� ---*/
int Size(const IntStack *s, int sw);

/*--- �X�^�b�N�͋� ---*/
int IsEmpty(const IntStack *s, int sw);

/*--- �X�^�b�N�͖��t�� ---*/
int IsFull(const IntStack *s);

/*--- �X�^�b�N����̒T�� ---*/
int Search(const IntStack *s, int sw, int x);

/*--- �S�f�[�^�̕\�� ---*/
void Print(const IntStack *s, int sw);

/*--- �X�^�b�N�̌�n�� ---*/
void Terminate(IntStack *s);

#endif
