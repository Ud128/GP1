// 1, 2, �c, n�̑��a�����߂�iwhile���j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;

	puts("1����n�܂ł̑��a�����߂܂��B");

	printf("n�̒l�F");
	scanf("%d", &n);

	int sum = 0;		// ���a
	int i = 1;

	while (i <= n) {	// i��n�ȉ��ł���ΌJ��Ԃ�
		sum += i;		// sum��i��������
		i++;			// i�̒l���C���N�������g
	}
	printf("1����%d�܂ł̑��a��%d�ł��B\n", n, sum);

	while( 1 ) {
	}

	return 0;
}
