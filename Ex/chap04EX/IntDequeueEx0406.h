// 演習4-6 int型デックIntDequeue（ヘッダ部）

#ifndef ___IntDequeue
#define ___IntDequeue

//IntQueueと中身は全く同じだけど、IntDequeue に名前を変更★

/*--- デックを実現する構造体 ---*/
typedef struct {
	int max;		// デックの容量
	int num;		// 現在のデータ数
	int front;		// 先頭要素カーソル
	int rear;		// 末尾要素カーソル
	int *que;		// デック本体（の先頭要素へのポインタ）
} IntDequeue;

//関数の第一引数で、型の IntQueue を IntDequeue に変更★

/*--- デックの初期化 ---*/
int Initialize( IntDequeue *q , int max );

/*--- デックの先頭にデータをエンキュー ---*/
int EnqueFront( IntDequeue *q , int x );

/*--- デックの末尾にデータをエンキュー ---*/
int EnqueRear( IntDequeue *q , int x );

/*--- デックの先頭からデータをデキュー ---*/
int DequeFront( IntDequeue *q , int *x );

/*--- デックの末尾からデータをデキュー ---*/
int DequeRear( IntDequeue *q , int *x );

/*--- デックの先頭からデータをピーク ---*/
int PeekFront( const IntDequeue *q , int *x );

/*--- デックの末尾からデータをピーク ---*/
int PeekRear( const IntDequeue *q , int *x );

/*--- 全データを削除 ---*/
void Clear( IntDequeue *q );

/*--- デックの容量 ---*/
int Capacity( const IntDequeue *q );

/*--- デック上のデータ数 ---*/
int Size( const IntDequeue *q );

/*--- デックは空か ---*/
int IsEmpty( const IntDequeue *q );

/*--- デックは満杯か ---*/
int IsFull( const IntDequeue *q );

/*--- デックからの探索 ---*/
int Search( const IntDequeue *q , int x );

/*--- デックからの探索（論理的添字を返却）---*/
int Search2( const IntDequeue *q , int x );

/*--- 全データの表示 ---*/
void Print( const IntDequeue *q );

/*--- デックの後始末 ---*/
void Terminate( IntDequeue *q );

#endif
