// ���K1-11�@���̐����l�̌��������߂�

#include <stdio.h>

int main(void)
{
	int n;

	do {
		printf("���̐����l�F");
		scanf("%d", &n);
	} while (n <= 0);

	int digits = 0;		// ����
	while (n > 0) {
		n /= 10;		// x��10�Ŋ���
		digits++;
	}

	printf("���̐���%d���ł��B\n", digits);

	return 0;
}
