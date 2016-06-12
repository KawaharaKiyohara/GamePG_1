/*!
* @brief	敵
*/

#include "stdafx.h"
#include "Packman/game/enemy/CEnemy.h"
#include "tkEngine/graphics/tkEffect.h"
#include "Packman/game/CGameManager.h"


CSphereShape*	CEnemy::m_sphere = nullptr;
/*!
*@brief	コンストラクタ。
*/
CEnemy::CEnemy()
{
	m_intervalFrame = 30;
	currentRoot = 0;
}
/*!
*@brief	デストラクタ。
*/
CEnemy::~CEnemy()
{
	for (auto n : m_nodes) {
		delete n;
	}
}
void CEnemy::Awake()
{
	m_position = CVector3::Zero;
}
void CEnemy::BuildNodes()
{
	CVector3 offset(GRID_SIZE * 0.5f, 0.0f, GRID_SIZE * -0.5f);
	for (int i = 0; i < NUM_GRID; i++) {
		for (int k = 0; k < NUM_GRID; k++) {
			CPathFinding::SNode* node = new CPathFinding::SNode;
			if (sMap[i][k] == 1) {
				node->isPossiblePath = false;
			}
			else {
				node->isPossiblePath = true;
			}
			node->position.x = GRID_SIZE *k;
			node->position.y = 0.0f;
			node->position.z = GRID_SIZE * -i;
			node->position.Add(offset);
			m_nodes.push_back(node);
		}
	}
	//隣接ノードを構築する。
	for (int i = 0; i < NUM_GRID; i++) {
		for (int k = 0; k < NUM_GRID; k++) {
			CPathFinding::SNode* node = m_nodes.at(i * NUM_GRID + k);
			//左の隣接ノード。
			if (k > 0) {
				node->linkNodes.push_back(m_nodes.at(i * NUM_GRID + k - 1));
			}
			//右の隣接ノード
			if (k < NUM_GRID - 1) {
				node->linkNodes.push_back(m_nodes.at(i * NUM_GRID + k + 1));
			}
			//上の隣接ノード
			if (i > 0) {
				node->linkNodes.push_back(m_nodes.at((i-1) * NUM_GRID + k));
			}
			//下の隣接ノード
			if (i < NUM_GRID - 1) {
				node->linkNodes.push_back(m_nodes.at((i + 1) * NUM_GRID + k));
			}
		}
	}
}
void CEnemy::Start()
{
	BuildNodes();
	m_pathFinding.SetNodes(m_nodes);
}
void CEnemy::Update()
{
	m_sphere->SetPosition(m_position);
	m_sphere->UpdateWorldMatrix();
	CGameManager& gm = CGameManager::GetInstance();
	CMatrix mMVP = gm.GetGameCamera().GetViewProjectionMatrix();
	m_worldMatrix = m_sphere->GetWorldMatrix();
	m_wvpMatrix.Mul(m_worldMatrix, mMVP);
	m_idMapModel.SetWVPMatrix(m_wvpMatrix);
	IDMap().Entry(&m_idMapModel);
	//プレイヤーまでの経路を探索する。	
	if (m_intervalFrame == 30) {
		//30フレームに一度経路を再検索する。
		m_intervalFrame = 0;
		m_pathFinding.FindRoot(&m_root, m_position, Player().GetPosition());
		currentRoot = 0;
	}
	m_intervalFrame++;
	Move();

}
void CEnemy::Move()
{
	if (m_root.empty()) {
		//ルートなし。
		return;
	}
	CVector3 moveDir = CVector3::Zero;
	
	if (currentRoot < m_root.size() - 1) {
		CPathFinding::SNode* node = m_root[currentRoot];
		CPathFinding::SNode* nextNode = m_root[currentRoot + 1];
		//次のノードまでのベクトルを計算。
		
		moveDir.Subtract(nextNode->position, m_position);
		moveDir.y = 0.0f;
		float len = moveDir.Length();
		if (len < 0.02f) {
			//次のノードへ
			currentRoot++;
			return;
		}
		moveDir.Normalize();
	}
	CVector3 add = moveDir;
	add.Scale(0.01f);
	m_position.Add(add);

}
void CEnemy::Render(tkEngine::CRenderContext& renderContext)
{
	CGameManager& gm = CGameManager::GetInstance();
	m_sphere->RenderLightWVP(
		renderContext,
		m_wvpMatrix,
		gm.GetFoodLight(),
		true,
		true,
		&m_worldMatrix
		);
}
void CEnemy::Build(const CVector3& pos)
{
	m_idMapModel.Create(m_sphere->GetPrimitive());
	m_position = pos;
}
void CEnemy::CreateShape(float radius)
{
	if (m_sphere == nullptr) {
		m_sphere = new tkEngine::CSphereShape();
		m_sphere->Create(radius * 1.5f, 10, 0xffff0000, true);
	}
}
void CEnemy::ReleaseShape()
{
	delete m_sphere;
	m_sphere = nullptr;
}