// �e��ɂP�̉��܂�z�u����g�������ċA�I�ɗ�

#include <stdio.h>

int pos[8];			// �e��̉��܂̈ʒu

/*--- �Ֆʁi�e��̉��܂̈ʒu�j���o�� ---*/
void print(void)
{
	for (int i = 0; i < 8; i++)
		printf("%2d", pos[i]);
	putchar('\n');
}

/*--- i��ڂɉ��܂�z�u ---*/
void set(int i)
{
	for (int j = 0; j < 8; j++) {
		pos[i] = j;
		if (i == 7)				// �S��ɔz�u�I��
			print();
		else
			set(i + 1);			// ���̗�ɉ��܂�z�u
	}
}

int main(void)
{
	set(0);						// 0��ڂɉ��܂�z�u

	return 0;
}
