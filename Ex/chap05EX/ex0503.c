// ���K5-3�@�z��̑S�v�f�̍ő���񐔒l�����߂�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*--- �����lx, y�̍ő���񐔂�ԋp���� ---*/
int gcd( int x , int y ) {
	if( y == 0 )
		return ( x );
	else
		return ( gcd( y , x % y ) );
}

/*--- �v�f��n�̔z��a�̑S�v�f�̍ő���񐔂����߂� ---*/
int gcd_array( const int a[] , int n ) {
	
	if( n == 1 )
		return ( a[0] );
	else if( n == 2 )
		return ( gcd( a[0] , a[1] ) );
	else
		return ( gcd( a[0] , gcd_array( &a[1] , n - 1 ) ) );
		// n �� 3 �̏ꍇ�@���̕����� gcd_array( &a[1] , 2 ) ���n���Ă��ā@if( n == 2 )�̏����� gcd( a[0] , a[1] ) ���g����
		// ���̎������� gcd( a[1] , a[2] ) �Ƃ��Ĉ����Ă���B 
		// ���R�� &a[1] ���擪�̔z��Ƃ��Ĉ����邽�߁Agcd( a[0] , a[1] )�@�����ۂ� gcd( a[1] , a[2] ) �̏ꏊ���w���Ă��܂����߁B
	
	/*
	int result = a[0];
    for (int i = 1; i < n; i++) {
        result = gcd(result, a[i]);
    }
    return result;
	*/

}

int main( void ) {
	int nx;

	printf( "�v�f�� : " );
	scanf( "%d" , &nx );
	int *x = calloc( nx , sizeof( int ) );	// �v�f��nx��int�^�z��x�𐶐�

	for( int i = 0; i < nx; i++ ) {
		printf( "x[%d] : " , i );
		scanf( "%d" , &x[i] );
	}

	printf( "�ő���񐔂�%d�ł��B\n" , gcd_array( x , nx ) );

	free( x );								// �z���j��

	while( 1 ) {
	}

	return 0;
}
