/*!
* @brief	�G�B
*/
#pragma once

#include "tkEngine/shape/tkSphereShape.h"
#include "tkEngine/AI/tkPathFinding.h"

class CEnemy : public tkEngine::IGameObject {
public:
	/*!
	*@brief	�R���X�g���N�^�B
	*/
	CEnemy();
	/*!
	*@brief	�f�X�g���N�^�B
	*/
	~CEnemy();
	/*!
	*@brief	�C���X�^���X�𐶐���������Ɉ�x�����Ă΂�鏈���B</br>
	* Start��葬���^�C�~���O�ŃR�[�������B
	*/
	void Awake() override final;
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
	void Build(const CVector3& pos);
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
	/*!
	*@brief	�o�H�T���p�̃m�[�h���\�z�B
	*/
	void BuildNodes();
	/*!
	*@brief	�ړ������B
	*/
	void Move();
private:
	static tkEngine::CSphereShape*		m_sphere;
	CMatrix								m_wvpMatrix;			//<���[���h�r���[�v���W�F�N�V�����s��B
	tkEngine::CIDMapModel				m_idMapModel;
	CVector3							m_position;
	CMatrix								m_worldMatrix;			//!<���[���h�s��B
	tkEngine::CPathFinding				m_pathFinding;			//!<�o�H�T���B
	std::vector<CPathFinding::SNode*>	m_nodes;				//!<�o�H�T���p�̃m�[�h�B
	int									m_intervalFrame;		//!<�C���^�[�o���^�C���B
	std::vector<CPathFinding::SNode*>	m_root;					//!<�v���C���[�܂ł̃��[�g�B
	int									currentRoot;			//!<�v���C���[�܂ł̃��[�g��ō��ǂ��̃m�[�h�ɂ��邩�B
};
