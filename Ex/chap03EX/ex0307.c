// ���K3-7�@bsearch�֐��Ɠ����`���̐��`�T���֐�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- base���w���v�f�̑傫����size�ŗv�f����nmemb�̔z�񂩂�key�ƈ�v����v�f��
	  ��r�֐�compar��p���Đ��`�T�� ---*/
void *seqsearch( const void *key , const void *base , size_t nmemb , size_t size ,
	int ( *compar )( const void * , const void * ) ) {
	char *x = (char *)base;

	for( size_t i = 0; i < nmemb; i++ )
		if( !compar( (const void *)&x[i * size] , key ) )
			return ( &x[i * size] );		//�C���f�b�N�X0���猟�����āu!0�v�����if���ŋA���Ă�����A�Y���A�h���X��Ԃ�
	return NULL;							// �T�����s
}

/*--- �������r����֐� ---*/
int int_cmp( const int *a , const int *b ) {
	if( *a < *b )
		return -1;
	else if( *a > *b )
		return 1;
	else
		return 0;
}
/*
//���������������ō���Ă�̂ł���ł�OK
int int_cmp( const int *a , const int *b ) {
	if( *a == *b )
		return 0;
	else
		return 1;
}
*/

int main( void ) {
	int nx , ky;

	puts( "seqsearch�֐��ɂ��T��" );
	printf( "�v�f�� : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// �v�f��nx��int�^�z��x�𐶐�

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	printf( "�T���l : " );
	scanf( "%d" , &ky );

	int *p = seqsearch(
		&ky ,							// �T���l�ւ̃|�C���^
		x ,								// �z��
		nx ,							// �v�f��
		sizeof( int ) ,					// �v�f�̑傫��
		( int ( * )( const void * , const void * ) )int_cmp	// ��r�֐�
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
