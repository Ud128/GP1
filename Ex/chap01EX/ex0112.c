// ���K1-12�@���̕\��\���i�^�C�g���t���j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main( void ) {
	printf( "   |" );
	for( int i = 1; i <= 9; i++ )
		printf( "%3d" , i );				//�ŏ��̈���
	printf( "\n---+---------------------------\n" );	//���ڂ̐�

	for( int i = 1; i <= 9; i++ ) {
		printf( "%2d |" , i );				//�ŏ��̈�s�ڂɂȂ鐔���Əc��
		for( int j = 1; j <= 9; j++ )
			printf( "%3d" , i * j );		//��̊|���Z�̓���
		putchar( '\n' );
	}

	while( 1 ) {
	}

	return 0;
}
