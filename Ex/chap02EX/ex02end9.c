#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 8

int main() {
    char A[SIZE][SIZE] = {
        {' ', '*', '*', '*', '*', '*', '*', ' '},
        {' ', '*', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', '*', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', '*', '*', '*', '*', ' ', ' ', ' '},
        {' ', '*', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', '*', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', '*', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', '*', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    char B[SIZE][SIZE];

    printf( "Aの状態:\n" );
    for( int i = 0; i < SIZE; i++ ) {
        for( int j = 0; j < SIZE; j++ ) {
            printf( "%c " , A[i][j] );
        }
        printf( "\n" );
    }

    // ★ 左に90度回転: B[j][7-i] = A[i][j]
    for( int i = 0; i < SIZE; i++ ) {
        for( int j = 0; j < SIZE; j++ ) {
            B[j][7 - i] = A[i][j];
        }
    }

    printf( "\nBの状態（右に90度回転後）:\n" );
    for( int i = 0; i < SIZE; i++ ) {
        for( int j = 0; j < SI