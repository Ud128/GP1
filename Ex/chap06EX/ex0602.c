// ���K6-2�@�P�������\�[�g�i�\�[�g�ߒ��̏ڍׂ�\���j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- �P�������\�[�g ---*/
void bubble( int a[] , int n ) {
	int ccnt = 0;		// ��r��
	int scnt = 0;		// ������

	for( int i = 0; i < n - 1; i++ ) {
		printf( "�p�X%d�F\n" , i + 1 );
		for( int j = n - 1; j > i; j-- ) {
			for( int m = 0; m < n - 1; m++ )
				printf( "%3d %c" ,
				a[m] , ( m != j - 1 /*�`�F�b�N�͈͊O*/ ) ? ' ' : ( a[j - 1] > a[j] /*�����K�v*/ ) ? '+' : '-');
			printf( "%3d\n" , a[n - 1] );

			ccnt++;
			if( a[j - 1] > a[j] ) {//����
				scnt++;
				swap( int , a[j - 1] , a[j] );
			}
		}
		for( int m = 0; m < n; m++ )
			printf( "%3d  " , a[m] );
		putchar( '\n' );
	}
	printf( "��r��%d��ł����B\n" , ccnt );
	printf( "������%d��ł����B\n" , scnt );
}

int main( void ) {
	int nx;

	puts( "�P�������\�[�g" );
	printf( "�v�f�� : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// �v�f��nx��int�^�z��x�𐶐�

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	bubble( x , nx );						// �z��x��P�������\�[�g

	puts( "�����Ƀ\�[�g���܂����B" );
	for( int i = 0; i < nx; i++ )
		printf( "x[%d] = %d\n" , i , x[i] );

	free( x );							// �z��x��j��

	while( 1 ) {
	}

	return 0;
}
