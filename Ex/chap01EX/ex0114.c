// ���K1-14�@�����`��\��

#include <stdio.h>

int main(void)
{
	int n;					// �i��

	puts("�����`��\�����܂��B");
	do {
		printf("�i���́F");
		scanf("%d", &n);
	} while (n <= 0);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			putchar('*');
		putchar('\n');
	}

	return 0;
}
