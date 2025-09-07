// ���K6-7�@�P���I���\�[�g�i�\�[�g�ߒ��̏ڍׂ�\���j

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- �P���I���\�[�g�i�\�[�g�ߒ��̏ڍׂ�\���j---*/
void selection(int a[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		for (int m = 0; m < n; m++)
			printf((m == i) ? "  * " : (m == min) ? "  + " : "    ");
		putchar('\n');

		for (int m = 0; m < n; m++)
			printf("%3d ", a[m]);
		putchar('\n');

		swap(int, a[i], a[min]);
	}
	putchar('\n');
	for (int m = 0; m < n; m++)
		printf("%3d ", a[m]);
	putchar('\n');
}

int main(void)
{
	int nx;

	puts("�P���I���\�[�g");
	printf("�v�f�� : ");
	scanf("%d", &nx);
	int *x = calloc(nx, sizeof(int));	// �v�f��nx��int�^�z��x�𐶐�

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	selection(x, nx);					// �z��x��P���I���\�[�g

	puts("�����Ƀ\�[�g���܂����B");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);							// �z��x��j��

	return 0;
}

