// �z��̗v�f�̕��т𔽓]����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- type�^��x��y�̒l������ ---*/
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0) // if ����{}���g���Ă����Ă��do while�����Ŗ��Ȃ� { type t = x; x = y; y = t; } 

// void* �� swap�֐�
void vt_swap( size_t size , void *a , void *b ) {//�������ł͏��������s���Ă���̂ŁA*�����Ă��Ă��n�����̓A�h���X�ł���K�v������
	//�����ӁFswap( sizeof(int) , &a[i] , &a[n - i - 1]);�ƌĂяo�������������Ȃ���
	void *t = malloc( size );	//���̊֐����Ō^���������ɒl���󂯎��̂ŁA��������}���b�N�Ō^�̑傫�����w�肵�āA�I�u�W�F�N�gt���q�[�v�Ɋm��
	if( t == NULL ) {
		printf( "Error: �������m�ۂɎ��s���܂���\n" );
	}
	else {

		memcpy( t , a , size);	//a��t�Ƀo�C�g�P�ʂŕ���
		memcpy( a , b , size );	//b��a�Ƀo�C�g�P�ʂŕ���
		memcpy( b , t , size );	//t��b�Ƀo�C�g�P�ʂŕ���

		free( t );				//t�̃q�[�v�����
	}
}


/*--- �v�f��n�̔z��a�̗v�f�̕��т𔽓] ---*/
void ary_reverse(int a[], int n)
{
	for (int i = 0; i < n / 2; i++)
		swap( int , a[i] , a[n - i - 1]);
}

int main(void)
{
	int nx;		// �z��x�̗v�f��

	printf("�v�f���F");
	scanf("%d", &nx);
	int *x = calloc(nx, sizeof(int));	// �v�f��nx��int�^�z��x�𐶐�

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	ary_reverse(x, nx);					// �z��x�̗v�f�̕��т𔽓]

	printf("�v�f�̕��т𔽓]���܂����B\n");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);							// �z��x��j��

	while( 1 ) {
	}

	return 0;
}
