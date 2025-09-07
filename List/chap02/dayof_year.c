// 年内の経過日数を求める
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*- 各月の日数 -*/
int mdays[][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},//通常
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},//閏年
};

/*--- 西暦year年は閏年か ---*/
int isleap( int year ) {
	//4で割り切れる年は閏年	ただし、100で割り切れる年は平年（閏年ではない） || 400で割り切れる年は閏年
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

/*--- 西暦y年m月d日の年内の経過日数を求める ---*/
int dayof_year( int y , int m , int d ) {
	int days = d;							// 日数（ここは直接打ち込まれた"日"が入ってくる）

	for( int i = 1; i < m; i++ )
		days += mdays[isleap( y )][i - 1];	//直接打ち込まれた"日"に月の日数max分が加算される
	return days;
}

int main( void ) {
	int retry;		// もう一度？

	do {
		int year , month , day;		// 年・月・日
		printf( "年：" );   scanf( "%d" , &year );
		printf( "月：" );   scanf( "%d" , &month );
		printf( "日：" );   scanf( "%d" , &day );

		printf( "年内で%d日目です。\n" , dayof_year( year , month , day ) );

		printf( "もう一度しますか（1…はい／0…いいえ）：" );
		scanf( "%d" , &retry );
	} while( retry == 1 );


	return 0;
}
