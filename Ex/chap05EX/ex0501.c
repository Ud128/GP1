// ���K5-1�@�K��l���ċA�I�ɋ��߂�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*--- �����ln�̊K���ԋp ---*/
int factorial( int n ) {
	int fact = 1;

	while( n > 1 )
		fact *= n--;

	/*
	4�̊K������߂��
	while(n > 1) {
		fact *= n;  // 1���: fact = 1 * 4 = 4
		n--;        // n = 3
		fact *= n;  // 2���: fact = 4 * 3 = 12
		n--;        // n = 2
		fact *= n;  // 3���: fact = 12 * 2 = 24
		n--;        // n = 1 �� ���[�v�I��
	}
	return fact;  // �� 24
	*/


	/*
	//�������ɂ������肩��
	for (int i = 1; i <= n; i++) {
		fact *= i;  // fact = fact �~ i;
	}
	*/

	return fact;
}

int main( void ) {
	int x;

	printf( "��������͂���F" );
	scanf( "%d" , &x );

	printf( "%d�̊K���%d�ł��B\n" , x , factorial( x ) );

	while( 1 ) {
	}

	return 0;
}
