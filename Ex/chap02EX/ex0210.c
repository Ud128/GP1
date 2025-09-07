// ���K2-10�@�N���̌o�ߓ��������߂�iwhile���j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*- �e���̓��� -*/
int mdays[][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

/*--- ����year�N�͉[�N�� ---*/
int isleap( int year ) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

/*--- ����y�Nm��d���̔N���̌o�ߓ��������߂� ---*/
int dayof_year( int y , int m , int d ) {
	while( --m )
		d += mdays[isleap( y )][m - 1];
	return ( d );
}

int main( void ) {
	int retry;		// ������x�H

	do {
		int year , month , day;		// �N�E���E��
		printf( "�N�F" );   scanf( "%d" , &year );
		printf( "���F" );   scanf( "%d" , &month );
		printf( "���F" );   scanf( "%d" , &day );

		printf( "�N����%d���ڂł��B\n" , dayof_year( year , month , day ) );

		printf( "������x���܂����i1�c�͂��^0�c�������j�F" );
		scanf( "%d" , &retry );
	} while( retry == 1 );

	return 0;
}
