// ���K1-18�@������������ׂċt�����s���~�b�h��\��

#include <stdio.h>

/*--- ������������ׂċt�����s���~�b�h��\�� ---*/
void nrpira( int n ) {
	for( int i = 1; i <= n; i++ ) {					// i�s�ii = 1, 2, �c ,n�j
		for( int j = 1; j <= i - 1; j++ )			// i-1��' '��\��
			putchar( ' ' );
		for( int j = 1; j <= ( n - i ) * 2 + 1; j++ )	// (n-i)*2+1�̐�����\��
			printf( "%d" , i % 10 );
		putchar( '\n' );
	}
}

int main( void ) {
	int n;

	puts( "�s���~�b�h��\�����܂��B" );
	do {
		printf( "�i���́F" );
		scanf( "%d" , &n );
	} while( n <= 0 );

	nrpira( n );

	return 0;
}
