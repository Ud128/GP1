// ���K3-3�@�z�񒆂̔C�ӂ̒l�ƈ�v����S�v�f�̓Y���𒊏o
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- �z��a���̒l��key�ł���S�v�f�̓Y����idx�Ɋi�[ ---*/
int search_idx( const int a[] , int n , int key , int idx[] ) {
	int count = 0;

	for( int i = 0; i < n; i++ )
		if( a[i] == key )
			idx[count++] = i;
	return count;
}

int main( void ) {
	int nx , ky;

	puts( "���`�T���i�S�v�f��T���j" );
	printf( "�v�f�� : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );		// �v�f��nx��int�^�z��x�𐶐�
	int *idx = calloc( nx , sizeof( int ) );		// �v�f��nx��int�^�z��idx�𐶐�

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}
	printf( "�T���l : " );
	scanf( "%d" , &ky );

	int no = search_idx( x , nx , ky , idx );	// �z��x����l��ky�̑S�v�f����`�T��

	if( no == -1 )
		puts( "��v����v�f�͑��݂��܂���B" );
	else {
		printf( "��v����v�f�͈ȉ���%d�ł��B\n" , no );
		for( int i = 0; i < no; i++ )
			printf( "x[%d] " , idx[i] );
		putchar( '\n' );
	}

	free( x );								// �z��x��j��
	free( idx );								// �z��idx��j��

	while( 1 ) {
	}

	return 0;
}
