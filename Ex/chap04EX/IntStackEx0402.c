// 演習4-2 配列共有int型スタックIntStack2（ソース部）
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntStackEx0402.h"

/*--- スタックの初期化 ---*/
int Initialize( IntStack *s , int max ) {
	s->ptrA = 0;
	if( ( s->stk = calloc( max , sizeof( int ) ) ) == NULL ) {
		s->max = 0;								// 配列の生成に失敗
		s->ptrB = 0;							//失敗し、使用する事もないので0を追加★
		return -1;
	}
	s->ptrB = max - 1;							//配列の生成に成功したので配列の後列にBの添字(インデックス)を指定★
	s->max = max;
	return 0;
}

/*--- スタックにデータをプッシュ ---*/
int Push( IntStack *s , int sw , int x ) {
	if( s->ptrA >= s->ptrB + 1 )				// スタックは満杯　if( s->ptr >= s->max ) --> if( s->ptrA >= s->ptrB + 1 ) Bの位置がmaxになるのでこのように指定★
		return -1;

	switch( sw ) {
		case StackA: s->stk[s->ptrA++] = x;  break;//スタックAが指定されたとき、こちらが動く★
		case StackB: s->stk[s->ptrB--] = x;  break;//スタックBが指定されたとき、こちらが動く(デクリメントで添字をスライドさせる)★
	}
	return 0;
}

/*--- スタックからデータをポップ ---*/
int Pop( IntStack *s , int sw , int *x ) {
	switch( sw ) {								// 追加★
		case StackA:
		if( s->ptrA <= 0 )						// スタックは空
			return -1;
		*x = s->stk[--s->ptrA];
		break;

		case StackB:
		if( s->ptrB >= s->max - 1 )				// スタックは空
			return -1;
		*x = s->stk[++s->ptrB];
		break;
	}
	return 0;
}

/*--- スタックからデータをピーク ---*/
int Peek( const IntStack *s , int sw , int *x ) {
	switch( sw ) {								// 変更★
		case StackA:
		if( s->ptrA <= 0 )						// スタックは空
			return -1;
		*x = s->stk[s->ptrA - 1];
		break;

		case StackB:			//スタックBの機能を追加★
		if( s->ptrB >= s->max - 1 )				// スタックは空
			return -1;
		*x = s->stk[s->ptrB + 1];
		break;
	}
	return 0;
}

/*--- スタックを空にする ---*/
void Clear( IntStack *s , int sw ) {
	switch( sw ) {								// 変更★
		case StackA: s->ptrA = 0;			break;
		case StackB: s->ptrB = s->max - 1;	break;//スタックBの機能を追加★
	}
}

/*--- スタックの容量 ---*/
int Capacity( const IntStack *s ) {
	return s->max;
}

/*--- スタックに積まれているデータ数 ---*/
int Size( const IntStack *s , int sw ) {
	return ( sw == StackA ) ? s->ptrA : s->max - s->ptrB - 1;// 変更★
}

/*--- スタックは空か ---*/
int IsEmpty( const IntStack *s , int sw ) {
	return ( sw == StackA ) ? ( s->ptrA <= 0 ) : ( s->ptrB >= s->max - 1 );// 変更★
}

/*--- スタックは満杯か ---*/
int IsFull( const IntStack *s ) {
	return s->ptrA >= s->ptrB + 1;	// 変更★
}

/*--- スタックからの探索 ---*/
int Search( const IntStack *s , int sw , int x ) {
	switch( sw ) {				// 変更★
		case StackA:
		for( int i = s->ptrA - 1; i >= 0; i-- )		// 頂上→底に線形探索
			if( s->stk[i] == x )
				return i;		// 探索成功
		return -1;				// 探索失敗

		case StackB:			//スタックBの機能を追加★
		for( int i = s->ptrB + 1; i < s->max; i++ )	// 頂上→底に線形探索
			if( s->stk[i] == x )
				return i;		// 探索成功
		return -1;				// 探索失敗
	}
}

/*--- 全データの表示 ---*/
void Print( const IntStack *s , int sw ) {
	switch( sw ) {				// 変更★
		case StackA:
		for( int i = 0; i < s->ptrA; i++ )			// 底→頂上に走査
			printf( "%d " , s->stk[i] );
		break;

		case StackB:			//スタックBの機能を追加★
		for( int i = s->max - 1; i > s->ptrB; i-- )	// 底→頂上に走査
			printf( "%d " , s->stk[i] );
		break;
	}
	putchar( '\n' );
}

/*--- スタックの後始末 ---*/
void Terminate( IntStack *s ) {
	if( s->stk != NULL )
		free( s->stk );				// 配列を破棄
	s->max = s->ptrA = s->ptrB = 0;	// 変更★
}
