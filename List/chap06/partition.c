// �z��̕���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- �z��𕪊����� ---*/
void partition( int a[] , int n ) {
	int pl = 0;			// ���J�[�\��
	int pr = n - 1;		// �E�J�[�\��
	int x = a[n / 2];	// �����͒����̗v�f

	do {
		while( a[pl] < x ) pl++;	// L�̒l�������̒l��艺��邤���͈ړ��𑱂���
		while( a[pr] > x ) pr--;	// R�̒l�������̒l�����邤���͈ړ��𑱂���
		if( pl <= pr ) {			//L��R�̓Y�����������ĂȂ����LR�̈ʒu�̒l�����ւ���
			swap( int , a[pl] , a[pr] );
			pl++;					//����ւ��ς݂̈ʒu�����щz���A���������
			pr--;					//����ւ��ς݂̈ʒu�����щz���A���������
		}
	} while( pl <= pr );			//L��R�̓Y�����������ĂȂ���΁A�������s��

	printf( "�����̒l��%d�ł��B\n" , x );

	printf( "�����ȉ��̃O���[�v\n" );			// �����ȉ��̃O���[�v
	for( int i = 0; i <= pl - 1; i++ )			// a[0] �` a[pl - 1]
		printf( "%d " , a[i] );
	putchar( '\n' );

	if( pl > pr + 1 ) {
		printf( "�����ƈ�v����O���[�v\n" );	// �����Ɠ����O���[�v
		for( int i = pr + 1; i <= pl - 1; i++ )	// a[pr + 1] �` a[pl - 1]
			printf( "%d " , a[i] );
		putchar( '\n' );
	}

	printf( "�����ȏ�̃O���[�v\n" );			// �����ȏ�̃O���[�v
	for( int i = pr + 1; i < n; i++ )			// a[pr + 1] �` a[n - 1]
		printf( "%d " , a[i] );
	putchar( '\n' );
}

int main( void ) {
	int nx;

	puts( "�z��𕪊����܂��B" );
	printf( "�v�f�� : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// �v�f��nx��int�^�z��x�𐶐�

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	partition( x , nx );					// �z��x�𕪊�

	free( x );							// �z��x��j��

	while( 1 ) {
	}

	return 0;
}
