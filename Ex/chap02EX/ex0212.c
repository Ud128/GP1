// 演習2-12　日付を表す構造体
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int y;	// 西暦年
	int m;	// 月（1～12）
	int d;	// 日（1～31）
} Date;

Date Before(Date x, int n);
Date After( Date x, int n);

/*--- 各月の日数 ---*/
static int  mdays[2][13] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},	// 平年
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},	// 閏年
};

/*--- 西暦year年は閏年か ---*/
int isleap(int year)
{
	return year % 4 == 0  &&  year % 100 != 0  ||  year % 400 == 0;
}

/*--- y年m月d日を表す構造体を返却する関数DateOf ---*/
Date DateOf(int y, int m, int d)
{
	Date temp;

	temp.y = y;
	temp.m = m;
	temp.d = d;

	return temp;
}

/*--- 日付xのn日後の日付を返す ---*/
Date After(Date x, int n)
{
	if (n < 0)
		return Before(x, -n);

	x.d += n;

	while (x.d > mdays[isleap(x.y)][x.m - 1]) {
		x.d -= mdays[isleap(x.y)][x.m - 1];
		if (++x.m > 12) {
			x.y++;		// 年を繰り上げ
			x.m = 1;	// 月を1月に戻す
		}
	}
	return x;
}

/*--- 日付xのn日前の日付を返す ---*/
Date Before(Date x, int n)
{
	if (n < 0)
		return After(x, -n);

	x.d -= n;

	while (x.d < 1) {
		if (--x.m < 1) {
			x.y--;		// 年を戻す
			x.m = 12;
		}
		x.d += mdays[isleap(x.y)][x.m - 1];
	}

	return x;
}

/*--- 日付を表示 ---*/
int Print(Date x)
{
	int y = x.y;
	int m = x.m;
	int d = x.d;

	char *ws[] = {"日", "月", "火", "水", "木", "金", "土"};
	if (m == 1 || m == 2) {
		y--;
		m += 12;
	}
	printf("%04d年%02d月%02d日(%s)", x.y, x.m, x.d, 
				ws[(y + y/4 - y/100 + y/400 + (13*m+8)/5 + d) % 7]);
}

int main(void)
{
	int y, m, d;

	printf("日付を入力してください。\n");
	printf("年：");  scanf("%d", &y);
	printf("月：");  scanf("%d", &m);
	printf("日：");  scanf("%d", &d);

	Date x = DateOf(y, m, d);

	int n;

	printf("何日前／後の日付を求めますか：");
	scanf("%d", &n);

	printf("%d日後の日付：", n);   Print(After(x, n));   putchar('\n');

	printf("%d日前の日付：", n);   Print(Before(x, n));  putchar('\n');

	while( 1 ) {
	}

	return 0;
}
