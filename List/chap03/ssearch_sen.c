// ���`�T���i�ԕ��@�j

#include <stdio.h>
#include <stdlib.h>

/*--- �v�f��n�̔z��a����key�ƈ�v����v�f����`�T���i�ԕ��@�j---*/
int search(int a[], int n, int key)
{
	int i = 0;

	a[n] = key;			// �ԕ���ǉ�

	while (1) {
		if (a[i] == key)
			break;		// ������
		i++;
	}

	return i == n ? -1 : i;
}

int main(void)
{
	int nx, ky;

	puts("���`�T���i�ԕ��@�j");
	printf("�v�f�� : ");
	scanf("%d", &nx);
	int *x = calloc(nx + 1, sizeof(int));	// �v�f��(nx + 1)��int�^�z��x�𐶐�

	for (int i = 0; i < nx; i++) {			// ���ӁF�l��ǂݍ��ނ̂�nx��
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}
	printf("�T���l : ");
	scanf("%d", &ky);

	int idx = search(x, nx, ky);			// �z��x����l��ky�̗v�f����`�T��

	if (idx == -1)
		puts("�T���Ɏ��s���܂����B");
	else
		printf("%d��x[%d]�ɂ���܂��B\n", ky, idx);

	free(x);								// �z��x��j��

	return 0;
}
