// ���K1-17�@�L����������ׂăs���~�b�h��\��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*--- �L����������ׂăs���~�b�h��\�� ---*/
void spira( int n ) {
	for( int i = 1; i <= n; i++ ) {						// i�s�ii = 1, 2, �c ,n�j
		for( int j = 1; j <= n - i; j++ )				// n-i��' '��\��
			putchar( ' ' );								//�ꕶ���Â�����ł��Ă���(�킴�ƕ��������Ă����Ɠ����������₷���Ȃ�)
		for( int j = 1; j <= ( i - 1 ) * 2 + 1; j++ )	// (i-1)*2+1��'*'��\��
			putchar( '*' );								//���for�̑�����ł��Ă���
		putchar( '\n' );									//�i�̉��s���s��
	}
}


int main( void ) {
	int n;

	puts( "�s���~�b�h��\�����܂��B" );
	do {
		printf( "�i���́F" );
		scanf( "%d" , &n );
	} while( n <= 0 );

	spira( n );

	while( 1 ) {
	}

	return 0;
}

