// �e�s�E�e��ɂP�̉��܂�z�u����g�������ċA�I�ɗ�

#include <stdio.h>

int flag[8];		// �e�s�ɉ��܂��z�u���݂�
int pos[8];			// �e��̉��܂̈ʒu

/*--- �Ֆʁi�e��̉��܂̈ʒu�j���o�� ---*/
void print(void)
{
	for (int i = 0; i < 8; i++)
		printf("%2d", pos[i]);
	putchar('\n');
}

/*--- i��ڂ̓K���Ȉʒu�ɉ��܂�z�u ---*/
void set(int i)
{
	for (int j = 0; j < 8; j++) {
		if (!flag[j]) {			// j�s�ɂ͉��܂͖��z�u
			pos[i] = j;
			if (i == 7)			// �S��ɔz�u�I��
				print();
			else {
				flag[j] = 1;
				set(i + 1);		// ���̗�ɔz�u
				flag[j] = 0;
			}
		}
	}
}

int main(void)
{
	for (int i = 0; i < 8; i++)
		flag[i] = 0;

	set(0);						// 0��ڂɔz�u

	return 0;
}
