// ���K2-5�@�z��̗v�f�̕��т𔽓]����i�r���o�߂�\���j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- type�^��x��y�̒l������ ---*/
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- �v�f��n�̔z��a�̗v�f�̕��т�\�� ---*/
void ary_print( const int a[] , int n ) {
	for( int i = 0; i < n; i++ )
		printf( "%d " , a[i] );				// ��������ւ���ꂽ���ʂ��o�� ��:52341
	putchar( '\n' );
}

/*--- �v�f��n�̔z��a�̗v�f�̕��т𔽓] ---*/
void ary_reverse( int a[] , int n ) {
	for( int i = 0; i < n / 2; i++ ) {
		ary_print( a , n );
		printf( "a[%d]��a[%d]���������܂��B\n" , i , n - i - 1 );	// �����������I�ɓ���ւ���`���Ă���Ă���Ƃ��� ��:a[0]��a[4]���������܂�
		swap( int , a[i] , a[n - i - 1] );
	}
	ary_print( a , n );
	puts( "���]���I�����܂����B" );
}

int main( void ) {
	int nx;		// �z��x�̗v�f��

	printf( "�v�f���F" );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// �v�f��nx��int�^�z��x�𐶐�

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	ary_reverse( x , nx );					// �z��x�̗v�f�̕��т𔽓]

	printf( "�v�f�̕��т𔽓]���܂����B\n" );
	for( int i = 0; i < nx; i++ )
		printf( "x[%d] = %d\n" , i , x[i] );

	free( x );								// �z��x��j��


	while( 1 ) {
	}

	return 0;
}

