// �O�̐����l��ǂݍ���ōő�l�����߂�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a, b, c;

	printf("�O�̐����̍ő�l�����߂܂��B\n");
	printf("a�̒l�F");   scanf("%d", &a);
	printf("b�̒l�F");   scanf("%d", &b);
	printf("c�̒l�F");   scanf("%d", &c);

	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;

	printf("�ő�l��%d�ł��B\n", max);

	while( 1 ) {
	}

	return 0;
}
