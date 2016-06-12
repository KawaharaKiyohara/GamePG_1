/*!
 * @brief	�p�b�N�}�����H�ׂ�A�C�e���B
 */

#pragma once

#include "tkEngine/shape/tkSphereShape.h"

class CFood : public tkEngine::IGameObject{
public:
	/*!
	*@brief	�R���X�g���N�^�B
	*@details
	* �R���X�g���N�^�Ƃ̓C���X�^���X���������ꂽ�Ƃ��Ɉ�x�����Ă΂�����Ȋ֐��B
	* �N���X�����֐����ɂȂ�܂��B
	*/
	CFood();
	/*!
	 *@brief	Update�����߂ČĂ΂�钼�O�Ɉ�x�����Ă΂�鏈���B
	 */
	void Start() override final;
	/*!
	 *@brief	�X�V�����B60fps�Ȃ�16�~���b�Ɉ�x�B30fps�Ȃ�32�~���b�Ɉ�x�Ă΂��B
	 */
	void Update() override final;
	/*!
	 *@brief	�`�揈���B60fps�Ȃ�16�~���b�Ɉ�x�B30fps�Ȃ�32�~���b�Ɉ�x�Ă΂��B
	 */
	void Render(tkEngine::CRenderContext& renderContext) override final;
	/*!
	 *@brief	�\�z�B
	 *�K�����CreateShape����x�R�[�����Ă����K�v������B
	 */
	void Build( const CVector3& pos );
	/*!
	 *@brief	�`��̐����B
	 *@param[in]	radius		���a�B
	 */
	static void CreateShape(float radius);
	/*!
	 *@brief	�`��̉���B
	 */
	static void ReleaseShape();
private:
	static tkEngine::CSphereShape*	m_sphere;
	CMatrix							m_wvpMatrix;			//<���[���h�r���[�v���W�F�N�V�����s��B
	tkEngine::CIDMapModel			m_idMapModel;
	CVector3						m_position;				//!<���W�B
	CMatrix							m_worldMatrix;			//!<���[���h�s��B
};
