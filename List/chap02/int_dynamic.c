// int�^�̃I�u�W�F�N�g�𓮓I�ɐ������Ĕj��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main( void ) {
	int *x = calloc( 1 , sizeof( int ) );	// OS�⃉���^�C�� ���Ǘ����Ă���q�[�v�̈�̒��̂ǂ����� int�^�I�u�W�F�N�g�𐶐�(�m��)

	if( x == NULL )							//calloc���̈���m�ۂł��Ȃ������Ƃ���NULL������i*�����ŃA�h���X�����Ă���j
		puts( "�L����̊m�ۂɎ��s���܂����B" );
	else {
		*x = 57;
		printf( "*x = %d\n" , *x );
		free( x );						// int�^�I�u�W�F�N�g(�q�[�v��)��j��
	}

	int a[] = { 0,1,2,3,4,5 };
	int *p = a;

	printf("%d", p[2]);



	while( 1 ) {

	}

	return 0;
}
