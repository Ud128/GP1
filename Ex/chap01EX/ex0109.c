// 演習1-9　整数aとbを含め、そのあいだの全整数の総和を求める

#include <stdio.h>

/*--- 整数aとbを含め、そのあいだの全整数の総和を求める ---*/
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

	printf("aの値：");   scanf("%d", &a);
	printf("bの値：");   scanf("%d", &b);

	printf("整数a,b間の全整数の和は%dです。\n", sumof(a, b));

	return 0;
}
