// ���K3-1�@���`�T���i�ԕ��@�Ffor���j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- �v�f��n�̔z��a����key�ƈ�v����v�f����`�T���i�ԕ��@�j---*/
int search( int a[] , int n , int key ) {
	int i;

	a[n] = key;			// �ԕ���ǉ�

	//---- for���̕ύX�ӏ� ----
	for( i = 0; i < n; i++ )
		if( a[i] == key )
			break;		// ������
	//---- for���̕ύX�ӏ� ----

	return i == n ? -1 : i;
}

int main( void ) {
	int nx , ky;

	puts( "���`�T���i�ԕ��@�j" );
	printf( "�v�f�� : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx + 1 , sizeof( int ) );	// �v�f��(nx + 1)��int�^�z��x�𐶐�

	for( int i = 0; i < nx; i++ ) {			// ���ӁF�l��ǂݍ��ނ̂�nx��
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}
	printf( "�T���l : " );
	scanf( "%d" , &ky );

	int idx = search( x , nx , ky );			// �z��x����l��ky�̗v�f����`�T��

	if( idx == -1 )
		puts( "�T���Ɏ��s���܂����B" );
	else
		printf( "%d��x[%d]�ɂ���܂��B\n" , ky , idx );

	free( x );								// �z��x��j��

	while( 1 ) {
	}

	return 0;
}
