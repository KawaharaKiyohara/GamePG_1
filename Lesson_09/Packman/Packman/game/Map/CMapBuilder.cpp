/*!
 * @brief	マップ構築処理。
 */

#include "stdafx.h"
#include "Packman/game/Map/CMapBuilder.h"
#include "Packman/game/Map/CWall.h"
#include "Packman/game/item/CFood.h"
#include "Packman/game/Player/CPlayer.h"
#include "Packman/game/CGameManager.h"

 //1は壁。3はプレイヤー。
int sMap[NUM_GRID][NUM_GRID] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 3, 0, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },


};
CMapBuilder::CMapBuilder()
{
}
CMapBuilder::~CMapBuilder()
{
}
void CMapBuilder::Build()
{
	//地面を作成。
	m_ground.Create( NUM_GRID * GRID_SIZE );
	CGameObjectManager::Instance().AddGameObject(0, &m_ground);
	float radius = GRID_SIZE *0.2f;
	CFood::CreateShape(GRID_SIZE *0.2f);
	CVector3 offset(GRID_SIZE * 0.5f, 0.0f, GRID_SIZE * -0.5f);
	for (int i = 0; i < NUM_GRID; i++) {
		for (int k = 0; k < NUM_GRID; k++) {
			if (sMap[i][k] == 1) {
				//壁を作成。
				CWall* wall = CGameObjectManager::Instance().NewGameObject<CWall>(0);
				CVector3 pos(GRID_SIZE*k, GRID_SIZE*0.5f, GRID_SIZE*-i);
				pos.Add(offset);
				wall->Build(CVector3(GRID_SIZE, GRID_SIZE, GRID_SIZE), pos);
			}
			else if (sMap[i][k] == 0) {
				//パックマンのエサを作成。
				CFood* food = CGameObjectManager::Instance().NewGameObject<CFood>(0);
				CVector3 pos(GRID_SIZE*k, radius, GRID_SIZE*-i);
				pos.Add(offset);
				food->Build(pos);
			}
			else if (sMap[i][k] == 3) {
				//プレイヤー
				CVector3 pos(GRID_SIZE*k, 0.2f, GRID_SIZE*-i);
				pos.Add(offset);
				Player().Build(pos);
			}
		}
	}
}