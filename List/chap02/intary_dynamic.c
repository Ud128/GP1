// int�^�̔z��𓮓I�ɐ������Ĕj��

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int na;		// �z��a�̗v�f��

	printf("�v�f���F");
	scanf("%d", &na);

	int* a = calloc(na, sizeof(int));	// �v�f��na��int�^�z��𐶐�

	if (a == NULL)
		puts("�L����̊m�ۂɎ��s���܂����B");
	else {
		printf("%d�̐�������͂��Ă��������B\n", na);
		for (int i = 0; i < na; i++) {
			printf("a[%d] : ", i);
			scanf("%d", &a[i]);
		}

		printf("�e�v�f�̒l�͎��̂Ƃ���ł��B\n");
		for (int i = 0; i < na; i++)
			printf("a[%d] = %d\n", i, a[i]);

		free(a);			// �v�f��na��int�^�z���j��
	}

	return 0;
}
