// FunctionSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	//A�N���X�̕��ϓ_�����߂�B
	int AclassScore[3];
	for (int i = 0; i < 3; i++) {
		std::cout << "A�N���X�̐��т���͂��Ă��������B";
		std::cin >> AclassScore[i] ;
		std::cout << "\n";
	}
	//���ς����߂�B
	int totalScore = 0;
	for (int i = 0; i < 3; i++) {
		totalScore += AclassScore[i];
	}
	std::cout << "A�N���X�̕��ϓ_��" << totalScore / 3 << "�ł�\n\n";


	//B�N���X�̕��ϓ_�����߂�B
	totalScore = 0;
	int BClassscore[2];
	for (int i = 0; i < 2; i++) {
		std::cout << "B�N���X�̐��т���͂��Ă��������B";
		std::cin >> BClassscore[i];
		std::cout << "\n";
	}
	//���ς����߂�B
	totalScore = 0;
	for (int i = 0; i < 2; i++) {
		totalScore += BClassscore[i];
	}
	std::cout << "B�N���X�̕��ϓ_��" << totalScore / 2 << "�ł�\n\n";

	//C�N���X�̕��ϓ_�����߂�B
	int CClassscore[3];
	for (int i = 0; i < 3; i++) {
		std::cout << "C�N���X�̐��т���͂��Ă��������B";
		std::cin >> CClassscore[i];
		std::cout << "\n";
	}
	//���ς����߂�B
	totalScore = 0;
	for (int i = 0; i <3; i++) {
		totalScore += CClassscore[i];
	}
	std::cout << "C�N���X�̕��ϓ_��" << totalScore / 3 << "�ł�\n\n";

	//D�N���X�̕��ϓ_�����߂�B
	int DClassscore[4];
	for (int i = 0; i < 4; i++) {
		std::cout << "D�N���X�̍���̐��т���͂��Ă��������B";
		std::cin >> DClassscore[i];
		std::cout << "\n";
	}
	//���ς����߂�B
	totalScore = 0;
	for (int i = 0; i < 4; i++) {
		totalScore += DClassscore[i];
	}
	std::cout << "D�N���X�̕��ϓ_��" << totalScore / 4 << "�ł�\n\n";
    return 0;
}

