// �z��̗v�f�̍ő�l�����߂�i�v�f�̒l�͗����Ő����j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*--- �v�f��n�̔z��a�̗v�f�̍ő�l�����߂� ---*/
int maxof( const int a[] , int n ) {
	int max = a[0];				// �ő�l

	for( int i = 1; i < n; i++ )
		if( a[i] > max ) max = a[i];

	return max;
}

int main( void ) {
	int number;			// �l�����z��height�̗v�f��

	printf( "�l�� : " );
	scanf( "%d" , &number );

	int *height = calloc( number , sizeof( int ) );	// �v�f��number�̔z��𐶐�

	srand( time( NULL ) );							// �������痐���̎��������
	
	//time_t now = time(NULL);  // ���݂̎����i�G�|�b�N�b:���萢�E�� 1970�N1��1�� 00:00:00 UTC ����̌o�ߕb�j���擾
    //printf("time(NULL) �̏o�͒l�i�G�|�b�N�b�j: %ld\n", now);
	
	for( int i = 0; i < number; i++ ) {
		height[i] = 100 + rand() % 90;			// 100�`189�̗����𐶐��E���

		printf( "height[%d] = %d\n" , i , height[i] );
	}

	printf( "�ő�l��%d�ł��B\n" , maxof( height , number ) );

	free( height );								// �z��height��j��

	while( 1 ) {

	}

	return 0;

}
