// 演習4-6 int型デックIntDequeue（ソース部）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntDequeueEx0406.h"

//関数の第一引数で、型の IntQueue を IntDequeue に(型の中身は同じなので、Dequeue を用意した方のみ)変更★

/*--- デックの初期化 ---*/
int Initialize( IntDequeue *q , int max ) {
	q->num = q->front = q->rear = 0;
	if( ( q->que = calloc( max , sizeof( int ) ) ) == NULL ) {
		q->max = 0;							// 配列の生成に失敗
		return -1;
	}
	q->max = max;
	return 0;
}

/*--- デックの先頭にデータをエンキュー ---*/
int EnqueFront( IntDequeue *q , int x ) {	//EnqueFrontを新たに追加★
	if( q->num >= q->max )
		return -1;							// デックは満杯
	else {
		q->num++;
		if( --q->front < 0 )
			q->front = q->max - 1;			//要素番号をmaxから一個後ろにずらして値を代入★
		q->que[q->front] = x;
		return 0;
	}
}

/*--- デックの末尾にデータをエンキュー ---*/
int EnqueRear( IntDequeue *q , int x ) {	//Enqueの名前をEnqueRearに(中身は前と同じ)変更★
	if( q->num >= q->max )
		return -1;							// デックは満杯
	else {
		q->num++;
		q->que[q->rear++] = x;
		if( q->rear == q->max )
			q->rear = 0;
		return 0;
	}
}

/*--- デックの先頭からデータをデキュー ---*/
int DequeFront( IntDequeue *q , int *x ) {	//Dequeの名前をDequeFrontに(中身は前と同じ)変更★
	if( q->num <= 0 )						// デックは空
		return -1;
	else {
		q->num--;
		*x = q->que[q->front++];
		if( q->front == q->max )
			q->front = 0;
		return 0;
	}
}

/*--- デックの末尾からデータをデキュー ---*/
int DequeRear( IntDequeue *q , int *x ) {	//DequeRearを新たに追加★
	if( q->num <= 0 )						// デックは空
		return -1;
	else {
		q->num--;
		if( --q->rear < 0 )
			q->rear = q->max - 1;			//要素番号をmaxから一個後ろにずらして、配列の値をxに渡す★
		*x = q->que[q->rear];
		return 0;
	}
}

/*--- デックの先頭からデータをピーク ---*/
int PeekFront( const IntDequeue *q , int *x ) {	//Peekの名前をPeekFrontに(中身は前と同じ)変更★
	if( q->num <= 0 )							// デックは空
		return -1;
	*x = q->que[q->front];
	return 0;
}

/*--- デックの末尾からデータをピーク ---*/
int PeekRear( const IntDequeue *q , int *x ) {	//PeekRearを新たに追加★
	if( q->num <= 0 )							// デックは空
		return -1;
	*x = q->que[q->rear];						//リアの位置の配列の値をxに渡す★
	return 0;
}

/*--- 全データを削除 ---*/
void Clear( IntDequeue *q ) {
	q->num = q->front = q->rear = 0;
}

/*--- デックの容量 ---*/
int Capacity( const IntDequeue *q ) {
	return q->max;
}

/*--- デックに蓄えられているデータ数 ---*/
int Size( const IntDequeue *q ) {
	return q->num;
}

/*--- デックは空か ---*/
int IsEmpty( const IntDequeue *q ) {
	return q->num <= 0;
}

/*--- デックは満杯か ---*/
int IsFull( const IntDequeue *q ) {
	return q->num >= q->max;
}

/*--- デックからの探索 ---*/
int Search( const IntDequeue *q , int x ) {
	int idx;

	for( int i = 0; i < q->num; i++ ) {
		if( q->que[idx = ( i + q->front ) % q->max] == x )
			return idx;		// 添字(インデックス)の探索成功
	}
	return -1;				// 探索失敗
}

/*--- デックからの探索（論理的添字を返却）---*/
int Search2( const IntDequeue *q , int x ) {
	for( int i = 0; i < q->num; i++ ) {
		if( q->que[( i + q->front ) % q->max] == x )
			return i;		// 探索成功
	}
	return -1;				// 探索失敗
}

/*--- 全データの表示 ---*/
void Print( const IntDequeue *q ) {
	for( int i = 0; i < q->num; i++ )
		printf( "%d " , q->que[( i + q->front ) % q->max] );
	putchar( '\n' );
}

/*--- デックの後始末 ---*/
void Terminate( IntDequeue *q ) {
	if( q->que != NULL )
		free( q->que );							// 配列を破棄
	q->max = q->num = q->front = q->rear = 0;
}
