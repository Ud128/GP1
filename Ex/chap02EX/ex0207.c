// ���K2-7�@�z��̑S�v�f���R�s�[
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- �v�f��n�̔z��b�̑S�v�f��z��a�ɃR�s�[ ---*/
void ary_copy( int a[] , const int b[] , int n ) {
	for( int i = 0; i < n; i++ )
		a[i] = b[i];
}

int main( void ) {
	int n;		// �z��x��y�̗v�f��

	printf( "�v�f���F" );
	scanf( "%d" , &n );
	int *x = calloc( n , sizeof( int ) );	// �v�f��n��int�^�z��x�𐶐�
	int *y = calloc( n , sizeof( int ) );	// �v�f��n��int�^�z��y�𐶐�

	printf( "%d�̐�������͂��Ă��������B\n" , n );
	for( int i = 0; i < n; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	ary_copy( y , x , n );					// �z��x�̑S�v�f��z��y�ɃR�s�[

	printf( "�z��x�̑S�v�f��z��y�ɃR�s�[���܂����B\n" );
	for( int i = 0; i < n; i++ )
		printf( "y[%d] = %d\n" , i , y[i] );

	free( x );							// �z��x��j��
	free( y );							// �z��y��j��

	while( 1 ) {
	}

	return 0;
}