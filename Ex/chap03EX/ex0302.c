// ���K3-2�@���`�T���i��P�ŁF�T���ߒ���\���j*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- �v�f��n�̔z��a����key�ƈ�v����v�f����`�T�� ---*/
int search(const int a[], int n, int key)
{
	printf("   |");
	for (int i = 0; i < n; i++)
		printf("%3d", i);		//�Y��(�C���f�b�N�X)����ׂ�
	printf("\n---+");
	for (int i = 0; i < n; i++)
		printf("---", i);
	printf("--\n");

	for (int i = 0; i < n; i++) {
		printf("   |");
		printf("%*s", 3 * (i - 1) + 5, "");//"%*s" �� "�ϕ�"�̕�����o�͂��s���w��q ��Fprintf("%*s", 10, "");�@�u��10�̋󕶎�����o�͂���v�B"" �͋󕶎���i����0�j�ł�
		printf("*\n");			// * ��ł�
		printf("%3d|", i);
		for (int j = 0; j < n; j++)
			printf("%3d", a[j]);//�z��̒��g����ׂ�
		putchar('\n');

		if (a[i] == key)
			return i;			// �T������

		printf("   |\n");
	}

	return -1;					// �T�����s
}

int main(void)
{
	int nx, ky;

	puts("���`�T���i�ԕ��@�j");
	printf("�v�f�� : ");
	scanf("%d", &nx);
	int *x = calloc(nx + 1, sizeof(int));	// �v�f��(nx + 1)��int�^�z��x�𐶐�

	for (int i = 0; i < nx; i++) {			// ���ӁF�l��ǂݍ��ނ̂�nx��
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}
	printf("�T���l : ");
	scanf("%d", &ky);

	int idx = search(x, nx, ky);			// �z��x����l��ky�̗v�f����`�T��

	if (idx == -1)
		puts("�T���Ɏ��s���܂����B");
	else
		printf("%d��x[%d]�ɂ���܂��B\n", ky, idx);

	free(x);								// �z��x��j��

	while( 1 ) {
	}

	return 0;
}
