// ���K5-2�@���[�N���b�h�̌ݏ��@�ɂ���čő���񐔒l���ċA�I�ɋ��߂�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*--- �����lx, y�̍ő���񐔂�ԋp���� ---*/
int gcd( int x , int y ) {
	while( y != 0 ) {
		int temp = y;
		y = x % y;
		x = temp;
	}
	return x;
}

int main( void ) {
	int x , y;

	puts( "��̐����̍ő���񐔂����߂܂��B" );

	printf( "��������͂���F" );
	scanf( "%d" , &x );

	printf( "��������͂���F" );
	scanf( "%d" , &y );

	printf( "�ő���񐔂�%d�ł��B\n" , gcd( x , y ) );

	while( 1 ) {
	}

	return 0;
}
