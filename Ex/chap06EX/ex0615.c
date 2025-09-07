// ���K6-15�@�N�C�b�N�\�[�g�i���ǔŁF�v�f��9�ȉ��͒P���}���\�[�g�j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- x[a], x[b], x[c]���\�[�g�i�����l�̃C���f�b�N�X��ԋp�j---*/
int sort3elem( int x[] , int a , int b , int c ) {
	if( x[b] < x[a] ) swap( int , x[b] , x[a] );
	if( x[c] < x[b] ) swap( int , x[c] , x[b] );
	if( x[b] < x[a] ) swap( int , x[b] , x[a] );
	return b;
}

/*--- �P���}���\�[�g ---*/
void insertion( int a[] , int n ) {
	for( int i = 1; i < n; i++ ) {
		int tmp = a[i];
		int j;
		for( j = i; j > 0 && a[j - 1] > tmp; j-- )
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}

/*--- �N�C�b�N�\�[�g ---*/
void quick( int a[] , int left , int right ) {
	if( right - left < 9 )//�O���[�v�̗v�f��9�ȉ�
		insertion( &a[left] , right - left + 1 );		//�P���}���\�[�g
	else {
		int pl = left;									// ���J�[�\��
		int pr = right;									// �E�J�[�\��
		int m = sort3elem( a , pl , ( pl + pr ) / 2 , pr );	// �擪�E�����E�������\�[�g
		int x = a[m];									// ����

		swap( int , a[m] , a[right - 1] );				// �����Ɩ�������Q�Ԗڂ�����
		pl++;											// ���J�[�\�����P�E��
		pr -= 2;										// �E�J�[�\�����Q����

		do {
			while( a[pl] < x ) pl++;
			while( a[pr] > x ) pr--;
			if( pl <= pr ) {
				swap( int , a[pl] , a[pr] );
				pl++;
				pr--;
			}
		} while( pl <= pr );

		if( pr - left < right - pl ) {
			swap( int , pl , left );
			swap( int , pr , right );
		}
		if( left < pr )  quick( a , left , pr );
		if( pl < right ) quick( a , pl , right );
	}
}

int main( void ) {
	int nx;

	puts( "�N�C�b�N�\�[�g" );
	printf( "�v�f�� : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// �v�f��nx��int�^�z��x�𐶐�

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	quick( x , 0 , nx - 1 );				// �z��x���N�C�b�N�\�[�g

	puts( "�����Ƀ\�[�g���܂����B" );
	for( int i = 0; i < nx; i++ )
		printf( "x[%d] = %d\n" , i , x[i] );

	free( x );							// �z��x��j��

	while( 1 ) {
	}

	return 0;
}
