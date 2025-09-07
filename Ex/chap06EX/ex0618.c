// ���K6-18�@�ėp�N�C�b�N�\�[�g�iqsort�֐��ɏ������d�l�j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- x, y�̎w��n�o�C�g�̗̈������ ---*/
static void memswap( void *x , void *y , size_t n ) {
	unsigned char *a = (unsigned char *)x;
	unsigned char *b = (unsigned char *)y;

	for( ; n--/*0�ɂȂ�܂ŌJ��Ԃ�*/; a++ , b++ ) {
		unsigned char c = *a;
		*a = *b;
		*b = c;
	}
}

/*--- �ėp�N�C�b�N�\�[�g�iqsort�֐��ɏ������d�l�j---*/
void q_sort( void *base , size_t nmemb , size_t size ,
			 int ( *compar )( const void * , const void * ) ) {
	if( nmemb > 0 ) {
		size_t pl = 0;					// ���J�[�\��
		size_t pr = nmemb - 1;			// �E�J�[�\��
		size_t pv = nmemb;				// ����
		size_t pt = ( pl + pr ) / 2;	// �����̍X�V�l
		char *v = (char *)base;			// �擪�v�f�ւ̃|�C���^

		do {
			char *x = &v[( pv = pt ) * size];		// pv = pt �̑�����ʂ��� pt �~ size �Ő����ւ̃|�C���^�����߂�(��̎���pv = pt���ĂĂ������C������)
			while( compar( (const void *)&v[pl * size] , x ) < 0 ) pl++;// compar�͂����Ō��߂��������̖��O�� int_cmp���㏑�����ď��������B
																		//int_cmp �Ŕ�r���� -1��1���ς�������̂ŁA��������Ƃ� <0 �Ŕ�r��
																		// ���J�[�\����������菬�����Ԃ͐i�߂�
			
			while( compar( (const void *)&v[pr * size] , x ) > 0 ) pr--;// �ڍׂ͏�Ɠ����Ł@�E�J�[�\�����������傫���Ԃ͖߂�
			if( pl <= pr ) {
				pt = ( pl == pv ) ? pr : ( pr == pv ) ? pl : pv;
				memswap( &v[pl * size] , &v[pr * size] , size );//������ swap( int , a[pl] , a[pr] ); �̊֐��� �� void �ł� swap
				pl++;
				if( pr == 0 )	// ������������0����̃f�N�������g�������(0�𒴂��ď������Ȃ邱�Ƃ͂Ȃ��̂�goto�ŋ������)
					goto QuickRight;
				pr--;
			}
		} while( pl <= pr );

		if( 0 < pr )		q_sort( &v[0] , pr + 1 , size , compar );
	QuickRight:
		if( pl < nmemb - 1 ) q_sort( &v[pl * size] , nmemb - pl , size , compar );
	}
}

/*--- int�^�̔�r�֐��i�����\�[�g�p�j ---*/
int int_cmp( const int *a , const int *b ) {
	if( *a < *b )
		return -1;
	else if( *a > *b )
		return 1;
	else
		return 0;
}

int main( void ) {
	int nx;

	printf( "q_sort�ɂ��\�[�g\n" );
	printf( "�v�f�� : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// �v�f��nx��int�^�z��x�𐶐�

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	q_sort( x ,											// �z��
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
