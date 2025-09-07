// ���K6-21�@�x���\�[�g�i�\�[�g�ߒ��̏ڍׂ�\���j

#include <stdio.h>
#include <stdlib.h>

/*--- �x���\�[�g�i�z��v�f�̒l��0�ȏ�max�ȉ��j---*/
void counting(int a[], int n, int max)
{
	int *f = calloc(max + 1, sizeof(int));		// �ݐϓx��
	int *b = calloc(n,       sizeof(int));		// ��Ɨp�ړI�z��

	puts("\n�\�[�g�O�z��");
	for (int i = 0; i < n; i++) printf("%3d", i);		putchar('\n');
	for (int i = 0; i < n; i++) printf("---", i);		putchar('\n');
	for (int i = 0; i < n; i++) printf("%3d", a[i]);	putchar('\n');

	for (int i = 0;		i <= max; i++) f[i] = 0;			// [Step0]
	for (int i = 0;		i < n;	  i++) f[a[i]]++;			// [Step1]

	puts("\n�x�����z");
	for (int i = 0; i < max; i++) printf("%3d", i);		putchar('\n');
	for (int i = 0; i < max; i++) printf("---", i);		putchar('\n');
	for (int i = 0; i < max; i++) printf("%3d", f[i]);	putchar('\n');

	for (int i = 1;		i <= max; i++) f[i] += f[i - 1];	// [Step2]

	puts("\n�ݐϓx�����z");
	for (int i = 0; i < max; i++) printf("%3d", i);		putchar('\n');
	for (int i = 0; i < max; i++) printf("---", i);		putchar('\n');
	for (int i = 0; i < max; i++) printf("%3d", f[i]);	putchar('\n');

	putchar('\n');
	for (int i = n - 1; i >= 0;	  i--) {					// [Step3]
		b[--f[a[i]]] = a[i];
		printf("a[%2d]��%2d��b[%2d]�Ɋi�[�B\n", i, a[i], f[a[i]]);
	}

	for (int i = 0;		i < n;	  i++) a[i] = b[i];			// [Step4]

	puts("\n�\�[�g��z��");
	for (int i = 0; i < n; i++) printf("%3d", i);		putchar('\n');
	for (int i = 0; i < n; i++) printf("---", i);		putchar('\n');
	for (int i = 0; i < n; i++) printf("%3d", a[i]);	putchar('\n');
	free(b);
	free(f);
}

int main(void)
{
	int nx;
	const int max = 100;			// �ő�l

	puts("�x���\�[�g");
	printf("�v�f�� : ");
	scanf("%d", &nx);
	int *x = calloc(nx, sizeof(int));

	printf("0�`%d�̐�������͂���B\n", max);
	for (int i = 0; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while (x[i] < 0 || x[i] > max);
	}

	counting(x, nx, max);		// �z��x��x���\�[�g

	puts("�����Ƀ\�[�g���܂����B");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);					// �z��x��j��

	return 0;
}
