// �P���}���\�[�g
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- �P���}���\�[�g ---*/
void insertion(int a[], int n)
{
	for (int i = 1; i < n; i++) {					//1�Y��1�����Âl���`�F�b�N���Ă���
		int tmp = a[i];								//���ׂ�l���ꎞ�m��
		int j;
		for (j = i; j > 0 && a[j - 1] > tmp; j--)	//�߂܂��Ă���l�̍��ׂ��傫�������͐��������X�ړ������Ă���
			a[j] = a[j - 1];
		a[j] = tmp;									//���for������������m�ۂ��Ă������l���I�����_��j�ɑ������
	}
}

int main(void)
{
	int nx;

	puts("�P���}���\�[�g");
	printf("�v�f�� : ");
	scanf("%d", &nx);
	int* x = calloc(nx, sizeof(int));	// �v�f��nx��int�^�z��x�𐶐�

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	insertion(x, nx);					// �z��x��P���}���\�[�g

	puts("�����Ƀ\�[�g���܂����B");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);							// �z��x��j��

	while( 1 ) {
	}

	return 0;
}
