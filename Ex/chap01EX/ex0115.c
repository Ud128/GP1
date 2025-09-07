// 演習1-15　長方形を表示

#include <stdio.h>

int main(void)
{
	int height, width;			// 高さと横幅

	puts("長方形を表示します。");

	do {
		printf("高さは：");
		scanf("%d", &height);
	} while (height <= 0);

	do {
		printf("横幅は：");
		scanf("%d", &width);
	} while (width <= 0);

	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++)
			putchar('*');
		putchar('\n');
	}

	return 0;
}
