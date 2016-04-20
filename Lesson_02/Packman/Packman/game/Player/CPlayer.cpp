/*!
 * @brief	�v���C���[
 */

#include "stdafx.h"
#include "Packman/game/Player/CPlayer.h"
#include "Packman/game/CGameManager.h"

/*!
 *@brief	Update�����߂ČĂ΂�钼�O�Ɉ�x�����Ă΂�鏈���B
 */
void CPlayer::Start() 
{
	m_moveSpeed.Set(0.0f, 0.0f, 0.0f);
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
	m_moveSpeed.x = 0.02f;		//XZ���ʂł̈ړ����x�B
	m_moveSpeed.z = 0.02f;
	if (KeyInput().IsAPress()) {
		//�L�[�{�[�h��A��������Ă����瑬�x��{�ɂ���B
		m_moveSpeed.x *= 2.0f;
		m_moveSpeed.z *= 2.0f;
		m_moveSpeed.y = 0.1f;
	}
	//Y�����ւ̈ړ����x�B
	if (KeyInput().IsUpPress()) {
		m_position.z += m_moveSpeed.z;
	}
	if (KeyInput().IsDownPress()) {
		m_position.z -= m_moveSpeed.z;
	}
	if (KeyInput().IsRightPress()) {
		m_position.x += m_moveSpeed.x;
	}
	if (KeyInput().IsLeftPress()) {
		m_position.x -= m_moveSpeed.x;
	}
	m_position.y += m_moveSpeed.y;

	//�d�͂Ƃ��͍l���Ȃ��B
	m_moveSpeed.y -= 0.01f;
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
	m_sphere.Create(0.08f, 10, 0xffff0000, true );
	m_idMapModel.Create(m_sphere.GetPrimitive());
	m_shadowModel.Create(m_sphere.GetPrimitive());
	m_position = pos;
}