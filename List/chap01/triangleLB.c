// �����������p�̓񓙕ӎO�p�`��\��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;

	do {
		printf("���i�̎O�p�`�ł����F");
		scanf("%d", &n);
	} while (n <= 0);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			putchar('*');
		putchar('\n');
	}

	while( 1 ) {
	}

	return 0;
}
