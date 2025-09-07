// ���K6-22�@�x���\�[�g�i�ŏ��l�ƍő�l���w��j

#include <stdio.h>
#include <stdlib.h>

/*--- �x���\�[�g�i�z��v�f�̒l��min�ȏ�max�ȉ��j ---*/
void counting(int a[], int n, int min, int max)
{
	int *f = calloc(max - min + 2, sizeof(int));	// �ݐϓx��
	int *b = calloc(n, sizeof(int));				// ��Ɨp�ړI�z��

	for (int i=0;	i <= max-min+1;	i++) f[i] = 0;					// [Step0]
	for (int i=0;	i < n;			i++) f[a[i]-min]++;				// [Step1]
	for (int i=1;	i <= max-min+1; i++) f[i] += f[i - 1];			// [Step2]
	for (int i=n-1; i >= 0;			i--) b[--f[a[i]-min]] = a[i];	// [Step3]
	for (int i=0;	i < n;			i++) a[i] = b[i];				// [Step4]

	free(b);
	free(f);
}
int main(void)
{
	int nx;
	int min, max;			// �ŏ��l�ƍő�l

	puts("�x���\�[�g");
	printf("�v�f�� : ");
	scanf("%d", &nx);
	int *x = calloc(nx, sizeof(int));	// �v�f��nx��int�^�z��x�𐶐�

	printf("�ŏ��l�F");
	scanf("%d", &min);

	while (1) {
		printf("�ő�l�F");
		scanf("%d", &max);
		if (max > min) break;
		printf("%d���傫�Ȓl����͂��Ă��������B\n", min);
	}

	printf("%d�`%d�̐�������͂���B\n", min, max);
	for (int i = 0; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while (x[i] < min || x[i] > max);
	}

	counting(x, nx, min, max);			// �z��x��x���\�[�g

	puts("�����Ƀ\�[�g���܂����B");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);							// �z��x��j��

	return 0;
}
