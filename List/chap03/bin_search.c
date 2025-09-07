// ‚Q•ª’Tõ

#include <stdio.h>
#include <stdlib.h>

/*--- —v‘f”n‚Ì”z—ña‚©‚çkey‚Æˆê’v‚·‚é—v‘f‚ğ‚Q•ª’Tõ ---*/
int bin_search(const int a[], int n, int key)
{
	int pl = 0;						// ’Tõ”ÍˆÍ‚Ìæ“ª‚Ì“Yš
	int pr = n - 1;					// @@V@@––”ö‚Ì“Yš

	do {
		int pc = (pl + pr) / 2;		// @@V@@’†‰›‚Ì“Yš
		if (a[pc] == key)			// ’Tõ¬Œ÷
			return pc;
		else if (a[pc] < key)
			pl = pc + 1;			// ’Tõ”ÍˆÍ‚ğŒã”¼‚Éi‚è‚Ş
		else
			pr = pc - 1;			// ’Tõ”ÍˆÍ‚ğ‘O”¼‚Éi‚è‚Ş
	} while (pl <= pr);

	return -1;						// ’Tõ¸”s
}

int main(void)
{
	int nx, ky;

	puts("‚Q•ª’Tõ");
	printf("—v‘f” : ");
	scanf("%d", &nx);
	int *x = calloc(nx, sizeof(int));	// —v‘f”nx‚ÌintŒ^”z—ñx‚ğ¶¬

	printf("¸‡‚É“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\n");
	printf("x[0] : ");
	scanf("%d", &x[0]);

	for (int i = 1; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while (x[i] < x[i - 1]);		// ˆê‚Â‘O‚Ì’l‚æ‚è‚à¬‚³‚¯‚ê‚ÎÄ“ü—Í
	}
	printf("’T‚·’l : ");
	scanf("%d", &ky);

	int idx = bin_search(x, nx, ky);	// ”z—ñx‚©‚ç’l‚ªky‚Ì—v‘f‚ğ‚Q•ª’Tõ

	if (idx == -1)
		puts("’Tõ‚É¸”s‚µ‚Ü‚µ‚½B");
	else
		printf("%d‚Íx[%d]‚É‚ ‚è‚Ü‚·B\n", ky, idx);

	free(x);							// ”z—ñx‚ğ”jŠü

	return 0;
}
