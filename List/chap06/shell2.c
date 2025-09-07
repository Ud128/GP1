// �V�F���\�[�g�i��Q�ŁFh �� �c, 13, 4, 1�j

#include <stdio.h>
#include <stdlib.h>

/*--- �V�F���\�[�g�i��Q�ŁFh �� �c, 13, 4, 1�j---*/
void shell(int a[], int n)
{
	int h;

	for (h = 1; h < n; h = h * 3 + 1)
		;

	for (; h > 0; h /= 3)
		for (int i = h; i < n; i++) {
			int tmp = a[i];
			int j;
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
				a[j + h] = a[j];
			a[j + h] = tmp;
		}
}

int main(void)
{
	int nx;

	puts("�V�F���\�[�g");
	printf("�v�f���F");
	scanf("%d", &nx);
	int* x = calloc(nx, sizeof(int));	// �v�f��nx��int�^�z��x�𐶐�

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	shell(x, nx);				// �z��x���V�F���\�[�g

	puts("�����Ƀ\�[�g���܂����B");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);					// �z��x��j��

	return 0;
}
