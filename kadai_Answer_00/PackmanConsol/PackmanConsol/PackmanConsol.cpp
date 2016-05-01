// PackmanConsol.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>

//マップの高さ。
const int MAP_HEIGHT = 15;
//マップの幅。
const int MAP_WIDTH = 15;

//マップの定義。1は壁。0は餌。
static int sMap[MAP_HEIGHT][MAP_WIDTH] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 2, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
	{ 1, 2, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 2, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};

void EndFrame()
{
	Sleep(100);	//100ミリ秒眠る。
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 0;
	pos.Y = 0;

	SetConsoleCursorPosition(hCons, pos);
}
/*!
 *@brief	プレイヤークラス。
 */
class CPlayer {
private:
	int m_posX;			//!<x座標。
	int m_posY;			//!<y座標。
public:
	/*!
	 *@brief	コンストラクタ。
	 */
	CPlayer()
	{
		//初期化を行う。
		m_posX = 0;
		m_posY = 0;
	}
	/*!
	 *@brief	デストラクタ。
	 */
	~CPlayer()
	{

	}
	/*!
	 *@brief	移動処理。
	 */
	void Move()
	{
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			m_posY--;
			if (m_posY < 0) {
				m_posY = 0;
			}
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			m_posX--;
			if (m_posX < 0) {
				m_posX = 0;
			}
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			m_posY++;
			if (m_posY > MAP_HEIGHT - 1) {
				m_posY = MAP_HEIGHT - 1;
			}
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			m_posX++;
			if (m_posX > MAP_WIDTH - 1) {
				m_posX = MAP_WIDTH - 1;
			}
		}
	}
	/*!
	 *@brief	X座標を取得。
	 */
	int GetPositionX()
	{
		return m_posX;
	}
	/*!
	 *@brief	Y座標を取得。
	 */
	int GetPositionY()
	{
		return m_posY;
	}
	/*!
	 *@brief	座標を設定。
	 *@param	x		x座標。
	 *@param	y		y座標。
	 */
	void SetPosition(int x, int y)
	{
		m_posX = x;
		m_posY = y;
	}
};
/*!
 *@brief	メイン関数。
 */
int main()
{
	CPlayer player;
	//プレイヤーの初期位置を決定。
	player.SetPosition(7, 7);
	//ゲームループ。
	while (true) {
		//プレイヤーの移動処理。
		player.Move();	
		int isGameOver = 0;	//ゲームオーバーフラグ。
		//描画。
		for (int i = 0; i < MAP_HEIGHT; i++) {
			for (int j = 0; j < MAP_WIDTH; j++) {
				if (player.GetPositionX() == j && player.GetPositionY() == i) {
					if (sMap[i][j] == 2) {
						//ここは敵がいるのでゲームオーバーのフラグを立てる。
						isGameOver = 1;
					}
					else if (sMap[i][j] == 0) {
						//食べ物なので食べる。
						sMap[i][j] = -1;	//-1にしたら表示されなくなる。
					}
					std::cout << "Ｐ";
				}else if (sMap[i][j] == 1) {
					std::cout << "■";
				}
				else if (sMap[i][j] == 0) {
					std::cout << "〇";
				}
				else if (sMap[i][j] == 2) {		//マップ配列が２なら敵。
					std::cout << "敵";
				}
				else if (sMap[i][j] == -1) {
					std::cout << "　";
				}
			}
			std::cout << "\n";
		}
		if (isGameOver == 1) {
			//ゲームオーバーのフラグが立っているのでゲームオーバーの表示をする。
			std::cout << "ゲームオーバー\n";
		}
		EndFrame();	//フレームの最後に呼んでね。おまじない。
	}
    return 0;
}

