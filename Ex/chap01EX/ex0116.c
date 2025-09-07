// 演習1-16　直角二等辺三角形を表示
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


#if 1
/*--- 直角が左下側の直角二等辺三角形を表示 ---*/
void triangleLB(int n)
{
	for (int i = 1; i <= n; i++) {				// i行（i = 1, 2, … ,n）
		for (int j = 1; j <= i; j++)			// i個の'*'を表示
			putchar('*');
		putchar('\n');
	}
}

/*--- 直角が左上側の直角二等辺三角形を表示 ---*/
void triangleLU(int n)
{
	for (int i = 1; i <= n; i++) {				// i行（i = 1, 2, … ,n）
		for (int j = 1; j <= n - i + 1; j++)		// n-i+1個の'*'を表示
			putchar('*');
		putchar('\n');
	}
}

/*--- 直角が右上側の直角二等辺三角形を表示 ---*/
void triangleRU(int n)
{
	for (int i = 1; i <= n; i++) {				// i行（i = 1, 2, … ,n）
		for (int j = 1; j <= i - 1; j++)		// i-1個の' 'を表示
			putchar(' ');
		for (int j = 1; j <= n - i + 1; j++)	// n-i+1個の'*'を表示
			putchar('*');
		putchar('\n');							// 改行
	}
}

/*--- 直角が右下側の直角二等辺三角形を表示 ---*/
void triangleRB(int n)
{
	for (int i = 1; i <= n; i++) {				// i行（i = 1, 2, … ,n）
		for (int j = 1; j <= n - i; j++)		// n-i個の' 'を表示
			putchar(' ');
		for (int j = 1; j <= i; j++)			// i個の'*'を表示
			putchar('*');
		putchar('\n');							// 改行
	}
}
#else
//-------------------------------------------------------------------------
// 左下が直角
void triangleLB(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			putchar('*');
		}
		putchar('\n');
	}
}

// 左上が直角
void triangleLU(int n) {
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			putchar('*');
		}
		putchar('\n');
	}
}

// 右上が直角
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

// 右下が直角
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

	puts("直角二等辺三角形を表示します。");
	do {
		printf("大きさは：");
		scanf("%d", &n);
	} while (n <= 0);

	printf("\n左下側が直角\n");   triangleLB(n);
	printf("\n左上側が直角\n");   triangleLU(n);
	printf("\n右上側が直角\n");   triangleRU(n);
	printf("\n右下側が直角\n");   triangleRB(n);

	system("pause");

	return 0;
}
