// �N���̌o�ߓ��������߂�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*- �e���̓��� -*/
int mdays[][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},//�ʏ�
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},//�[�N
};

/*--- ����year�N�͉[�N�� ---*/
int isleap( int year ) {
	//4�Ŋ���؂��N�͉[�N	�������A100�Ŋ���؂��N�͕��N�i�[�N�ł͂Ȃ��j || 400�Ŋ���؂��N�͉[�N
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

/*--- ����y�Nm��d���̔N���̌o�ߓ��������߂� ---*/
int dayof_year( int y , int m , int d ) {
	int days = d;							// �����i�����͒��ڑł����܂ꂽ"��"�������Ă���j

	for( int i = 1; i < m; i++ )
		days += mdays[isleap( y )][i - 1];	//���ڑł����܂ꂽ"��"�Ɍ��̓���max�������Z�����
	return days;
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
