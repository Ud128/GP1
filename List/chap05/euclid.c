// ���[�N���b�h�̌ݏ��@�ɂ���čő���񐔂����߂�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*--- �����lx, y�̍ő���񐔂�ԋp���� ---*/
int gcd( int x , int y ) {
	if( y == 0 )
		return x;
	else
		return gcd( y , x % y );
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
