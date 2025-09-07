// 演習4-2 配列共有int型スタックIntStack2（ヘッダ部）

#ifndef ___IntStack2
#define ___IntStack2

enum {StackA, StackB};		//追加 ★

/*--- 配列共有スタックを実現する構造体 ---*/
typedef struct {
	int max;		// スタックの容量
	int ptrA;		// スタックポインタＡ
	int ptrB;		// スタックポインタＢ ★
	int *stk;		// スタック本体（の先頭要素へのポインタ）
} IntStack;

/*--- スタックの初期化 ---*/
int Initialize(IntStack *s, int max);

/*--- スタックにデータをプッシュ ---*/
int Push(IntStack *s, int sw, int x);

/*--- スタックからデータをポップ ---*/
int Pop(IntStack *s, int sw, int *x);

/*--- スタックからデータをピーク ---*/
int Peek(const IntStack *s, int sw, int *x);

/*--- スタックを空にする ---*/
void Clear(IntStack *s, int sw);

/*--- スタックの容量 ---*/
int Capacity(const IntStack *s);

/*--- スタックに積まれているデータ数 ---*/
int Size(const IntStack *s, int sw);

/*--- スタックは空か ---*/
int IsEmpty(const IntStack *s, int sw);

/*--- スタックは満杯か ---*/
int IsFull(const IntStack *s);

/*--- スタックからの探索 ---*/
int Search(const IntStack *s, int sw, int x);

/*--- 全データの表示 ---*/
void Print(const IntStack *s, int sw);

/*--- スタックの後始末 ---*/
void Terminate(IntStack *s);

#endif
