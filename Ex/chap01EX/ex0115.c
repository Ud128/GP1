// ���K1-15�@�����`��\��

#include <stdio.h>

int main(void)
{
	int height, width;			// �����Ɖ���

	puts("�����`��\�����܂��B");

	do {
		printf("�����́F");
		scanf("%d", &height);
	} while (height <= 0);

	do {
		printf("�����́F");
		scanf("%d", &width);
	} while (width <= 0);

	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++)
			putchar('*');
		putchar('\n');
	}

	return 0;
}
