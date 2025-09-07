// 演習4-3 int型キューArrayIntQueue（ヘッダ部）

#ifndef ___ArrayIntQueue
#define ___ArrayIntQueue

/*--- キューを実現する構造体 ---*/
typedef struct {
	int max;		// キューの容量
	int num;		// 現在のデータ数
	int *que;		// キュー本体（の先頭要素へのポインタ）
} ArrayIntQueue;

/*--- キューの初期化 ---*/
int Initialize(ArrayIntQueue *q, int max);

/*--- キューにデータをエンキュー ---*/
int Enque(ArrayIntQueue *q, int x);

/*--- キューからデータをデキュー ---*/
int Deque(ArrayIntQueue *q, int *x);

/*--- キューからデータをピーク ---*/
int Peek(const ArrayIntQueue *q, int *x);

/*--- 全データを削除 ---*/
void Clear(ArrayIntQueue *q);

/*--- キューの容量 ---*/
int Capacity(const ArrayIntQueue *q);

/*--- キュー上のデータ数 ---*/
int Size(const ArrayIntQueue *q);

/*--- キューは空か ---*/
int IsEmpty(const ArrayIntQueue *q);

/*--- キューは満杯か ---*/
int IsFull(const ArrayIntQueue *q);

/*--- キューからの探索 ---*/
int Search(const ArrayIntQueue *q, int x);

/*--- 全データの表示 ---*/
void Print(const ArrayIntQueue *q);

/*--- キューの後始末 ---*/
void Terminate(ArrayIntQueue *q);

#endif
