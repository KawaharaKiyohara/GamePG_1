/*!
 * @brief	�v���C���[
 */

#include "stdafx.h"
#include "Packman/game/Player/CPlayer.h"
#include "Packman/game/CGameManager.h"

static const float PLAYER_RADIUS = 0.08;
/*!
 *@brief	Update�����߂ČĂ΂�钼�O�Ɉ�x�����Ă΂�鏈���B
 */
void CPlayer::Start() 
{
}
/*!
*@brief	Update�֐������s�����O�ɌĂ΂��X�V�֐��B
*/
void CPlayer::PreUpdate()
{
	Move();
}
/*!
 *@brief	�X�V�����B60fps�Ȃ�16�~���b�Ɉ�x�B30fps�Ȃ�32�~���b�Ɉ�x�Ă΂��B
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
*@brief	�ړ������B
*/

void CPlayer::Move()
{
	int jumpflg = 0;
	if (m_position.y == 0.08f || m_position.y == 0.28f)
	{
		jumpflg = 1;
	}
	if(GetPosition().x)
	float a = 0.02f;
	static const float deltaTime = 1.0f / 60.0f;
	m_position2.z = 1.f;
	m_position2.x = 1.f;
	CVector3 add(0.0f, 0.0f, 0.0f);
	add = m_position2;
	add.Scale(deltaTime);
	if (KeyInput().IsPressW() && jumpflg == 1)
	{
		m_position2.y = 2.5f;
	}

	if (KeyInput().IsPressA())
	{

	}
	if (KeyInput().IsRightPress() && rightmoveflg)
	{
		m_position.x += add.x;
	}
	else if (KeyInput().IsLeftPress() && leftmoveflg)
	{
		m_position.x -= add.x;
	}
	else if (KeyInput().IsUpPress() && upmoveflg)
	{
		m_position.z += add.z;
	}
	else if (KeyInput().IsDownPress() && downmoveflg)
	{
		m_position.z -= add.z;
	}
	rightmoveflg = true;
	leftmoveflg = true;
	upmoveflg = true;
	downmoveflg = true;

	m_position.y += add.y;
	static const CVector3 gravity(0.0f, -9.8f, 0.0f);
	CVector3 addVelocity = gravity;
	addVelocity.Scale(deltaTime);
	m_position2.y += addVelocity.y;
	if (m_position.y < 0.08)
	{
		m_position.y = 0.08;
	}
}

/*!
 *@brief	�`�揈���B60fps�Ȃ�16�~���b�Ɉ�x�B30fps�Ȃ�32�~���b�Ɉ�x�Ă΂��B
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
 *@brief	�\�z�B
 *�K�����CreateShape����x�R�[�����Ă����K�v������B
 */
void CPlayer::Build( const CVector3& pos )
{	
	
	m_sphere.Create(PLAYER_RADIUS, 10, 0xffff0000, true);
	m_idMapModel.Create(m_sphere.GetPrimitive());
	m_shadowModel.Create(m_sphere.GetPrimitive());
	m_position = pos;
}
/*!
*@brief	AABB�̍X�V�B
*/
void CPlayer::UpdateAABB()
{

}