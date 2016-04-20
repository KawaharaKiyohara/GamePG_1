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
	//Moveが呼ばれる感覚は16ミリ秒で固定で考える。
	static const float deltaTime = 1.0f / 60.0f;
	//速度の単位をm/sに変更する。
	m_moveSpeed.x = 1.f;		//XZ平面での移動速度。
	m_moveSpeed.z = 1.f;
	if (KeyInput().IsAPress()) {
		//ジャンプ。
		//初速度を2m/sで与える。
		m_moveSpeed.y = 2.0f;
	}
	CVector3 add(0.0f, 0.0f, 0.0f);
	add = m_moveSpeed;
	add.Scale(deltaTime);
	if (KeyInput().IsUpPress()) {
		m_position.z += add.z;
	}
	if (KeyInput().IsDownPress()) {
		m_position.z -= add.z;
	}
	if (KeyInput().IsRightPress()) {
		m_position.x += add.x;
	}
	if (KeyInput().IsLeftPress()) {
		m_position.x -= add.x;
	}
	m_position.y += add.y;

	//速度に重力加速度の影響を与える。
	static const CVector3 gravity(0.0f, -9.8f, 0.0f);		//重力加速度 9.8m/s^2
	CVector3 addVelocity = gravity;
	addVelocity.Scale(deltaTime);
	m_moveSpeed.y += addVelocity.y;
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