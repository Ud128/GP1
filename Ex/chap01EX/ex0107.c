// ���K1-7�@1, 2, �c, n�̑��a�����߂�ifor���F����\���j

#include <stdio.h>

int main(void)
{
	int n;

	puts("1����n�܂ł̑��a�����߂܂��B");

	printf("n�̒l�F");
	scanf("%d", &n);

	int sum = 0;		// ���a

	for (int  i = 1; i <= n; i++)	// i = 1, 2, �c, n
		sum += i;					// sum��i��������

	for (int i = 1; i < n; i++)
		printf("%d + ", i);
	printf("%d = %d\n", n, sum);

	return 0;
}
