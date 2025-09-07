// �x���\�[�g
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- �x���\�[�g�i�z��v�f�̒l��0�ȏ�max�ȉ��j---*/
void counting( int a[] , int n , int max ) {
	int *f = calloc( max + 1 , sizeof( int ) );		// �ݐϓx��
	int *b = calloc( n , sizeof( int ) );			// ��Ɨp�ړI�z��

	for( int i = 0; i <= max; i++ ) f[i] = 0;				// [Step0]
	for( int i = 0; i < n; i++ ) f[a[i]]++;					// [Step1]
	for( int i = 1; i <= max; i++ ) f[i] += f[i - 1];		// [Step2]
	for( int i = n - 1; i >= 0; i-- ) b[--f[a[i]]] = a[i];	// [Step3]
	for( int i = 0; i < n; i++ ) a[i] = b[i];				// [Step4]

	free( b );
	free( f );
}

int main( void ) {
	int nx;
	const int max = 100;			// �ő�l

	puts( "�x���\�[�g" );
	printf( "�v�f�� : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// �v�f��nx��int�^�z��x�𐶐�

	printf( "0�`%d�̐�������͂���B\n" , max );
	for( int i = 0; i < nx; i++ ) {
		do {
			printf( "x[%d] : " , i );
			scanf( "%d" , &x[i] );
		} while( x[i] < 0 || x[i] > max );
	}

	counting( x , nx , max );		// �z��x��x���\�[�g

	puts( "�����Ƀ\�[�g���܂����B" );
	for( int i = 0; i < nx; i++ )
		printf( "x[%d] = %d\n" , i , x[i] );

	free( x );						// �z��x��j��

	while( 1 ) {

	}

	return 0;
}
