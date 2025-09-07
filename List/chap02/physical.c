// �g�̌����f�[�^�p�\���̂̔z��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define VMAX	21		// ���͂̍ő�l2.1�~10

/*--- �g�̌����f�[�^�^ ---*/
typedef struct {
	char   name[20];	// ����
	int    height;		// �g��
	double vision;		// ����
} PhysCheck;

/*--- �g���̕��ϒl�����߂� ---*/
double ave_height( const PhysCheck dat[] , int n ) {
	double sum = 0;

	for( int i = 0; i < n; i++ )
		sum += dat[i].height;

	return sum / n;
}

/*--- ���͂̕��z�����߂� ---*/
void dist_vision( const PhysCheck dat[] , int n , int dist[] ) {
	for( int i = 0; i < VMAX; i++ )
		dist[i] = 0;								//dist[] �̊e�v�f�����ׂ� 0�l�ŏ��������܂��B

	for( int i = 0; i < n; i++ )
		if( dat[i].vision >= 0.0 && dat[i].vision <= VMAX / 10.0 )
			dist[(int)( dat[i].vision * 10 )]++;	//���͂�10���|���Z���Ĕz��̃C���f�b�N�X�ԍ�==����1/10(0.1)���w�肵�Ă�
}

int main( void ) {
	PhysCheck x[] = {
		{"AKASAKA Tadao",	162, 0.3},
		{"KATOH Tomiaki",	173, 0.7},
		{"SAITOH Syouji",	175, 2.0},
		{"TAKEDA Shinya",	171, 1.5},
		{"NAGAHAMA Masaki",	168, 0.4},
		{"HAMADA Tetsuaki",	174, 1.2},
		{"MATSUTOMI Akio",	169, 0.8},
	};
	int nx = sizeof( x ) / sizeof( x[0] );		// �l��
	int vdist[VMAX];							// ���͂̕��z

	puts( "������ �g�̌����ꗗ�\ ������" );
	puts( "  ����            �g�� ���� " );
	puts( "----------------------------" );
	for( int i = 0; i < nx; i++ )
		printf( "%-18.18s%4d%5.1f\n" , x[i].name , x[i].height , x[i].vision );//���񂹁A�ő�18�����\��(.18)�̕�����,��4�ŉE��,��5�ŏ����_�ȉ�1���E��

	printf( "\n���ϐg���F%5.1fcm\n" , ave_height( x , nx ) );

	dist_vision( x , nx , vdist );				// ���͂̕��z�����߂�

	printf( "\n���͂̕��z\n" );
	for( int i = 0; i < VMAX; i++ )
		printf( "%3.1f�`�F%2d�l\n" , i / 10.0 , vdist[i] );	//i / 10.0 �Ŏ��͕\�����s���Ă���

	while( 1 ) {
	}

	return 0;
}
