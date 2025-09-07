// ���K3-8�@bsearch�֐��Ɠ����Ȋ֐�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- base���w���v�f�̑傫����size�ŗv�f����nmemb�̔z�񂩂�key�ƈ�v����v�f��
	  ��r�֐�compar��p���ĂQ���T�� ---*/
void *binsearch( const void *key , const void *base , size_t nmemb , size_t size ,
	int ( *compar )( const void * , const void * ) ) {
	char *x = (char *)base;
	size_t pl = 0;							// �T���͈͂̐擪�̓Y��
	size_t pr = nmemb - 1;					// �@�@�V�@�@�����̓Y��

	if( nmemb > 0 ) {
		while( 1 ) {
			size_t pc = ( pl + pr ) / 2;	// �@�@�V�@�@�����̓Y��
			int comp = compar( (const void *)&x[pc * size] , key );//�w��֐���0��1��-1�͏o��̂�...

			if( comp == 0 )	 				// �T������
				return &x[pc * size];		//0 �� comp �ŋA���Ă�����A�Y���A�h���X��Ԃ�
			else if( pl == pr )
				break;
			else if( comp < 0 )				//�w��֐��̌��ʂɔC����p.102�̗v�̂œY�������炷
				pl = pc + 1;				// �T���͈͂��㔼�ɍi�荞��
			else
				pr = pc - 1;				// �T���͈͂�O���ɍi�荞��
		}
	}

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

int main( void ) {
	int nx , ky;

	puts( "binsearch�֐��ɂ��T��" );
	printf( "�v�f�� : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// �v�f��nx��int�^�z��x�𐶐�

	printf( "�����ɓ��͂��Ă��������B\n" );
	printf( "x[0] : " );
	scanf( "%d" , &x[0] );

	for( int i = 1; i < nx; i++ ) {
		do {
			printf( "x[%d] : " , i );
			scanf( "%d" , &x[i] );
		} while( x[i] < x[i - 1] );		// ��O�̒l������������΍ē���
	}

	printf( "�T���l : " );
	scanf( "%d" , &ky );

	int *p = binsearch(
		&ky ,							// �T���l�ւ̃|�C���^
		x ,								// �z��
		nx ,								// �v�f��
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
