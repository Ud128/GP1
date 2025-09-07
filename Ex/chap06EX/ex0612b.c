// ���K6-12�@�V�F���\�[�g�i��Q�ŁF�v�f�̈ړ��񐔂�\���j

#include <stdio.h>
#include <stdlib.h>

/*--- �V�F���\�[�g�i��Q�ŁF�v�f�̈ړ��񐔂�ԋp�j---*/
int shell(int a[], int n)
{
	int h;
	int count = 0;					// �ړ���

	for (h = 1; h < n; h = h * 3 + 1)
		;

	for ( ; h > 0; h /= 3)
		for (int i = h; i < n; i++) {
			int	tmp = a[i];
			int j;
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {
				a[j + h] = a[j];
				count++;
			}
			a[j + h] = tmp;
			count++;
		}
	return count;
}

int main(void)
{
	int nx;

	puts("�V�F���\�[�g");
	printf("�v�f���F");
	scanf("%d", &nx);
	int *x = calloc(nx, sizeof(int));	// �v�f��nx��int�^�z��x�𐶐�

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	int count = shell(x, nx);			// �z��x���V�F���\�[�g

	puts("�����Ƀ\�[�g���܂����B");
	for (int i =0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	printf("�v�f�̈ړ��񐔂�%d��ł����B\n", count);

	free(x);							// �z��x��j��

	return 0;
}
