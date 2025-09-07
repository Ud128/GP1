// 演習5-10　８王妃問題を非再帰に解く

// 注：本プログラムのコンパイルには"IntStack.h"と"IntStack.c"が必要です。

#include <stdio.h>
#include "IntStack.h"

int flag_a[8];		// 各行に王妃が配置ずみか
int flag_b[15];		// ／対角線に王妃が配置ずみか
int flag_c[15];		// ＼対角線に王妃が配置ずみか
int pos[8];			// 各列の王妃の位置 */

/*--- 盤面（各列の王妃の位置）を出力 ---*/
void print(void)
{
	for (int i = 0; i < 8; i++)
		printf("%2d", pos[i]);
	putchar('\n');
}

/*--- i列目の適当な位置に王妃を配置（非再帰版）---*/
void set(int i)
{
	IntStack jstk;
	Initialize(&jstk, 8);

Start :
	while (1) {
		int j = 0;
		while (1) {
			while (j < 8) {
				if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7]) {
					pos[i] = j;
					if (i == 7)				// 全列に配置終了
						print();
					else {
						flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
						i++;
						Push(&jstk, j);		// i列目の行をプッシュ
						goto Start;
					}
				}
				j++;
			}
			if (--i == -1) return;
			Pop(&jstk, &j);					// i列目の行をポップ
			flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
			j++;
		}
	}
	Terminate(&jstk);
}

int main(void)
{
	for (int i = 0; i <  8; i++)
		flag_a[i] = 0;
	for (int i = 0; i < 15; i++)
		flag_b[i] = flag_c[i] = 0;

	set(0);						// 0列目に配置

	return 0;
}
