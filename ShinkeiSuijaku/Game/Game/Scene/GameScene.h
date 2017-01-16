#pragma once

#include "tkEngine/Sound/tkSoundSource.h"

/*!
 *@brief	�Q�[���V�[���B
 */
class GameScene :
	public IGameObject
{
public:
	/*!
	 *@brief	�R���X�g���N�^�B
	 */
	GameScene();
	/*!
	 *@brief	�f�X�g���N�^�B
	 */
	~GameScene();
	/*!
	 *@brief	�J�n�֐��B
	 *@details
	 * �������Ȃǂ����̊֐��Ɏ������Ă��������B</br>
	 * ���̊֐���true��Ԃ��Ɩ{�ِ��͈ȍ~�̃t���[���ł͌Ă΂�Ȃ��Ȃ�܂��B</br>
	 * �����ăQ�[���I�u�W�F�N�g�̏�Ԃ������������ɂȂ�Update�֐����Ă΂��悤�ɂȂ�܂��B</br>
	 *@return	true���A���Ă����珉���������B
	 */
	bool Start() override;
	/*!
	 *@brief	�X�V�֐��B
	 */
	void Update() override;
	/*!
	*@brief	�`��֐��B
	*/
	void Render(CRenderContext& renderContext);
private:
	CCamera camera;								//!<�J�����B
	CLight  light;								//!<���C�g�B
	CSoundSource* bgmSource;					//!<BGM�\�[�X�B
	CSkinModelDataHandle testModelDataHandle;	//!<�e�X�g���f���f�[�^�n���h���B
	CSkinModel testModel;						//!<�e�X�g���f���B
};

extern GameScene* g_gameScene;
