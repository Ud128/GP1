// bsearch�֐��𗘗p���������ɕ��񂾔z�񂩂�̒T��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- �������r����֐��i�����p�j---*/
int int_cmp(const int *a, const int *b)
{
	if (*a < *b)
		return -1;
	else if (*a > *b)
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
				&ky,							// �T���l�ւ̃|�C���^
				x,								// �z��
				nx,								// �v�f��
				sizeof(int),					// �v�f�̑傫��
				(int (*)(const void *, const void *))int_cmp	// ��r�֐�
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
