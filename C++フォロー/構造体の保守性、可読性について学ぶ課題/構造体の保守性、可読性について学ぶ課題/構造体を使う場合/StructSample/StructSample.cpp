// StructSample.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>


//プレイヤーの構造体。
struct Player{
	int 	hp ;			//HP
	int 	mp ;			//MP
	int 	lv ;			//レベル
	int 	atk ;			//攻撃力。
	int 	def ;			//防御力。
	int 	posX ;			//X座標。
	int 	posY ;			//Y座標。
	int		posZ ;			//Z座標。
	int		moveSpeedX;		//X方向への移動速度。
	int		moveSpeedY;		//Y方向への移動速度。
};

//プレイヤーの移動処理。
void MovePlayer(Player& player )
{
	player.posX += player.moveSpeedX;
	player.posY += player.moveSpeedY;
}
//プレイヤーのパラメータを表示。
void DispPlayerParameter( Player player )
{
	std::cout << "プレイヤーのHP" << player.hp << "\n";
	std::cout << "プレイヤーのMP" << player.mp << "\n";
	std::cout << "プレイヤーのレベル" << player.lv << "\n";
	std::cout << "プレイヤーの攻撃力" << player.atk << "\n";
	std::cout << "プレイヤーの防御力" << player.def << "\n";
	std::cout << "プレイヤーのX座標"  << player.posX << "\n";
	std::cout << "プレイヤーのY座標" << player.posY << "\n";
	std::cout << "プレイヤーのZ座標" << player.posZ << "\n";
	std::cout << "プレイヤーのX方向への移動速度" << player.moveSpeedX << "\n";
	std::cout << "プレイヤーのY方向への移動速度" << player.moveSpeedY << "\n\n";
}
//メイン関数。
int main()
{
	Player player;
	player.hp 			= 100;		//プレイヤーのHP
	player.mp 			= 200;		//プレイヤーのMP
	player.lv 			= 10;		//プレイヤーのレベル
	player.atk 			= 20;		//プレイヤーの攻撃力。
	player.def 			= 30;		//プレイヤーの防御力。
	player.posX 		= 0;		//プレイヤーのX座標。
	player.posY 		= 0;		//プレイヤーのY座標。
	player.posZ 		= 0;		//プレイヤーのZ座標。
	player.moveSpeedX 	= 2;		//プレイヤーのX方向への移動速度。
	player.moveSpeedY 	= 1;		//プレイヤーのY方向への移動速度。
	
	//プレイヤーのパラメータを表示。
	DispPlayerParameter( player );
	//プレイヤーを移動。
	MovePlayer( player );
	//移動後のプレイヤーのパラメータを表示する。
	DispPlayerParameter( player );
	return 0;
}

