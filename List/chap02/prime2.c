// 1,000�ȉ��̑f����񋓁i��Q�Łj
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main( void ) {
	int prime[500];							// �f�����i�[����z��
	int ptr = 0;							// ���ɓ���ꂽ�f���̌�
	unsigned long counter = 0;				// ���Z�̉�

	prime[ptr++] = 2;						// �Q�͑f���ł���

	for( int n = 3; n <= 1000; n += 2 ) {	// ��݂̂�ΏۂƂ���prime�z���for�ň�C�ɍ��
		int i;
		for( i = 1; i < ptr; i++ ) {		// ���ɓ���ꂽ�f���Ŋ���
			counter++;
			if( n % prime[i] == 0 )			// ����؂��Ƒf���ł͂Ȃ�
				break;						// ����ȏ�̌J�Ԃ��͕s�v
		}
		if( ptr == i )						// �Ō�܂Ŋ���؂�Ȃ�����
			prime[ptr++] = n;				// �z��ɓo�^
	}

	for( int i = 0; i < ptr; i++ )			//�Ō��prim�z��̒��g����C�ɏo��
		printf( "%d\n" , prime[i] );

	printf( "���Z���s�����񐔁F%lu\n" , counter );

	while( 1 ) {
	}

	return 0;
}
