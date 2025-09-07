// ���K6-19�@�ėp�}�[�W�\�[�g
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *buff;			// ��Ɨp�z��

/*--- �ėp�}�[�W�\�[�g�i���C�����jvoid �ŏ����̂ŏ�Ƀ|�C���^�[��size�|���ŏ����Ȃ����Ă��� ---*/
void __mergesort( char *a , size_t left , size_t right , size_t size ,
				  int ( *compar )( const void * , const void * ) ) {
	if( left < right ) {
		size_t center = ( left + right ) / 2;
		size_t p = 0;
		size_t i;
		size_t j = 0;
		size_t k = left;

		__mergesort( a , left , center , size , compar );		// �O�������}�[�W�\�[�g �Ō�̈����� ��r�֐�m_sort ��n����悤�ɏ���
		__mergesort( a , center + 1 , right , size , compar );	// �㔼�����}�[�W�\�[�g �Ō�̈����� ��r�֐�m_sort ��n����悤�ɏ���

		for( i = left; i <= center; i++ )
			memcpy( &buff[p++ * size] , &a[i * size] , size );

		while( i <= right && j < p )
			memcpy( &a[k++ * size] , compar( (const void *)&buff[j * size] , (const void *)&a[i * size] ) <= 0 ?
					&buff[j++ * size] : &a[i++ * size] , size );

		while( j < p )
			memcpy( &a[k++ * size] , &buff[j++ * size] , size );
	}
}

/*--- �ėp�}�[�W�\�[�g ---*/
void m_sort( void *base , size_t nmemb , size_t size ,
			 int ( *compar )( const void * , const void * ) ) {
	if( nmemb > 0 ) {
		buff = calloc( nmemb , size );

		__mergesort( base , 0 , nmemb - 1 , size , compar );		// �z��S�̂��}�[�W�\�[�g

		free( buff );
	}
}

/*--- int�^�̔�r�֐��i�����\�[�g�p�j ---*/
int int_cmp( const int *a , const int *b ) {
	return *a < *b ? -1 : *a > *b ? 1 : 0;
}

int main( void ) {
	int nx;

	printf( "m_sort�ɂ��\�[�g\n" );
	printf( "�v�f�� : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// �v�f��nx��int�^�z��x�𐶐�

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	m_sort( x ,											// �z��
			nx ,										// �v�f��
			sizeof( int ) ,								// �v�f�̑傫��
			( int ( * )( const void * , const void * ) )int_cmp	// ��r�֐�
	);

	puts( "�����Ƀ\�[�g���܂����B" );
	for( int i = 0; i < nx; i++ )
		printf( "x[%d] = %d\n" , i , x[i] );

	free( x );							// �z��x��j��

	while( 1 ) {
	}

	return 0;
}
