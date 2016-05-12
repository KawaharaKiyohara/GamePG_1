// StructSample.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>


//プレイヤーの移動処理。
void MovePlayer(int& playerPosX, int& playerPosY, int& playerPosZ, int	playerMoveSpeedX, int	playerMoveSpeedY )
{
	playerPosX += playerMoveSpeedX;
	playerPosY += playerMoveSpeedY;
}
//プレイヤーのパラメータを表示。
void DispPlayerParameter( int playerHp, int playerMp, int playerLv, int playerAtk, int playerDef, int playerPosX, int playerPosY, int playerPosZ, int	playerMoveSpeedX, int	playerMoveSpeedY )
{
	std::cout << "プレイヤーのHP" << playerHp << "\n";
	std::cout << "プレイヤーのMP" << playerMp << "\n";
	std::cout << "プレイヤーのレベル" << playerLv << "\n";
	std::cout << "プレイヤーの攻撃力" << playerAtk << "\n";
	std::cout << "プレイヤーの防御力" << playerDef << "\n";
	std::cout << "プレイヤーのX座標"  << playerPosX << "\n";
	std::cout << "プレイヤーのY座標" << playerPosY << "\n";
	std::cout << "プレイヤーのZ座標" << playerPosZ << "\n";
	std::cout << "プレイヤーのX方向への移動速度" << playerMoveSpeedX << "\n";
	std::cout << "プレイヤーのY方向への移動速度" << playerMoveSpeedY << "\n\n";
}
//メイン関数。
int main()
{
	int 	playerHp 			= 100;		//プレイヤーのHP
	int 	playerMp 			= 200;		//プレイヤーのMP
	int 	playerLv 			= 10;		//プレイヤーのレベル
	int 	playerAtk 			= 20;		//プレイヤーの攻撃力。
	int 	playerDef 			= 30;		//プレイヤーの防御力。
	int 	playerPosX 			= 0;		//プレイヤーのX座標。
	int 	playerPosY 			= 0;		//プレイヤーのY座標。
	int		playerPosZ 			= 0;		//プレイヤーのZ座標。
	int		playerMoveSpeedX 	= 2;		//プレイヤーのX方向への移動速度。
	int		playerMoveSpeedY 	= 1;		//プレイヤーのY方向への移動速度。
	
	//プレイヤーのパラメータを表示。
	DispPlayerParameter( playerHp, playerMp, playerLv, playerAtk, playerDef, playerPosX, playerPosY, playerPosZ, playerMoveSpeedX, playerMoveSpeedY );
	//プレイヤーを移動。
	MovePlayer(playerPosX, playerPosY, playerPosZ, playerMoveSpeedX, playerMoveSpeedY);
	//移動後のプレイヤーのパラメータを表示する。
	DispPlayerParameter(playerHp, playerMp, playerLv, playerAtk, playerDef, playerPosX, playerPosY, playerPosZ, playerMoveSpeedX, playerMoveSpeedY );
	return 0;
}

