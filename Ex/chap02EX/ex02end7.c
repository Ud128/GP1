#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    const int n = 5;
    // �z��̏������iTANGO[0] �͎g��Ȃ��j
    char TANGO[][10] = { "orange", "apple", "banana", "grape", "cherry" };

    // �\���i�ړ��O�j
    printf( "�ړ��O:\n" );
    for( int i = 1; i < n; i++ ) {
        printf( "TANGO[%d] = %s\n" , i , TANGO[i] );
    }

    // �� ���̏��������i���ɂ��炷�j
    for( int i = n - 1; i >= 0; i-- ) {
        if( i >= n - 1 )continue;           //���肾�Ƃ�������Ȃ��Ɛ������Ȃ�
        strcpy( TANGO[i + 1] , TANGO[i] );  // TANGO[i] �� TANGO[i+1]
    }

    // �\���i�ړ���j
    printf( "\n�ړ���(TANGO[i] �� TANGO[i+1]):\n" );
    for( int i = 1; i < n; i++ ) {
        printf( "TANGO[%d] = %s\n" , i , TANGO[i] );
    }

    while( 1 ) {
    }

    return 0;
}