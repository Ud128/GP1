// 演習4-3 int型キューArrayIntQueue（ソース部）

#include <stdio.h>
#include <stdlib.h>
#include "ArrayIntQueue.h"

/*--- キューの初期化 ---*/
int Initialize(ArrayIntQueue *q, int max)
{
	q->num = 0;
	if ((q->que = calloc(max, sizeof(int))) == NULL) {
		q->max = 0;								// 配列の生成に失敗
		return -1;
	}
	q->max = max;
	return 0;
}

/*--- キューにデータをエンキュー ---*/
int Enque(ArrayIntQueue *q, int x)
{
	if (q->num >= q->max)
		return -1;								// キューは満杯
	else {
		q->que[q->num++] = x;
		return 0;
	}
}

/*--- キューからデータをデキュー ---*/
int Deque(ArrayIntQueue *q, int *x)
{
	if (q->num <= 0)							// キューは空
		return -1;
	else {
		*x = q->que[0];
		for (int i = 0; i < q->num - 1; i++)
			q->que[i] = q->que[i + 1];
		q->num--;
		return 0;
	}
}

/*--- キューからデータをピーク ---*/
int Peek(const ArrayIntQueue *q, int *x)
{
	if (q->num <= 0)							// キューは空
		return -1;
	*x = q->que[0];
	return 0;
}

/*--- 全データを削除 ---*/
void Clear(ArrayIntQueue *q)
{
	q->num = 0;
}

/*--- キューの容量 ---*/
int Capacity(const ArrayIntQueue *q)
{
	return q->max;
}

/*--- キューに蓄えられているデータ数 ---*/
int Size(const ArrayIntQueue *q)
{
	return q->num;
}

/*--- キューは空か ---*/
int IsEmpty(const ArrayIntQueue *q)
{
	return q->num <= 0;
}

/*--- キューは満杯か ---*/
int IsFull(const ArrayIntQueue *q)
{
	return q->num >= q->max;
}

/*--- キューからの探索 ---*/
int Search(const ArrayIntQueue *q, int x)
{
	for (int i = 0; i < q->num; i++) {
		if (q->que[i] == x)
			return i;		// 探索成功
	}
	return -1;				// 探索失敗
}

/*--- 全データの表示 ---*/
void Print(const ArrayIntQueue *q)
{
	for (int i = 0; i < q->num; i++)
		printf("%d ", q->que[i]);
	putchar('\n');
}

/*--- キューの後始末 ---*/
void Terminate(ArrayIntQueue *q)
{
	if (q->que != NULL)
		free(q->que);							// 配列を破棄
	q->max = q->num = 0;
}
