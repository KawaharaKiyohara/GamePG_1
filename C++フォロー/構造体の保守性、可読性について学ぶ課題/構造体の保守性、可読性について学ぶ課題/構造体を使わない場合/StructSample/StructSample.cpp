// StructSample.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <iostream>


//�v���C���[�̈ړ������B
void MovePlayer(int& playerPosX, int& playerPosY, int& playerPosZ, int	playerMoveSpeedX, int	playerMoveSpeedY )
{
	playerPosX += playerMoveSpeedX;
	playerPosY += playerMoveSpeedY;
}
//�v���C���[�̃p�����[�^��\���B
void DispPlayerParameter( int playerHp, int playerMp, int playerLv, int playerAtk, int playerDef, int playerPosX, int playerPosY, int playerPosZ, int	playerMoveSpeedX, int	playerMoveSpeedY )
{
	std::cout << "�v���C���[��HP" << playerHp << "\n";
	std::cout << "�v���C���[��MP" << playerMp << "\n";
	std::cout << "�v���C���[�̃��x��" << playerLv << "\n";
	std::cout << "�v���C���[�̍U����" << playerAtk << "\n";
	std::cout << "�v���C���[�̖h���" << playerDef << "\n";
	std::cout << "�v���C���[��X���W"  << playerPosX << "\n";
	std::cout << "�v���C���[��Y���W" << playerPosY << "\n";
	std::cout << "�v���C���[��Z���W" << playerPosZ << "\n";
	std::cout << "�v���C���[��X�����ւ̈ړ����x" << playerMoveSpeedX << "\n";
	std::cout << "�v���C���[��Y�����ւ̈ړ����x" << playerMoveSpeedY << "\n\n";
}
//���C���֐��B
int main()
{
	int 	playerHp 			= 100;		//�v���C���[��HP
	int 	playerMp 			= 200;		//�v���C���[��MP
	int 	playerLv 			= 10;		//�v���C���[�̃��x��
	int 	playerAtk 			= 20;		//�v���C���[�̍U���́B
	int 	playerDef 			= 30;		//�v���C���[�̖h��́B
	int 	playerPosX 			= 0;		//�v���C���[��X���W�B
	int 	playerPosY 			= 0;		//�v���C���[��Y���W�B
	int		playerPosZ 			= 0;		//�v���C���[��Z���W�B
	int		playerMoveSpeedX 	= 2;		//�v���C���[��X�����ւ̈ړ����x�B
	int		playerMoveSpeedY 	= 1;		//�v���C���[��Y�����ւ̈ړ����x�B
	
	//�v���C���[�̃p�����[�^��\���B
	DispPlayerParameter( playerHp, playerMp, playerLv, playerAtk, playerDef, playerPosX, playerPosY, playerPosZ, playerMoveSpeedX, playerMoveSpeedY );
	//�v���C���[���ړ��B
	MovePlayer(playerPosX, playerPosY, playerPosZ, playerMoveSpeedX, playerMoveSpeedY);
	//�ړ���̃v���C���[�̃p�����[�^��\������B
	DispPlayerParameter(playerHp, playerMp, playerLv, playerAtk, playerDef, playerPosX, playerPosY, playerPosZ, playerMoveSpeedX, playerMoveSpeedY );
	return 0;
}

