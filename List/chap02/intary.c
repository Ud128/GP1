// int[5]�^�̔z��i�v�f�^��int�^�ŗv�f����5�̔z��j�̗v�f�ɒl��ǂݍ���ŕ\��

#include <stdio.h>

#define N	5						// �z��̗v�f��

int main()
{
	int a[N];						// �z��̐錾

	for (int i = 0; i < N; i++) {	// �e�v�f�ɒl��ǂݍ���
		printf("a[%d] : ", i);
		scanf("%d", &a[i]);
	}

	puts("�e�v�f�̒l");
	for (int i = 0; i < N; i++) {	// �e�v�f�̒l��\��
		printf("a[%d] = %d\n", i, a[i]);
	}

	return 0;
}
