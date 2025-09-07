// ���K6-8�@�P���}���\�[�g�i�}���ߒ��̏ڍׂ�\���j

#include <stdio.h>
#include <stdlib.h>

/*--- �P���}���\�[�g�i�}���ߒ��̏ڍׂ�\���j---*/
void insertion(int a[], int n)
{
	for (int i = 1; i < n; i++) {
		int tmp = a[i];
		int j;

		for (int m = 0; m < n; m++)
			printf("%3d ", a[m]);
		putchar('\n');

		for (j = i; j > 0 && a[j - 1] > tmp; j--)
			a[j] = a[j - 1];
		a[j] = tmp;

		printf("%*s%s", 4 * j , "", (i != j) ? "^-" : "  ");
		for (int m = 0; m < 4*(i-j); m++)
			putchar('-');
		printf("+\n\n");
	}
	for (int m = 0; m < n; m++)
		printf("%3d ", a[m]);
	putchar('\n');
}

int main(void)
{
	int nx;

	puts("�P���}���\�[�g");
	printf("�v�f�� : ");
	scanf("%d", &nx);
	int *x = calloc(nx, sizeof(int));	// �v�f��nx��int�^�z��x�𐶐�

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	insertion(x, nx);					// �z��x��P���}���\�[�g

	puts("�����Ƀ\�[�g���܂����B");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);							// �z��x��j��

	return 0;
}
