/// ���K5-7 �n�m�C�̓��i�����𕶎���ŕ\���j
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*--- �~��[1]�`�~��[no]��x������y���ֈړ� ---*/
void move( int no , int x , int y ) {
	char *name[] = { "�`��", "�a��", "�b��" };

	if( no > 1 )
		move( no - 1 , x , 6 - x - y );		//�O���[�v���J�n�����璆�Ԏ���

	printf( "�~��[%d]��%s����%s�ֈړ�\n" , no , name[x - 1] , name[y - 1] );	// ���ړI����

	if( no > 1 )
		move( no - 1 , 6 - x - y , y );		// �O���[�u�𒆊Ԏ�����ړI����
}

int main( void ) {
	int n;		// �~�Ղ̖���

	printf( "�n�m�C�̓�\n�~�Ղ̖����F" );
	scanf( "%d" , &n );

	move( n , 1 , 3 );

	while( 1 ) {

	}

	return 0;
}
