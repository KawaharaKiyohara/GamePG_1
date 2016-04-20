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
	//Move���Ă΂�銴�o��16�~���b�ŌŒ�ōl����B
	static const float deltaTime = 1.0f / 60.0f;
	//���x�̒P�ʂ�m/s�ɕύX����B
	m_moveSpeed.x = 1.f;		//XZ���ʂł̈ړ����x�B
	m_moveSpeed.z = 1.f;
	if (KeyInput().IsAPress()) {
		//�W�����v�B
		//�����x��2m/s�ŗ^����B
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

	//���x�ɏd�͉����x�̉e����^����B
	static const CVector3 gravity(0.0f, -9.8f, 0.0f);		//�d�͉����x 9.8m/s^2
	CVector3 addVelocity = gravity;
	addVelocity.Scale(deltaTime);
	m_moveSpeed.y += addVelocity.y;
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