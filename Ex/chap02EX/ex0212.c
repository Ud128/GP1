// ���K2-12�@���t��\���\����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int y;	// ����N
	int m;	// ���i1�`12�j
	int d;	// ���i1�`31�j
} Date;

Date Before(Date x, int n);
Date After( Date x, int n);

/*--- �e���̓��� ---*/
static int  mdays[2][13] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},	// ���N
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},	// �[�N
};

/*--- ����year�N�͉[�N�� ---*/
int isleap(int year)
{
	return year % 4 == 0  &&  year % 100 != 0  ||  year % 400 == 0;
}

/*--- y�Nm��d����\���\���̂�ԋp����֐�DateOf ---*/
Date DateOf(int y, int m, int d)
{
	Date temp;

	temp.y = y;
	temp.m = m;
	temp.d = d;

	return temp;
}

/*--- ���tx��n����̓��t��Ԃ� ---*/
Date After(Date x, int n)
{
	if (n < 0)
		return Before(x, -n);

	x.d += n;

	while (x.d > mdays[isleap(x.y)][x.m - 1]) {
		x.d -= mdays[isleap(x.y)][x.m - 1];
		if (++x.m > 12) {
			x.y++;		// �N���J��グ
			x.m = 1;	// ����1���ɖ߂�
		}
	}
	return x;
}

/*--- ���tx��n���O�̓��t��Ԃ� ---*/
Date Before(Date x, int n)
{
	if (n < 0)
		return After(x, -n);

	x.d -= n;

	while (x.d < 1) {
		if (--x.m < 1) {
			x.y--;		// �N��߂�
			x.m = 12;
		}
		x.d += mdays[isleap(x.y)][x.m - 1];
	}

	return x;
}

/*--- ���t��\�� ---*/
int Print(Date x)
{
	int y = x.y;
	int m = x.m;
	int d = x.d;

	char *ws[] = {"��", "��", "��", "��", "��", "��", "�y"};
	if (m == 1 || m == 2) {
		y--;
		m += 12;
	}
	printf("%04d�N%02d��%02d��(%s)", x.y, x.m, x.d, 
				ws[(y + y/4 - y/100 + y/400 + (13*m+8)/5 + d) % 7]);
}

int main(void)
{
	int y, m, d;

	printf("���t����͂��Ă��������B\n");
	printf("�N�F");  scanf("%d", &y);
	printf("���F");  scanf("%d", &m);
	printf("���F");  scanf("%d", &d);

	Date x = DateOf(y, m, d);

	int n;

	printf("�����O�^��̓��t�����߂܂����F");
	scanf("%d", &n);

	printf("%d����̓��t�F", n);   Print(After(x, n));   putchar('\n');

	printf("%d���O�̓��t�F", n);   Print(Before(x, n));  putchar('\n');

	while( 1 ) {
	}

	return 0;
}
