// 1,000�ȉ��̑f����񋓁i��P�Łj
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main( void ) {
	unsigned long counter = 0;	// ���Z�̉�

	
	for( int n = 2; n <= 1000; n++ ) {
		int i;
		for( i = 2; i < n; i++ ) {	//���Z��n�Ɠ����ɂȂ�܂ōs�킭�Ă�����(�����܂ōs���Ă����ʂ͓���)
			counter++;
			if( n % i == 0 )		// ����؂��Ƒf���ł͂Ȃ�
				break;				// ����؂�鎖��������΂���ȏ�̌J�Ԃ��͕s�v
		}
		if( n == i )				// 2�܂ŉ��Z�������A�Ō�܂Ŋ���؂�Ȃ����� ��
			printf( "%d\n" , n );
	}
	
	/*
	�Љ��Ă�̂��Љ�͂��Ȃ��Ă���
	for( int n = 2; n <= 1000; n++ ) {
		int isPrime = 1;  // �f���Ɖ���
		for( int i = 2; i * i <= n; i++ ) {
			counter++;
			if( n % i == 0 ) {
				isPrime = 0;  // ����؂ꂽ �� �f������Ȃ�
				break;
			}
		}
		if( isPrime )
			printf( "%d\n" , n );
	}
	*/
	/*
	//����2��т� p.71 �ŏЉ��Ă�̂��Љ�͂��Ȃ��Ă���
	printf( "2\n" );  // �ŏ���2���o�́i�B��̋����̑f���j
	for( int n = 3; n <= 1000; n += 2 ) {  // ��̂݃`�F�b�N
		int i;
		for( i = 3; i < n; i += 2 ) {
			counter++;
			if( n % i == 0 )		// ����؂��Ƒf���ł͂Ȃ��@
				break;				// ����؂�鎖��������΂���ȏ�̌J�Ԃ��͕s�v
		}
		if( n == i )				// �Ō�܂Ŋ���؂�Ȃ������A
			printf( "%d\n" , n );
	}
	*/
	printf( "���Z���s�����񐔁F%lu\n" , counter );

	while( 1 ) {
	}

	return 0;
}
