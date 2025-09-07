// ���K6-14�@�N�C�b�N�\�[�g�i�v�f�������������̃O���[�v��D��I�ɕ����F�ċA�Łj
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- �N�C�b�N�\�[�g�i�v�f�������������̃O���[�v��D��I�ɕ����j---*/
void quick( int a[] , int left , int right ) {
	int pl = left;				// ���J�[�\��
	int pr = right;				// �E�J�[�\��
	int x = a[( pl + pr ) / 2];	// �����͒����̗v�f

	do {
		while( a[pl] < x ) pl++;	// L�̒l�������̒l��艺��邤���͈ړ��𑱂���
		while( a[pr] > x ) pr--;	// R�̒l�������̒l�����邤���͈ړ��𑱂���
		if( pl <= pr ) {			//L��R�̓Y�����������ĂȂ����LR�̈ʒu�̒l�����ւ���
			swap( int , a[pl] , a[pr] );
			pl++;					//����ւ��ς݂̈ʒu�����щz���A���������
			pr--;					//����ւ��ς݂̈ʒu�����щz���A���������
		}
	} while( pl <= pr );			//L��R�̓Y�����������ĂȂ���΁A�������s��

	//left ~ pr �� �����̃O���[�v:pl ~ right �� �E���̃O���[�v
	//�����O���[�v�̕����v�f�������Ȃ����H
	if( pr - left < right - pl ) {
		// ���������Ȃ��̂ŁA��ɍ�������
		if( left < pr ) quick( a , left , pr );		//if( left < pr ) �Ń\�[�g���I����Ă��Ȃ����Ƃ��m�F�A���s
		if( pl < right ) quick( a , pl , right );	//if( pl < right )�Ń\�[�g���I����Ă��Ȃ����Ƃ��m�F�A���s
	}
	else {
		// �E�������Ȃ��̂ŁA��ɉE������
		if( pl < right ) quick( a , pl , right );	//if( pl < right )�Ń\�[�g���I����Ă��Ȃ����Ƃ��m�F�A���s
		if( left < pr ) quick( a , left , pr );		//if( left < pr ) �Ń\�[�g���I����Ă��Ȃ����Ƃ��m�F�A���s
	}

	/*
	//��̃R�[�h�Ő�������Ɓ@pl <-> left �@pl <-> left �֐��̏㉺�̈��������ւ��Ă�A�������c�ɓ���ւ��ď����̏��Ԃ����ւ��Ă�悤�ȏ���
	if( pr - left < right - pl ) {
		swap( int , pl , left );
		swap( int , pl , left  );
	}
	if( left < pr )  quick( a , left , pr );//���ۂ�pr�J�[�\����0�ɓ͂��܂ōċA�I�ɌJ��Ԃ�
	if( pl < right ) quick( a , pl , right );//���ۂ�pl�J�[�\����n-1�ɓ͂��܂ōċA�I�ɌJ��Ԃ�
	*/

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
