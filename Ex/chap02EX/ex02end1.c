#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int j = 0;
    int k = 0;
    int NISHIN[8];  // �ő�8�r�b�g�܂őΉ�

    printf( "j����� (1����255): " );
    scanf( "%d" , &j );

    while( j > 0 ) {�@//�G
        NISHIN[k] = j % 2;  // mod 2
        j = j / 2;          // div 2
        k++;
    }

    printf( "2�i���i��NISHIN[1����8]�Ȃ̂Ō����͋t�ɂȂ�j: " );
    for( int i = 0; i < k; i++ ) {
        printf( "%d" , NISHIN[i] );
    }
    printf( "\n" );

    while( 1 ) {
    }

    return 0;
}