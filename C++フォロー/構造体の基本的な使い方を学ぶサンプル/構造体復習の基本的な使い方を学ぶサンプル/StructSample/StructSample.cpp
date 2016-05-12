// StructSample.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>


int main()
{
	int playerHp = 100;		//プレイヤーのHP
	int playerMp = 200;		//プレイヤーのMP
	int playerLv = 10;		//プレイヤーのレベル
	int playerAtk = 20;		//プレイヤーの攻撃力。
	int playerDef = 30;		//プレイヤーの防御力。

	std::cout << "プレイヤーのHP      " << playerHp << "\n";
	std::cout << "プレイヤーのMP      " << playerMp << "\n";
	std::cout << "プレイヤーのLv      " << playerLv << "\n";
	std::cout << "プレイヤーの攻撃力  " << playerAtk << "\n";
	std::cout << "プレイヤーの防御力  " << playerDef << "\n";
    return 0;
}

