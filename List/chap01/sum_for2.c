// 1, 2, �c, n�̑��a�����߂�ido���ɂ���Đ��̐����l�݂̂�n�ɓǂݍ��ށj
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;

	puts("1����n�܂ł̑��a�����߂܂��B");

	do {
		printf("n�̒l�F");
		scanf("%d", &n);
	} while (n <= 0);

	int sum = 0;		// ���a

	for (int i = 1; i <= n; i++)	// i = 1, 2, �c, n
		sum += i;					// sum��i��������

	printf("1����%d�܂ł̑��a��%d�ł��B\n", n, sum);

	while( 1 ) {
	}

	return 0;
}
