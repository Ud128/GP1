// 1,000�ȉ��̑f����񋓁i��R�Łj
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main( void ) {
	int prime[500];							// �f�����i�[����z��
	int ptr = 0;							// ���ɓ���ꂽ�f���̌�
	unsigned long counter = 0;				// �揜�̉�

	prime[ptr++] = 2;						// �Q�͑f���ł���
	prime[ptr++] = 3;						// �R�͑f���ł���

	for( int n = 5; n <= 1000; n += 2 ) {	// ��݂̂�ΏۂƂ���
		int i;
		int flag = 0;

		//n �̕������܂Œ��ׂ�Ώ\��.
		//��F���� n = 49 �̏ꍇ�A7 * 7 = 49 �܂Œ��ׂ�Ώ\��
		for( i = 1; counter++ , prime[i] * prime[i] <= n; i++ ) {
			counter++;
			if( n % prime[i] == 0 ) {		// ����؂��Ƒf���ł͂Ȃ�
				flag = 1;
				break;						// ����ȏ�̌J�Ԃ��͕s�v
			}
		}
		if( !flag )							// �Ō�܂Ŋ���؂�Ȃ�����
			prime[ptr++] = n;				// �z��ɓo�^
	}

	for( int i = 0; i < ptr; i++ )
		printf( "%d\n" , prime[i] );

	printf( "�揜�Z���s�����񐔁F%lu\n" , counter );

	while( 1 ) {
	}

	return 0;
}
