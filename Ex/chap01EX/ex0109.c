// ���K1-9�@����a��b���܂߁A���̂������̑S�����̑��a�����߂�

#include <stdio.h>

/*--- ����a��b���܂߁A���̂������̑S�����̑��a�����߂� ---*/
int sumof(int a, int b)
{
	int min, max;

	if (a < b) {
		min = a;  max = b;
	} else {
		min = b;  max = a;
	}

	int sum = 0;
	for (int i = min; i <= max; i++)
		sum += i;

	return sum;
}

int main(void)
{
	int a, b;

	printf("a�̒l�F");   scanf("%d", &a);
	printf("b�̒l�F");   scanf("%d", &b);

	printf("����a,b�Ԃ̑S�����̘a��%d�ł��B\n", sumof(a, b));

	return 0;
}
