// FunctionSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

//�N���X�̐��т̓��͂ƕ\�����s���֐��B
//className �N���X��
//numStudent ���k�̐��B
void InputAndDispClassScore( const char* className, int numStudent)
{
	int classScore[256];
	for (int i = 0; i < numStudent; i++) {
		std::cout << className;
		std::cout << "�̐��т���͂��Ă��������B";
		std::cin >> classScore[i];
		std::cout << "\n";
	}
	//���ς����߂�B
	int totalScore = 0;
	for (int i = 0; i < numStudent; i++) {
		totalScore += classScore[i];
	}
	std::cout << className << "�̕��ϓ_��" << totalScore / numStudent << "�ł�\n\n";
}
int main()
{
	//A�N���X�̐��ѓ��͂ƕ\���B
	InputAndDispClassScore("A�N���X", 3);

	//B�N���X�̐��ѓ��͂ƕ\���B
	InputAndDispClassScore("B�N���X", 2);

	//C�N���X�̕��ϓ_�����߂�B
	InputAndDispClassScore("C�N���X", 3);

	//D�N���X�̕��ϓ_�����߂�B
	InputAndDispClassScore("D�N���X", 4);

    return 0;
}

