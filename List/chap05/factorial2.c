// �K��l���ċA�I�ɋ��߂�i�������Z�q�j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*--- �����ln�̊K���ԋp�i�������Z�q�j ---*/
int factorial(int n)
{
	return (n > 0) ? n * factorial(n - 1) : 1;
}

int main(void)
{
	int x;

	printf("��������͂���F");
	scanf("%d", &x);

	printf("%d�̊K���%d�ł��B\n", x, factorial(x));

	return 0;
}
