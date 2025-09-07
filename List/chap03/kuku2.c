// ‹ã‹ã‚Ì‰ÁZ‚ÆæZi•Ê‰ğj
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*--- x1‚Æx2‚Ì˜a‚ğ‹‚ß‚é ---*/
int sum(int x1, int x2)
{
	return x1 + x2;
}

/*--- x1‚Æx2‚ÌÏ‚ğ‹‚ß‚é ---*/
int mul(int x1, int x2)
{
	return x1 * x2;
}

/*--- ŠÖ”kuku‚Ì•Ê‰ğ ---*/
void kuku(int calc(int, int))
{
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++)
			printf("%3d", calc(i, j));
		putchar('\n');
	}
}

int main(void)
{
	puts("‹ã‹ã‚Ì‰ÁZ•\");
	kuku(sum);

	puts("\n‹ã‹ã‚ÌæZ•\");
	kuku(mul);

	while( 1 ) {
	}

	return 0;
}
