// ���`�T���ifor���j

#include <stdio.h>
#include <stdlib.h>

/*--- �v�f��n�̔z��a����key�ƈ�v����v�f����`�T���ifor���j---*/
int search(const int a[], int n, int key)
{
	for (int i = 0; i < n; i++)
		if (a[i] == key)
			return i;			// �T������

	return -1;					// �T�����s
}

int main(void)
{
	int nx, ky;

	puts("���`�T��");
	printf("�v�f�� : ");
	scanf("%d", &nx);
	int *x = calloc(nx, sizeof(int));	// �v�f��nx��int�^�z��x�𐶐�

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}
	printf("�T���l : ");
	scanf("%d", &ky);

	int idx = search(x, nx, ky);		// �z��x����l��ky�̗v�f����`�T��

	if (idx == -1)
		puts("�T���Ɏ��s���܂����B");
	else
		printf("%d��x[%d]�ɂ���܂��B\n", ky, idx);

	free(x);							// �z��x��j��

	return 0;
}
