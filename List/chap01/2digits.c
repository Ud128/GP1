// �Q���̐��̐����l�i10�`99�j��ǂݍ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int no;

	printf("�Q���̐����l����͂��Ă��������B\n");

	do {
		printf("�l�́F");
		scanf("%d", &no);
	} while (no < 10 || no > 99);

	printf("�ϐ�no�̒l��%d�ɂȂ�܂����B\n", no);

	while( 1 ) {
	}

	return 0;
}
