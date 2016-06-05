/*!
 * @brief	�}�b�v�\�z�����B
 */

#include "stdafx.h"
#include "Packman/game/Map/CMapBuilder.h"
#include "Packman/game/Map/CWall.h"
#include "Packman/game/item/CFood.h"
#include "Packman/game/Player/CPlayer.h"
#include "Packman/game/CGameManager.h"

 //1�͕ǁB3�̓v���C���[�B
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
	//�n�ʂ��쐬�B
	m_ground.Create( NUM_GRID * GRID_SIZE );
	CGameObjectManager::Instance().AddGameObject(0, &m_ground);
	float radius = GRID_SIZE *0.2f;
	CFood::CreateShape(GRID_SIZE *0.2f);
	CVector3 offset(GRID_SIZE * 0.5f, 0.0f, GRID_SIZE * -0.5f);
	for (int i = 0; i < NUM_GRID; i++) {
		for (int k = 0; k < NUM_GRID; k++) {
			if (sMap[i][k] == 1) {
				//�ǂ��쐬�B
				CWall* wall = CGameObjectManager::Instance().NewGameObject<CWall>(0);
				CVector3 pos(GRID_SIZE*k, GRID_SIZE*0.5f, GRID_SIZE*-i);
				pos.Add(offset);
				wall->Build(CVector3(GRID_SIZE, GRID_SIZE, GRID_SIZE), pos);
			}
			else if (sMap[i][k] == 0) {
				//�p�b�N�}���̃G�T���쐬�B
				CFood* food = CGameObjectManager::Instance().NewGameObject<CFood>(0);
				CVector3 pos(GRID_SIZE*k, radius, GRID_SIZE*-i);
				pos.Add(offset);
				food->Build(pos);
			}
			else if (sMap[i][k] == 3) {
				//�v���C���[
				CVector3 pos(GRID_SIZE*k, 0.2f, GRID_SIZE*-i);
				pos.Add(offset);
				Player().Build(pos);
			}
		}
	}
}