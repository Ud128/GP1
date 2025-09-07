#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    const int n = 5;
    // 配列の初期化（TANGO[0] は使わない）
    char TANGO[][10] = { "orange", "apple", "banana", "grape", "cherry" };

    // 表示（移動前）
    printf( "移動前:\n" );
    for( int i = 1; i < n; i++ ) {
        printf( "TANGO[%d] = %s\n" , i , TANGO[i] );
    }

    // ★ 問題の処理部分（後ろにずらす）
    for( int i = n - 1; i >= 0; i-- ) {
        if( i >= n - 1 )continue;           //お題だとこれを入れないと成立しない
        strcpy( TANGO[i + 1] , TANGO[i] );  // TANGO[i] → TANGO[i+1]
    }

    // 表示（移動後）
    printf( "\n移動後(TANGO[i] → TANGO[i+1]):\n" );
    for( int i = 1; i < n; i++ ) {
        printf( "TANGO[%d] = %s\n" , i , TANGO[i] );
    }

    while( 1 ) {
    }

    return 0;
}