// ���K1-2�@�O�̐����l�̍ŏ��l�����߂�

#include <stdio.h>

/*--- a, b, c�̍ŏ��l�����߂� ---*/
int min3(int a, int b, int c)
{
	int min = a;	// �ŏ��l

	if (b < min) min = b;
	if (c < min) min = c;

	return min;
}

int main(void)
{
	int a, b, c;

	printf("�O�̐����̍ŏ��l�����߂܂��B\n");
	printf("a�̒l�F");   scanf("%d", &a);
	printf("b�̒l�F");   scanf("%d", &b);
	printf("c�̒l�F");   scanf("%d", &c);

	printf("�ŏ��l��%d�ł��B\n", min3(a, b, c));

	return 0;
}
