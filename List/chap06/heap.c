// �q�[�v�\�[�g
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- a[left]�`a[right]���q�[�v�� ---*/
static void downheap( int a[] , int left , int right ) {
	int temp = a[left];				// ��
	int child;
	int parent;

	// ���̃��[�v�́A�e����q�ւƉ����Ă����܂��idownheap�j
	for( parent = left; parent < ( right + 1 ) / 2; parent = child ) {
		// parent �̍��E�̌̈ʒu�� ���̌v�Z�Ŋ���o����
		int cl = parent * 2 + 1;	// ���̎q
		int cr = cl + 1;			// �E�̎q

		//printf( "p %d : l %d : r %d\n" , parent , cl , cr );// �����ł�����x�z����ǂ̂悤�ɖ؍\���Œǂ��Ă��邩����܂�

		child = ( cr <= right && a[cr] > a[cl] ) ? cr : cl;	// cr <= right �Ŕz����Ɏ��߁A�傫���ق��̎q��I�т܂��i�ő�q�[�v�ɂ��邽�߁j
		if( temp >= a[child] )	// �q�̕����������Ȃ�A���[�v���I��
			break;
		a[parent] = a[child];	// �q�̕����傫���Ȃ�A�e�Ɏq�̒l���R�s�[
	}
	a[parent] = temp;// �Ō�ɐe�̈ʒu�Ɍ��̒l���i�[��z�肵�����́i���������j
}

/*--- �q�[�v�\�[�g ---*/
void heapsort( int a[] , int n ) {

	// �ŏ��ɖ؍\�����q�[�v�������Ă���
	/*
	 ���S�񕪖؂ł́A ( n - 1 ) / 2 �Őe�������w��A���Ɏq��LR�̓Y��������o���Ă��� ( p.259�Ō����Ƃ���̇B�̃m�[�h�ɂ�����)
			[0]
		   /   |
		 [1]   [2]
		/ |    / |
	  [3][4] [5][6]
	*/
	for( int i = ( n - 1 ) / 2; i >= 0; i-- )
		downheap( a , i , n - 1 );

	// �q�[�v�����ς�ł���̂ŁA0�Ԃ�n-1�Ԃɓ���ւ��Ȃ���A�q�[�v�\�[�g���s���Ă���
	for( int i = n - 1; i > 0; i-- ) {	// i > 0 �͓���ւ��ς݂̌������O���Ȃ��珈�����Ă���������
		swap( int , a[0] , a[i] );
		downheap( a , 0 , i - 1 );
	}
}

int main( void ) {
	int nx;

	puts( "�q�[�v�\�[�g" );
	printf( "�v�f�� : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// �v�f��nx��int�^�z��x�𐶐�

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	heapsort( x , nx );	// �z��x���q�[�v�\�[�g

	puts( "�����Ƀ\�[�g���܂����B" );
	for( int i = 0; i < nx; i++ )
		printf( "x[%d] = %d\n" , i , x[i] );

	free( x );			// �z��x��j��

	while( 1 ) {

	}

	return 0;
}
