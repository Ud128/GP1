// ���K5-5 �^�ɍċA�I�Ȋ֐�recur�����������Ď���

#include <stdio.h>

int counter = 0;	// �֐�recur�̌Ăяo����

static char memo[128][1024];		// �����p������̔z��

/*--- �������𓱓������֐�recur ---*/
void recur(int n) {
	counter++;
	if (memo[n + 1][0] != '\0')
		printf("%s", memo[n + 1]);				// �������o��
	else {
		if (n > 0) {
			recur(n - 1);
			printf("%d\n", n);
			recur(n - 2);
			sprintf(memo[n + 1], "%s%d\n%s", memo[n], n, memo[n - 1]);
		}
		else {
			strcpy(memo[n + 1], "");
		}
	}
}

int main(void)
{
	int x;

	printf("��������͂���F");
	scanf("%d", &x);

	recur(x);

	printf("�֐�recur��%d��Ăяo����܂����B\n", counter);

	return 0;
}
