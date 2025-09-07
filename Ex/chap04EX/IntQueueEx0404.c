// int型キューIntQueue（ソース部）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntQueueEx0404.h"

/*--- キューの初期化 ---*/
int Initialize( IntQueue *q , int max ) {
	q->num = q->front = q->rear = 0;
	if( ( q->que = calloc( max , sizeof( int ) ) ) == NULL ) {
		q->max = 0;								// 配列の生成に失敗
		return -1;
	}
	q->max = max;
	return 0;
}

/*--- キューにデータをエンキュー ---*/
int Enque( IntQueue *q , int x ) {
	if( q->num >= q->max )
		return -1;								// キューは満杯
	else {
		q->num++;
		q->que[q->rear++] = x;
		if( q->rear == q->max )
			q->rear = 0;
		return 0;
	}
}

/*--- キューからデータをデキュー ---*/
int Deque( IntQueue *q , int *x ) {
	if( q->num <= 0 )							// キューは空
		return -1;
	else {
		q->num--;
		*x = q->que[q->front++];
		if( q->front == q->max )
			q->front = 0;
		return 0;
	}
}

/*--- キューからデータをピーク ---*/
int Peek( IntQueue *q , int *x ) {
	if( q->num <= 0 )							// キューは空
		return -1;
	*x = q->que[q->front];
	return 0;
}

/*--- 全データを削除 ---*/
void Clear( IntQueue *q ) {
	q->num = q->front = q->rear = 0;
}

/*--- キューの容量 ---*/
int Capacity( const IntQueue *q ) {
	return q->max;
}

/*--- キューに蓄えられているデータ数 ---*/
int Size( const IntQueue *q ) {
	return q->num;
}

/*--- キューは空か ---*/
int IsEmpty( const IntQueue *q ) {
	return q->num <= 0;
}

/*--- キューは満杯か ---*/
int IsFull( const IntQueue *q ) {
	return q->num >= q->max;
}

/*--- キューからの探索 ---*/
int Search( const IntQueue *q , int x ) {
	for( int i = 0; i < q->num; i++ ) {
		int idx;
		if( q->que[idx = ( i + q->front ) % q->max] == x )//検索は代入していない配列の検索を避けるため、frontとiの足し算から　mod max で配列内を検索する
			return idx;		// 添字(インデックス)の探索成功
	}
	return -1;				// 探索失敗
}

/*--- キューからの探索（論理的添字を返却）---*/
int Search2( const IntQueue *q , int x ) {			//演習4-4追加★
	for( int i = 0; i < q->num; i++ ) {
		if( q->que[( i + q->front ) % q->max] == x )//検索のしかたは上のSearchと全く同じだか↓のiで何回検索したかでfrontから何番目かを決めている
			return i;		// 探索成功
	}
	return -1;				// 探索失敗
}

/*--- 全データの表示 ---*/
void Print( const IntQueue *q ) {
	for( int i = 0; i < q->num; i++ )
		printf( "%d " , q->que[( i + q->front ) % q->max] );
	putchar( '\n' );
}

/*--- キューの後始末 ---*/
void Terminate( IntQueue *q ) {
	if( q->que != NULL )
		free( q->que );							// 配列を破棄
	q->max = q->num = q->front = q->rear = 0;
}
