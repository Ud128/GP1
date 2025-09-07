// ���K3-6�@bsearch�֐��𗘗p�����~���ɕ���long�^�z�񂩂�̒T��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- �������r����֐��ilong�^�̍~���p�j---*/
int long_cmpr( const long *a , const long *b ) {
	if( *a < *b )
		return 1;
	else if( *a > *b )
		return -1;
	else
		return 0;
}

int main( void ) {
	int nx;
	long ky;

	puts( "bsearch�֐��ɂ��T��" );
	printf( "�v�f�� : " );
	scanf( "%d" , &nx );
	long *x = calloc( nx , sizeof( long ) );	// �v�f��nx��long�^�z��x�𐶐�

	printf( "�~���ɓ��͂��Ă��������B\n" );

	printf( "x[0] : " );
	scanf( "%ld" , &x[0] );

	for( int i = 1; i < nx; i++ ) {
		do {
			printf( "x[%d] : " , i );
			scanf( "%ld" , &x[i] );
		} while( x[i] > x[i - 1] );		// ��O�̒l�����傫����΍ē���
	}

	printf( "�T���l : " );
	scanf( "%d" , &ky );

	long *p = bsearch(
		&ky ,							// �T���l�ւ̃|�C���^
		x ,								// �z��
		nx ,								// �v�f��
		sizeof( int ) ,					// �v�f�̑傫��
		( int ( * )( const void * , const void * ) )long_cmpr	// ��r�֐�
	);

	if( p == NULL )
		puts( "�T���Ɏ��s���܂����B" );
	else
		printf( "%d��x[%d]�ɂ���܂��B\n" , ky , (int)( p - x ) );

	free( x );							// �z��x��j��

	while( 1 ) {
	}

	return 0;
}
