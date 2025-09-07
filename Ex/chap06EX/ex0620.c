// ���K6-20�@�q�[�v�\�[�g�i�\�[�g�ߒ��̖؂�\���j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 2��n������߂� ---*/
static int pow2( int n ) {
	int k = 1;

	while( n-- )
		k *= 2;
	return ( k );
}

/*--- �q�[�v��\�� ---*/
static void disp_heap( int a[] , int n ) {
	int i , w , level;
	int height = 1;		// �؂̍���

	i = n;
	while( i /= 2 )
		height++;

	i = 0;
	w = 1;
	for( level = 0; level < height; level++ ) {
		int k;
		printf( "%*s" , pow2( height - level ) - 2 , "" );
		for( k = 0; k < w; k++ ) {
			printf( "%02d" , a[i++] );
			if( i >= n ) goto Exit;
			printf( "%*s" , pow2( height - level + 1 ) - 2 , "" );
		}
		putchar( '\n' );

		printf( "%*s" , pow2( height - level ) - 3 , "" );
		for( k = 0; k < w; k++ ) {
			if( 2 * k + i < n ) printf( "�^" );
			if( 2 * k + i + 1 < n ) printf( "�_" );
			printf( "%*s" , pow2( height - level + 1 ) - 4 , "" );
		}
		putchar( '\n' );
		w *= 2;
	}
Exit:
	putchar( '\n' );
	putchar( '\n' );
}

/*--- a[left]�`a[right]���q�[�v�� ---*/
static void downheap( int a[] , int left , int right ) {
	int temp = a[left];				// ��
	int child;
	int parent;

	for( parent = left; parent < ( right + 1 ) / 2; parent = child ) {
		int cl = parent * 2 + 1;	// ���̎q
		int cr = cl + 1;			// �E�̎q
		child = ( cr <= right && a[cr] > a[cl] ) ? cr : cl;	// �傫���ق��̎q
		if( temp >= a[child] )
			break;
		a[parent] = a[child];
	}
	a[parent] = temp;
}

/*--- �q�[�v�\�[�g�i�\�[�g�ߒ��̖؂�\���j---*/
void heapsort( int a[] , int n ) {
	int i;

	puts( "�z����q�[�v�����܂��B\n" );
	for( i = ( n - 1 ) / 2; i >= 0; i-- ) {
		disp_heap( a , n );
		downheap( a , i , n - 1 );
	}

	// �� �ǉ��F�q�[�v��������̕\��
	puts( "�q�[�v�������������z�� �F\n" );
	disp_heap( a , n );

	puts( "�q�[�v�����ƂɃ\�[�g���s���܂��B\n" );
	for( i = n - 1; i > 0; i-- ) {
		swap( int , a[0] , a[i] );
		disp_heap( a , n );
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
