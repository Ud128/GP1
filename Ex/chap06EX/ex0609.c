// ���K6-9�@�P���}���\�[�g�i�f�[�^��a[1]�ȍ~�Ɋi�[����Ă���j

#include <stdio.h>
#include <stdlib.h>

/*--- �P���}���\�[�g�i�f�[�^��a[1]�ȍ~�Ɋi�[����Ă���j---*/
void insertion(int a[], int n)
{
	for (int i = 2; i <= n; i++) {
		int tmp = a[0] = a[i];
		int j;
		for (j = i; a[j - 1] > tmp; j--)
			a[j] = a[j - 1];
		if (j > 0) a[j] = tmp;
	}
}

int main(void)
{
	int nx;

	puts("�P���}���\�[�g");
	printf("�v�f�� : ");
	scanf("%d", &nx);
	int *x = calloc(nx + 1, sizeof(int));	// �v�f��(nx+1)��int�^�z��x�𐶐�

	for (int i = 1; i < nx + 1; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	insertion(x, nx);					// �z��x��P���}���\�[�g

	puts("�����Ƀ\�[�g���܂����B");
	for (int i = 1; i < nx + 1; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);							// �z��x��j��

	return 0;
}
