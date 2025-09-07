// �N�C�b�N�\�[�g�i���ǔŁj��r�I�����̂Ȃ��i�΂�ɂ����j������I�Ԃ��߂̍H�v�@*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- x[a], x[b], x[c]���\�[�g�i�����l�̓Y����ԋp�j---*/
int sort3elem( int x[] , int a , int b , int c ) {
	// x[a] �� x[b] (pL,pC)���r���Ax[a] <= x[b] �ɂȂ�悤�ɕ��בւ���
	if( x[b] < x[a] ) swap( int , x[b] , x[a] );
	// x[b] �� x[c] (pC,pR)���r���Ax[b] <= x[c] �ɂȂ�悤�ɕ��בւ���
	if( x[c] < x[b] ) swap( int , x[c] , x[b] );
	// �ēx x[a] �� x[b] (pL,pC)���r���Ax[a] <= x[b] �ɂȂ�悤�ɒ����i�K�v�ȏꍇ�̂݁j
	if( x[b] < x[a] ) swap( int , x[b] , x[a] );
	// �����܂ł� x[a], x[b], x[c] (pL,pC,pR)��3�v�f�͏����ɕ���ł���ix[a] <= x[b] <= x[c]�j
	// �����̒l�� x[b] (pC)�Ȃ̂ŁA�Y�� b ��Ԃ�
	return b;
}

/*--- �N�C�b�N�\�[�g ---*/
void quick( int a[] , int left , int right ) {
	int pl = left;								// ���J�[�\��
	int pr = right;								// �E�J�[�\��
	int m = sort3elem( a , pl , ( pl + pr ) / 2 , pr );  // �擪�E�����E�������\�[�g
	int x = a[m];								// ����(pL,pC,pR���r���������Œ����̒l������������)

	swap( int , a[m] , a[right - 1] );			// �����Ɩ�������Q�Ԗڂ�����
	pl++;										// ���J�[�\�����P�E��
	pr -= 2;									// �E�J�[�\�����Q����

	do {
		while( a[pl] < x ) pl++;	// L�̒l�������̒l��艺��邤���͈ړ��𑱂���
		while( a[pr] > x ) pr--;	// R�̒l�������̒l�����邤���͈ړ��𑱂���
		if( pl <= pr ) {			//L��R�̓Y�����������ĂȂ����LR�̈ʒu�̒l�����ւ���
			swap( int , a[pl] , a[pr] );
			pl++;					//����ւ��ς݂̈ʒu�����щz���A���������
			pr--;					//����ւ��ς݂̈ʒu�����щz���A���������
		}
	} while( pl <= pr );			//L��R�̓Y�����������ĂȂ���΁A�������s��

	if( left < pr )  quick( a , left , pr );
	if( pl < right ) quick( a , pl , right );
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

	quick( x , 0 , nx - 1 );	// �z��x���N�C�b�N�\�[�g

	puts( "�����Ƀ\�[�g���܂����B" );
	for( int i = 0; i < nx; i++ )
		printf( "x[%d] = %d\n" , i , x[i] );

	free( x );					// �z��x��j��

	while( 1 ) {
	}

	return 0;
}
