// �ǂݍ���10�i������2�i���`36�i���Ɋ�ϊ����ĕ\��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*--- type�^��x��y�̒l������ ---*/
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- �����lx��n�i���ɕϊ��������������̕��т�z��d�Ɋi�[ ---*/
int card_conv( unsigned x , int n , char d[] ) {
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0;							// �ϊ���̌���

	if( x == 0 )							// 0�ł����
		d[digits++] = dchar[0];				// �ϊ����0
	else
		while( x ) {
			d[digits++] = dchar[x % n];		// n�Ŋ�������]���i�[
			x /= n;
		}

	for( int i = 0; i < digits / 2; i++ )	// �z��d�̕��т𔽓]
		swap( char , d[i] , d[digits - i - 1] );

	return digits;
}

int main( void ) {
	puts( "10�i������ϊ����܂��B" );

	int retry;				// ������x�H

	do {
		unsigned no;		// �ϊ����鐮��
		int      cd;		// �
		char     cno[512];	// �ϊ���̐��l�̊e���̐������i�[���镶���̔z�� 

		printf( "�ϊ�����񕉂̐����F" );
		scanf( "%u" , &no );

		do {
			printf( "���i���ɕϊ����܂����i2-36�j�F" );
			scanf( "%d" , &cd );
		} while( cd < 2 || cd > 36 );

		int dno = card_conv( no , cd , cno );	// no��dno����cd�i���ɕϊ�

		printf( "%d�i���ł�" , cd );
		for( int i = 0; i < dno; i++ )			// �e���̕��������ɕ\��
			printf( "%c" , cno[i] );
		printf( "�ł��B\n" );

		printf( "������x���܂����i1�c�͂��^0�c�������j�F" );
		scanf( "%d" , &retry );
	} while( retry == 1 );

	while( 1 ) {
	}

	return 0;
}
