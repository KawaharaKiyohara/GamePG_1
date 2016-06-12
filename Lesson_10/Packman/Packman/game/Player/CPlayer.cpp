/*!
 * @brief	プレイヤー
 */

#include "stdafx.h"
#include "Packman/game/Player/CPlayer.h"
#include "Packman/game/CGameManager.h"

/*!
 *@brief	Updateが初めて呼ばれる直前に一度だけ呼ばれる処理。
 */
void CPlayer::Start() 
{
	m_moveSpeed.Set(0.0f, 0.0f, 0.0f);
}
/*!
*@brief	Update関数が実行される前に呼ばれる更新関数。
*/
void CPlayer::PreUpdate()
{
	Move();
}
/*!
 *@brief	更新処理。60fpsなら16ミリ秒に一度。30fpsなら32ミリ秒に一度呼ばれる。
 */
void CPlayer::Update() 
{
	m_sphere.SetPosition(m_position);
	m_sphere.UpdateWorldMatrix();
	CGameManager& gm = CGameManager::GetInstance();
	CMatrix mMVP = gm.GetGameCamera().GetViewProjectionMatrix();
	const CMatrix& mWorld = m_sphere.GetWorldMatrix();
	m_wvpMatrix.Mul(mWorld, mMVP);
	m_idMapModel.SetWVPMatrix(m_wvpMatrix);
	IDMap().Entry(&m_idMapModel);
	m_shadowModel.SetWorldMatrix(mWorld);
	ShadowMap().Entry(&m_shadowModel);
}
/*!
*@brief	移動処理。
*/
void CPlayer::Move()
{
	//XZ平面での移動速度。
	m_moveSpeed.x = 0.02f;
	m_moveSpeed.z = 0.02f;
	if (KeyInput().IsPress(CKeyInput::enKeyA)) {
		//キーボードのAが押されていたら速度を倍にする。
		m_moveSpeed.x *= 2.0f;
		m_moveSpeed.z *= 2.0f;
		m_moveSpeed.y = 0.1f;
	}
	CVector3 pos = m_position;
	//Z方向への移動。
	{
		if (KeyInput().IsUpPress()) {
			pos.z += m_moveSpeed.z;
		}
		if (KeyInput().IsDownPress()) {
			pos.z -= m_moveSpeed.z;
		}
		//プレイヤーを内包する四角形の４隅の当たり判定を行う。
		bool isHitWall = false;
		float radius = 0.075f;
		//左上
		int x = (int)((pos.x - radius) / GRID_SIZE);
		int z = (int)((pos.z - radius) / -GRID_SIZE);
		if (sMap[z][x] == 1) {
			//壁
			isHitWall = true;
		}

		//右上
		x = (int)((pos.x + radius) / GRID_SIZE);
		z = (int)((pos.z - radius) / -GRID_SIZE);
		if (sMap[z][x] == 1) {
			//壁
			isHitWall = true;
		}
		//左下
		x = (int)((pos.x - radius) / GRID_SIZE);
		z = (int)((pos.z + radius) / -GRID_SIZE);
		if (sMap[z][x] == 1) {
			//壁
			isHitWall = true;
		}

		//右下
		x = (int)((pos.x + radius) / GRID_SIZE);
		z = (int)((pos.z + radius) / -GRID_SIZE);
		if (sMap[z][x] == 1) {
			//壁
			isHitWall = true;
		}

		if (isHitWall) {
			pos.z = m_position.z;
		}
	}
	//X方向への移動。
	{
		if (KeyInput().IsRightPress()) {
			pos.x += m_moveSpeed.x;
		}
		if (KeyInput().IsLeftPress()) {
			pos.x -= m_moveSpeed.x;
		}
		//プレイヤーを内包する四角形の４隅の当たり判定を行う。
		bool isHitWall = false;
		float radius = 0.075f;
		//左上
		int x = (int)((pos.x - radius) / GRID_SIZE);
		int z = (int)((pos.z - radius) / -GRID_SIZE);
		if (sMap[z][x] == 1) {
			//壁
			isHitWall = true;
		}

		//右上
		x = (int)((pos.x + radius) / GRID_SIZE);
		z = (int)((pos.z - radius) / -GRID_SIZE);
		if (sMap[z][x] == 1) {
			//壁
			isHitWall = true;
		}
		//左下
		x = (int)((pos.x - radius) / GRID_SIZE);
		z = (int)((pos.z + radius) / -GRID_SIZE);
		if (sMap[z][x] == 1) {
			//壁
			isHitWall = true;
		}

		//右下
		x = (int)((pos.x + radius) / GRID_SIZE);
		z = (int)((pos.z + radius) / -GRID_SIZE);
		if (sMap[z][x] == 1) {
			//壁
			isHitWall = true;
		}

		if (isHitWall) {
			pos.x = m_position.x;
			
		}
	}
	pos.y += m_moveSpeed.y;

	m_position = pos;
	
	//重力とかは考えない。
	m_moveSpeed.y -= 0.01f;
	if (m_position.y < 0.08f) {
		//座標が半径以下になったので座標を補正。
		m_position.y = 0.08f;
	}
}
/*!
 *@brief	描画処理。60fpsなら16ミリ秒に一度。30fpsなら32ミリ秒に一度呼ばれる。
 */
void CPlayer::Render(tkEngine::CRenderContext& renderContext) 
{
	CGameManager& gm = CGameManager::GetInstance();
	m_sphere.RenderLightWVP(
		renderContext,
		m_wvpMatrix,
		gm.GetFoodLight(),
		false,
		true
	);
}
/*!
 *@brief	構築。
 *必ず先にCreateShapeを一度コールしておく必要がある。
 */
void CPlayer::Build( const CVector3& pos )
{
	m_sphere.Create(0.08f, 10, 0xffff0000, true );
	m_idMapModel.Create(m_sphere.GetPrimitive());
	m_shadowModel.Create(m_sphere.GetPrimitive());
	m_position = pos;
}