#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int j = 0;
    int k = 0;
    int NISHIN[8];  // 最大8ビットまで対応

    printf( "jを入力 (1から255): " );
    scanf( "%d" , &j );

    while( j > 0 ) {　//エ
        NISHIN[k] = j % 2;  // mod 2
        j = j / 2;          // div 2
        k++;
    }

    printf( "2進数（※NISHIN[1から8]なので向きは逆になる）: " );
    for( int i = 0; i < k; i++ ) {
        printf( "%d" , NISHIN[i] );
    }
    printf( "\n" );

    while( 1 ) {
    }

    return 0;
}