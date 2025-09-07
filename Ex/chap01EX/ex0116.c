// ���K1-16�@���p�񓙕ӎO�p�`��\��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


#if 1
/*--- ���p���������̒��p�񓙕ӎO�p�`��\�� ---*/
void triangleLB(int n)
{
	for (int i = 1; i <= n; i++) {				// i�s�ii = 1, 2, �c ,n�j
		for (int j = 1; j <= i; j++)			// i��'*'��\��
			putchar('*');
		putchar('\n');
	}
}

/*--- ���p�����㑤�̒��p�񓙕ӎO�p�`��\�� ---*/
void triangleLU(int n)
{
	for (int i = 1; i <= n; i++) {				// i�s�ii = 1, 2, �c ,n�j
		for (int j = 1; j <= n - i + 1; j++)		// n-i+1��'*'��\��
			putchar('*');
		putchar('\n');
	}
}

/*--- ���p���E�㑤�̒��p�񓙕ӎO�p�`��\�� ---*/
void triangleRU(int n)
{
	for (int i = 1; i <= n; i++) {				// i�s�ii = 1, 2, �c ,n�j
		for (int j = 1; j <= i - 1; j++)		// i-1��' '��\��
			putchar(' ');
		for (int j = 1; j <= n - i + 1; j++)	// n-i+1��'*'��\��
			putchar('*');
		putchar('\n');							// ���s
	}
}

/*--- ���p���E�����̒��p�񓙕ӎO�p�`��\�� ---*/
void triangleRB(int n)
{
	for (int i = 1; i <= n; i++) {				// i�s�ii = 1, 2, �c ,n�j
		for (int j = 1; j <= n - i; j++)		// n-i��' '��\��
			putchar(' ');
		for (int j = 1; j <= i; j++)			// i��'*'��\��
			putchar('*');
		putchar('\n');							// ���s
	}
}
#else
//-------------------------------------------------------------------------
// ���������p
void triangleLB(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			putchar('*');
		}
		putchar('\n');
	}
}

// ���オ���p
void triangleLU(int n) {
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			putchar('*');
		}
		putchar('\n');
	}
}

// �E�オ���p
void triangleRU(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			putchar(' ');
		}
		for (int j = 0; j < n - i; j++) {
			putchar('*');
		}
		putchar('\n');
	}
}

// �E�������p
void triangleRB(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) {
			putchar(' ');
		}
		for (int j = 1; j <= i; j++) {
			putchar('*');
		}
		putchar('\n');
	}
}
#endif


int main(void)
{
	int n;

	puts("���p�񓙕ӎO�p�`��\�����܂��B");
	do {
		printf("�傫���́F");
		scanf("%d", &n);
	} while (n <= 0);

	printf("\n�����������p\n");   triangleLB(n);
	printf("\n���㑤�����p\n");   triangleLU(n);
	printf("\n�E�㑤�����p\n");   triangleRU(n);
	printf("\n�E���������p\n");   triangleRB(n);

	system("pause");

	return 0;
}
