// 乱数を生成（その２：現在の時刻に基づいて乱数の種を変更）

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	srand(time(NULL));
	int x = rand();		// 0～RAND_MAXの乱数
	int y = rand();		// 0～RAND_MAXの乱数
	printf("xは%dでyは%dです。\n", x, y);

	return 0;
}
