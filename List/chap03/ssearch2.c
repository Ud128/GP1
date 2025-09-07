// üŒ`’Tõifor•¶j

#include <stdio.h>
#include <stdlib.h>

/*--- —v‘f”n‚Ì”z—ña‚©‚çkey‚Æˆê’v‚·‚é—v‘f‚ğüŒ`’Tõifor•¶j---*/
int search(const int a[], int n, int key)
{
	for (int i = 0; i < n; i++)
		if (a[i] == key)
			return i;			// ’Tõ¬Œ÷

	return -1;					// ’Tõ¸”s
}

int main(void)
{
	int nx, ky;

	puts("üŒ`’Tõ");
	printf("—v‘f” : ");
	scanf("%d", &nx);
	int *x = calloc(nx, sizeof(int));	// —v‘f”nx‚ÌintŒ^”z—ñx‚ğ¶¬

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}
	printf("’T‚·’l : ");
	scanf("%d", &ky);

	int idx = search(x, nx, ky);		// ”z—ñx‚©‚ç’l‚ªky‚Ì—v‘f‚ğüŒ`’Tõ

	if (idx == -1)
		puts("’Tõ‚É¸”s‚µ‚Ü‚µ‚½B");
	else
		printf("%d‚Íx[%d]‚É‚ ‚è‚Ü‚·B\n", ky, idx);

	free(x);							// ”z—ñx‚ğ”jŠü

	return 0;
}
