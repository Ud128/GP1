// �����𐶐��i���̂Q�F���݂̎����Ɋ�Â��ė����̎��ύX�j

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	srand(time(NULL));
	int x = rand();		// 0�`RAND_MAX�̗���
	int y = rand();		// 0�`RAND_MAX�̗���
	printf("x��%d��y��%d�ł��B\n", x, y);

	return 0;
}
