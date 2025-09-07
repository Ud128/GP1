// ���K3-4�@�Q���T���i�T���ߒ���\���j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- �v�f��n�̔z��a����key�ƈ�v����v�f���Q���T�� ---*/
int bin_search(const int a[], int n, int key)
{
	int pl = 0;						// �T���͈͂̐擪�̓Y��
	int pr = n - 1;					// �@�@�V�@�@�����̓Y��

	printf("   |");
	for (int i = 0; i < n; i++)
		printf("%4d", i);
	printf("\n---+");
	for (int i = 0; i < n; i++) 
		printf("----", i);
	printf("--\n");

	do {
		int pc = (pl + pr) / 2;			// �T���͈͂̒����̓Y��

		printf("   |");
		for (int i = 0; i < 4 * pl; i++)//���̊J�n�ʒu�܂ŋ󔒂Ŗ��߂�
			printf(" "); 

		// <- + -> ���݂ǂ���T���Ă��邩�͈̔͂�����
		printf( " <-" );				//��̋󔒂ׂ̗�<���<-������
		for (int i = 0; i < 4 * (pc - pl); i++) //������Z���^�[�̊Ԃ��󔒂Ŗ��߂�
			printf(" "); 
		printf("+");					//�Z���^�[��+������
		for (int i = 0; i < 4 * (pr - pc) - 2; i++) //�E����Z���^�[�̊Ԃ��󔒂Ŗ��߂�
			printf(" "); 
		printf("->\n");					//��̋󔒂ׂ̗�->������


		printf("%3d|", pc);
		for (int i = 0; i < n; i++)
			printf("%4d", a[i]);
		putchar('\n');

		if (a[pc] == key)			// �T������
			return pc;
		else if (a[pc] < key)
			pl = pc + 1;			// �T���͈͂��㔼�ɍi�荞��
		else
			pr = pc - 1;			// �T���͈͂�O���ɍi�荞��

		printf("   |\n");

	} while (pl <= pr);

	return -1;						// �T�����s
}

int main(void)
{
	int nx, ky;

	puts("�Q���T��");
	printf("�v�f�� : ");
	scanf("%d", &nx);
	int *x = calloc(nx, sizeof(int));	// �v�f��nx��int�^�z��x�𐶐�

	printf("�����ɓ��͂��Ă��������B\n");
	printf("x[0] : ");
	scanf("%d", &x[0]);

	for (int i = 1; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while (x[i] < x[i - 1]);		// ��O�̒l������������΍ē���
	}
	printf("�T���l : ");
	scanf("%d", &ky);

	int idx = bin_search(x, nx, ky);	// �z��x����l��ky�̗v�f���Q���T��

	if (idx == -1)
		puts("�T���Ɏ��s���܂����B");
	else
		printf("%d��x[%d]�ɂ���܂��B\n", ky, idx);

	free(x);							// �z��x��j��

	while( 1 ) {
	}

	return 0;
}
