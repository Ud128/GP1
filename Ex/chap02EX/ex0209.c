// ���K2-9�@�z��̑S�v�f�̕��т��V���b�t������
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/*--- type�^��x��y�̒l������ ---*/
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- �v�f��n�̔z��a�̑S�v�f�̕��т��V���b�t�� ---*/
void shuffle( int a[] , int n ) {
	srand( time( NULL ) );
	for( int i = n - 1; i > 0; i-- ) {	// �z��a���V���b�t��
		int j = rand() % ( i + 1 );
		if( i != j )
			swap( int , a[i] , a[j] );
	}

	/*
	for (int i = 0; i < n - 1; i++) {	// �O������� ++ �̃o�[�W����
		int j = i + rand() % (n - i);	// i �` n-1 �̒����� j ��I��
		if (i != j)
			swap(int, a[i], a[j]);
	}
	*/
}

int main( void ) {
	int nx;		// �z��x�̗v�f��

	printf( "�v�f���F" );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// �v�f��nx��int�^�z��x�𐶐�

	printf( "%d�̐�������͂��Ă��������B\n" , nx );
	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	shuffle( x , nx );						// �z��x�̗v�f�̕��т��V���b�t��

	printf( "�z��̗v�f�̕��т��V���b�t�����܂����B\n" );
	for( int i = 0; i < nx; i++ )
		printf( "x[%d] = %d\n" , i , x[i] );

	free( x );							// �z��x��j��

	while( 1 ) {
	}

	return 0;
}