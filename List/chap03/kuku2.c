// ���̉��Z�Ə�Z�i�ʉ��j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*--- x1��x2�̘a�����߂� ---*/
int sum(int x1, int x2)
{
	return x1 + x2;
}

/*--- x1��x2�̐ς����߂� ---*/
int mul(int x1, int x2)
{
	return x1 * x2;
}

/*--- �֐�kuku�̕ʉ� ---*/
void kuku(int calc(int, int))
{
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++)
			printf("%3d", calc(i, j));
		putchar('\n');
	}
}

int main(void)
{
	puts("���̉��Z�\");
	kuku(sum);

	puts("\n���̏�Z�\");
	kuku(mul);

	while( 1 ) {
	}

	return 0;
}
