// bsearch�֐��𗘗p���������ɕ��񂾔z�񂩂�̒T���i�L���X�g�����ɗ��p�ł����r�֐��j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*-- �L���X�g�����ɗ��p�ł����r�֐� --*/
int int_cmp(const void *a, const void *b)
{
	if (*(int *)a < *(int *)b)
		return -1;
	else if (*(int *)a > *(int *)b)
		return 1;
	else
		return 0;
}

int main(void)
{
	int nx, ky;

	puts("bsearch�֐��ɂ��T��");
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

	int *p = bsearch(
				&ky,			// �T���l�ւ̃|�C���^
				x,				// �z��
				nx,				// �v�f��
				sizeof(int),	// �v�f�̑傫��
				int_cmp			// ��r�֐�
			 );

	if (p == NULL)
		puts("�T���Ɏ��s���܂����B");
	else
		printf("%d��x[%d]�ɂ���܂��B\n", ky, (int)(p - x));

	free(x);							// �z��x��j��

	while( 1 ) {
	}

	return 0;
}
