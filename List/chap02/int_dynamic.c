// int型のオブジェクトを動的に生成して破棄
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main( void ) {
	int *x = calloc( 1 , sizeof( int ) );	// OSやランタイム が管理しているヒープ領域の中のどこかに int型オブジェクトを生成(確保)

	if( x == NULL )							//callocが領域を確保できなかったときのNULLを見る（*無しでアドレスを見ている）
		puts( "記憶域の確保に失敗しました。" );
	else {
		*x = 57;
		printf( "*x = %d\n" , *x );
		free( x );						// int型オブジェクト(ヒープ側)を破棄
	}

	int a[] = { 0,1,2,3,4,5 };
	int *p = a;

	printf("%d", p[2]);



	while( 1 ) {

	}

	return 0;
}
