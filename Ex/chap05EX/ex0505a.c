// ���K5-5 �ċA�ɑ΂��闝����[�߂邽�߂̐^�ɍċA�I�Ȋ֐��i�Ăяo���񐔂��J�E���g�j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int counter = 0;	// �֐�recur�̌Ăяo���񐔁�

/*--- �^�ɍċA�I�Ȋ֐�recur ---*/
void recur(int n)
{
	counter++;		//���ۂ̃J�E���g����镔����
	if (n > 0) {
		recur(n - 1);
		printf("%d\n", n);
		recur(n - 2);
	}
}

int main(void)
{
	int x;

	printf("��������͂���F");
	scanf("%d", &x);

	recur(x);

	printf("�֐�recur��%d��Ăяo����܂����B\n", counter);

	while( 1 ) {
	}

	return 0;
}
