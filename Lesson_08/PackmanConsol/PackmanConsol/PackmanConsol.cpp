// PackmanConsol.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "CVector2.h"
#include "PackmanConsol.h"
#include "PathFinding.h"

//マップの定義。1は壁。0は餌。
int g_map[MAP_HEIGHT][MAP_WIDTH] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};

//フレームバッファ・・・のようなもの。
static char sFrameBuffer[MAP_HEIGHT][MAP_WIDTH];

CPathFinding g_pathFinding;

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
	CVector2 m_position;	//!<座標。
public:
	/*!
	*@brief	コンストラクタ。
	*/
	CPlayer()
	{
		//初期化を行う。
		m_position.Set(0, 0);
	}
	/*!
	*@brief	デストラクタ。
	*/
	~CPlayer()
	{

	}
	/*!
	*@brief	プレイヤーの描画処理。
	*/
	void Draw()
	{
		//フレームバッファにドロー。
		sFrameBuffer[m_position.GetY()][m_position.GetX()] = 'P';
	}
	/*!
	*@brief	更新処理。
	*/
	void Update()
	{
		int x = m_position.GetX();
		int y = m_position.GetY();
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			y--;
			if (y < 0) {
				y = 0;
			}
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			x--;
			if (x < 0) {
				x = 0;
			}
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			y++;
			if (y > MAP_HEIGHT - 1) {
				y = MAP_HEIGHT - 1;
			}
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			x++;
			if (x > MAP_WIDTH - 1) {
				x = MAP_WIDTH - 1;
			}
		}
		m_position.Set(x, y);
	}
	CVector2 GetPosition()
	{
		return m_position;
	}
	/*!
	*@brief	X座標を取得。
	*/
	int GetPositionX()
	{
		return m_position.GetX();
	}
	/*!
	*@brief	Y座標を取得。
	*/
	int GetPositionY()
	{
		return m_position.GetY();
	}
	/*!
	*@brief	座標を設定。
	*@param	x		x座標。
	*@param	y		y座標。
	*/
	void SetPosition(int x, int y)
	{
		m_position.Set(x, y);
	}
};
CPlayer g_player;

class CEnemy {
private:
	CVector2 m_position;	//!<座標。
	int		m_moveDir;		//!<移動方向
	int		m_intervalTime;
public:
	CEnemy()
	{
		m_moveDir = 1;
		m_intervalTime = 0;
	}
	/*!
	*@brief	プレイヤーの描画処理。
	*/
	void Draw()
	{
		//フレームバッファにドロー。
		sFrameBuffer[m_position.GetY()][m_position.GetX()] = 'E';
	}
	/*!
	*@brief	更新処理。
	*/
	void Update()
	{
		m_intervalTime++;
		if (m_intervalTime % 5) {
			return;
		}
		//プレイヤーまでの経路探索。
		std::vector<CVector2> root;
		g_pathFinding.FindRoot(root, m_position, g_player.GetPosition());
		if (!root.empty()) {
			m_position = root[0];
		}
	}
	void SetPosition(int x, int y)
	{
		m_position.Set(x, y);
	}
};


/*!
*@brief	食べ物クラス。
*/
class CFood {
private:
	CVector2 m_position;	//!<座標。
	bool m_isDead;			//!<死亡フラグ。
public:
	/*!
	*@brief	コンストラクタ。
	*/
	CFood() :
		m_isDead(false)
	{
		m_position.Set(0, 0);
	}
	/*!
	*@brief	壁の描画処理。
	*/
	void Draw()
	{
		if (!m_isDead) {
			//フレームバッファにドロー。
			sFrameBuffer[m_position.GetY()][m_position.GetX()] = '.';
		}
	}
	/*!
	*@brief	座標を設定。
	*/
	void SetPosition(int x, int y)
	{
		m_position.Set(x, y);
	}
	/*!
	*@brief	更新処理。
	*/
	void Update()
	{
		//プレイヤーと触れたら食べ物が消えるようにしてみよう・・・
		//プレイヤーはg_playerでアクセスできる。
		//プレイヤーとCFoodの座標が同じになった時に、消えるようにすればいいはず。
		//プレイヤーの座標はg_player.GetPositionX()とg_player.GetPositionY()で取得できる。
		//例えばプレイヤーのX座標が欲しいならこんな感じ。
		//int pos_x = g_player.GetPositionX();
		if (m_position.GetX() == g_player.GetPositionX()
			&& m_position.GetY() == g_player.GetPositionY()
			) {
			m_isDead = true;
		}
	}
};
/*!
*@brief	壁クラス。
*/
class CWall {
private:
	CVector2 m_position;		//!<座標
public:
	/*!
	*@brief	コンストラクタ。
	*/
	CWall()
	{
		m_position.Set(0, 0);
	}
	/*!
	*@brief	壁の描画処理。
	*/
	void Draw()
	{
		//フレームバッファにドロー。
		sFrameBuffer[m_position.GetY()][m_position.GetX()] = 'W';
	}
	/*!
	*@brief	座標を設定。
	*/
	void SetPosition(int x, int y)
	{
		m_position.Set(x, y);
	}
};

/*!
 *@brief	メイン関数。
 */
int main()
{
	//プレイヤーの初期位置を決定。
	g_player.SetPosition(7, 7);
	//壁
	int numWall = 0;	//壁の数。
	CWall walls[MAP_HEIGHT*MAP_WIDTH];
	//食べ物
	int numFood = 0;
	CFood foods[MAP_HEIGHT*MAP_WIDTH];
	//敵。
	int numEnemy = 0;
	CEnemy enemy[MAP_HEIGHT*MAP_WIDTH];
	g_pathFinding.BuildNodes();
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (g_map[i][j] == 1) {
				//壁。
				walls[numWall].SetPosition(j, i);
				//壁を一つ作ったのでカウントアップ。
				numWall++;
			}
			else if (g_map[i][j] == 2) {
				//敵。
				enemy[numEnemy].SetPosition(j, i);
				numEnemy++;
			}
			if (g_map[i][j] != 1) {
				//食べ物
				foods[numFood].SetPosition(j, i);
				//食べ物を一つ作ったのでカウントアップ。
				numFood++;
			}
		}
	}
	//ゲームループ。
	while (true) {
		//フレームバッファをクリア。
		memset(sFrameBuffer, 0, sizeof(sFrameBuffer));
		
		//食べ物の処理。
		for (int i = 0; i < numFood; i++) {
			foods[i].Update();
			foods[i].Draw();
		}
		//壁の処理。
		for (int i = 0; i < numWall; i++) {
			walls[i].Draw();
		}
		//敵の処理。
		for (int i = 0; i < numEnemy; i++) {
			enemy[i].Update();
			enemy[i].Draw();
		}
		//プレイヤーの処理。
		g_player.Update();
		g_player.Draw();

		//フレームバッファの内容を画面に表示する。
		for (int i = 0; i < MAP_HEIGHT; i++) {
			for (int j = 0; j < MAP_WIDTH; j++) {
				std::cout << sFrameBuffer[i][j];
			}
			std::cout << "\n";
		}
		EndFrame();	//フレームの最後に呼んでね。おまじない。
	}
    return 0;
}

