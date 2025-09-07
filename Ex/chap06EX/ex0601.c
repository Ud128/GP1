// ���K6-1�@�P�������\�[�g�i�擪�����瑖���j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- �P�������\�[�g ---*/
void bubble( int a[] , int n ) {

	/*
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				swap(int, a[j - 1], a[j]);
	}
	*/

	for( int i = n - 1; i > 0; i-- ) {		// i �̓\�[�g�ς݂̓Y���������i�������珇�Ƀ\�[�g�������j
		for( int j = 0; j < i; j++ )		// j �͐擪���� �אڗv�f�̔�r�ƌ����� i �̒��O�܂ŋt�����Ƀ\�[�g��i�܂���
			if( a[j] > a[j + 1] )			// �אڂ���2�̗v�f���r���A�ő�l�𖖔��ɐi�܂���
				swap( int , a[j] , a[j + 1] );
	}
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
