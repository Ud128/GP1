// ���K6-6�@�o�����o�u���\�[�g�i�V�F�[�J�[�\�[�g�j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- �o�����o�u���\�[�g�i�V�F�[�J�[�\�[�g�j---*/
void shaker( int a[] , int n ) {
	int left = 0;			// �����̖��\�[�g�͈͂̐擪�̓Y��
	int right = n - 1;		// �E���̖��\�[�g�͈̖͂����̓Y��
	int last = right;		// �Ō�Ɍ��������������ʒu���L�^����

	while( left < right ) { //�E����S�z��`�F�b�N���ē���ւ����N�����ʒu�A������S�z��`�F�b�N���ē���ւ����N�����ʒu���������Ă��Ȃ�������A
							//�݂��ɑO���̃\�[�g�`�F�b�N���ς�ł��܂��Ă�Ƃ������Ȃ̂ŁA����ȏ�̏������s�v�ƂȂ�A�\�[�g����������

		// ������ �E���獶��( <-- )�̔�r�E�����i�傫���l�����ցj
		for( int j = right; j > left; j-- ) {
			if( a[j - 1] > a[j] ) {
				swap( int , a[j - 1] , a[j] );	// �אڗv�f���r���Č���
				last = j;						// �Ō�Ɍ��������������ʒu���L�^
			}
		}
		left = last;							// �����̋��E���X�V�i����ȑO�̕����͂��łɐ���ς݁j

		// ������ ������E��( --> )�̔�r�E�����i�������l��O�ցj
		for( int j = left; j < right; j++ ) {
			if( a[j] > a[j + 1] ) {
				swap( int , a[j] , a[j + 1] );	// �אڗv�f���r���Č���
				last = j;						// �Ō�Ɍ��������������ʒu���L�^
			}
		}
		right = last;							// �E���̋��E���X�V�i����ȍ~�̕����͂��łɐ���ς݁j
	}

}

int main( void ) {
	int nx;

	puts( "�o�����o�u���\�[�g" );
	printf( "�v�f�� : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// �v�f��nx��int�^�z��x�𐶐�

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	shaker( x , nx );						// �z��x��o�����o�u���\�[�g

	puts( "�����Ƀ\�[�g���܂����B" );
	for( int i = 0; i < nx; i++ )
		printf( "x[%d] = %d\n" , i , x[i] );

	free( x );							// �z��x��j��

	while( 1 ) {
	}

	return 0;
}
