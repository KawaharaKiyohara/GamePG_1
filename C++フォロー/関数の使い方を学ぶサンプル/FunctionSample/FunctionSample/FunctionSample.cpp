// FunctionSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	int score[6];
	for (int i = 0; i < 6; i++) {
		std::cout << "���Ȃ��̐��т���͂��Ă��������B";
		std::cin >> score[i] ;
		std::cout << "\n";
	}
	//���ς����߂�B
	int totalScore = 0;
	for (int i = 0; i < 6; i++) {
		totalScore += score[i];
	}
	std::cout << "���ϓ_��" << totalScore / 6 << "�ł�\n";
    return 0;
}

