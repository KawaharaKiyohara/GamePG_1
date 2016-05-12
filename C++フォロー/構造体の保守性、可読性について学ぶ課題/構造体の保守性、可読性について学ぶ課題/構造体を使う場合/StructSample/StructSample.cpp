// StructSample.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <iostream>


//�v���C���[�̍\���́B
struct Player{
	int 	hp ;			//HP
	int 	mp ;			//MP
	int 	lv ;			//���x��
	int 	atk ;			//�U���́B
	int 	def ;			//�h��́B
	int 	posX ;			//X���W�B
	int 	posY ;			//Y���W�B
	int		posZ ;			//Z���W�B
	int		moveSpeedX;		//X�����ւ̈ړ����x�B
	int		moveSpeedY;		//Y�����ւ̈ړ����x�B
};

//�v���C���[�̈ړ������B
void MovePlayer(Player& player )
{
	player.posX += player.moveSpeedX;
	player.posY += player.moveSpeedY;
}
//�v���C���[�̃p�����[�^��\���B
void DispPlayerParameter( Player player )
{
	std::cout << "�v���C���[��HP" << player.hp << "\n";
	std::cout << "�v���C���[��MP" << player.mp << "\n";
	std::cout << "�v���C���[�̃��x��" << player.lv << "\n";
	std::cout << "�v���C���[�̍U����" << player.atk << "\n";
	std::cout << "�v���C���[�̖h���" << player.def << "\n";
	std::cout << "�v���C���[��X���W"  << player.posX << "\n";
	std::cout << "�v���C���[��Y���W" << player.posY << "\n";
	std::cout << "�v���C���[��Z���W" << player.posZ << "\n";
	std::cout << "�v���C���[��X�����ւ̈ړ����x" << player.moveSpeedX << "\n";
	std::cout << "�v���C���[��Y�����ւ̈ړ����x" << player.moveSpeedY << "\n\n";
}
//���C���֐��B
int main()
{
	Player player;
	player.hp 			= 100;		//�v���C���[��HP
	player.mp 			= 200;		//�v���C���[��MP
	player.lv 			= 10;		//�v���C���[�̃��x��
	player.atk 			= 20;		//�v���C���[�̍U���́B
	player.def 			= 30;		//�v���C���[�̖h��́B
	player.posX 		= 0;		//�v���C���[��X���W�B
	player.posY 		= 0;		//�v���C���[��Y���W�B
	player.posZ 		= 0;		//�v���C���[��Z���W�B
	player.moveSpeedX 	= 2;		//�v���C���[��X�����ւ̈ړ����x�B
	player.moveSpeedY 	= 1;		//�v���C���[��Y�����ւ̈ړ����x�B
	
	//�v���C���[�̃p�����[�^��\���B
	DispPlayerParameter( player );
	//�v���C���[���ړ��B
	MovePlayer( player );
	//�ړ���̃v���C���[�̃p�����[�^��\������B
	DispPlayerParameter( player );
	return 0;
}

