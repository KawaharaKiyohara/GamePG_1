// StructSample.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <iostream>


int main()
{
	int playerHp = 100;		//�v���C���[��HP
	int playerMp = 200;		//�v���C���[��MP
	int playerLv = 10;		//�v���C���[�̃��x��
	int playerAtk = 20;		//�v���C���[�̍U���́B
	int playerDef = 30;		//�v���C���[�̖h��́B

	std::cout << "�v���C���[��HP      " << playerHp << "\n";
	std::cout << "�v���C���[��MP      " << playerMp << "\n";
	std::cout << "�v���C���[��Lv      " << playerLv << "\n";
	std::cout << "�v���C���[�̍U����  " << playerAtk << "\n";
	std::cout << "�v���C���[�̖h���  " << playerDef << "\n";
    return 0;
}

