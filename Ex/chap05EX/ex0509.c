// ���K5-9�@�W���ܖ��������i���܂��L�������ŕ\���j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int flag_a[8];		// �e�s�ɉ��܂��z�u���݂�
int flag_b[15];		// �^�Ίp���ɉ��܂��z�u���݂�
int flag_c[15];		// �_�Ίp���ɉ��܂��z�u���݂�
int pos[8];			// �e��̉��܂̈ʒu */

/*--- �Ֆʁi�e��̉��܂̈ʒu�j���o�� ---*/
void print(void)
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			printf("%s", j == pos[i] ? "��" : "��");
		putchar('\n');
	}
	putchar('\n');

	/*
	int c = 400000000;
	while( c-- ) {

	}
	*/
}

/*--- i��ڂ̓K���Ȉʒu�ɉ��܂�z�u ---*/
void set(int i)
{
	for (int j = 0; j < 8; j++) {
		if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7]) {
			pos[i] = j;
			if (i == 7)			// �S��ɔz�u�I��
				print();
			else {
				flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
				set(i + 1);		// ���̗�ɔz�u
				flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
			}
		}
	}
}

int main(void)
{
	for (int i = 0; i <  8; i++)
		flag_a[i] = 0;
	for (int i = 0; i < 15; i++)
		flag_b[i] = flag_c[i] = 0;

	set(0);						// 0��ڂɔz�u

	while( 1 ) {
	}

	return 0;
}
