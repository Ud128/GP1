// ���K6-11�@�Q���}���\�[�g�i�v�f�̈ړ���memmove�֐��𗘗p�j

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*--- �Q���}���\�[�g�i�v�f�̈ړ���memmove�֐��𗘗p�j---*/
void bin_insertion(int a[], int n)
{
	for (int i = 1; i < n; i++) {
		int key = a[i];
		int pl = 0;			// �T���͈͐擪�̓Y��
		int pr = i - 1;		// �@ �V �@�����̓Y��
		int pc;				// �@ �V �@�����̓Y��

		do {
			pc = (pl + pr) / 2;
			if (a[pc] == key)		// �T������
				break;
			else if (a[pc] < key)
				pl = pc + 1;
			else
				pr = pc - 1;
		} while (pl <= pr);
		int pd = (pl <= pr) ? pc + 1 : pr + 1;		// �}�����׈ʒu�̓Y��

		memmove(&a[pd + 1], &a[pd], (i - pd) * sizeof(int)); 
		a[pd] = key;
	}
}

int main(void)
{
	int nx;

	puts("�Q���}���\�[�g");
	printf("�v�f�� : ");
	scanf("%d", &nx);
	int *x = calloc(nx, sizeof(int));	// �v�f��nx��int�^�z��x�𐶐�

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	bin_insertion(x, nx);				// �z��x��P���}���\�[�g

	puts("�����Ƀ\�[�g���܂����B");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);							// �z��x��j��

	return 0;
}
