// ���K1-10�@b - a�̒l�����߂�ib > a�ƂȂ�悤�ɓǂݍ��ށj

#include <stdio.h>

int main(void)
{
	int a, b;

	printf("a�̒l�F");
	scanf("%d", &a);

	while (1) {
		printf("b�̒l�F");
		scanf("%d", &b);
		if (b > a) break;
		printf("a���傫�Ȓl����͂���I\n");
	}

	printf("b - a��%d�ł��B\n", b - a);

	return 0;
}


/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int a, b;

    printf("a�̒l�F");
    scanf("%d", &a);

    do {
        printf("b�̒l�F");
        scanf("%d", &b);
        if (b < a) {
            printf("a���傫�Ȓl����͂���I\n");
        }
    } while (b < a);

    printf("b - a��%d�ł��B\n", b - a);

    return 0;
}
*/