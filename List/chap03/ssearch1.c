// ���`�T��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- �v�f��n�̔z��a����key�ƈ�v����v�f����`�T�� ---*/
int search( const int a[] , int n , int key ) {
	int i = 0;

	while( 1 ) {
		if( i == n )
			return -1;		// �T�����s
		if( a[i] == key )
			return i;		// �T������
		i++;
	}
}

int main( void ) {
	int nx , ky;

	puts( "���`�T��" );
	printf( "�v�f�� : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// �v�f��nx��int�^�z��𐶐�

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}
	printf( "�T���l : " );
	scanf( "%d" , &ky );

	int idx = search( x , nx , ky );		// �z��x����l��ky�̗v�f����`�T��

	if( idx == -1 )
		puts( "�T���Ɏ��s���܂����B" );
	else
		printf( "%d��x[%d]�ɂ���܂��B\n" , ky , idx );

	free( x );							// �z���j��

	while( 1 ) {
	}

	return 0;
}
