#pragma once
/*!
 *@brief	�^�C�g���V�[���B
 */
class TitleScene :
	public IGameObject
{
public:
	/*!
	 *@brief	�R���X�g���N�^�B
	 */
	TitleScene();
	/*!
	 *@brief	�f�X�g���N�^�B
	 */
	~TitleScene();
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
	*@brief	�x���`��֐��B
	@details
	* �|�X�g�G�t�F�N�g�̌�Ŏ��s����܂��BHUD�Ȃǃ|�X�g�G�t�F�N�g�̉e�����󂯂����Ȃ��`�敨�͂����Ń����_�����O���Ă��������B
	*@param[in]		renderContext		�����_�����O�R���e�L�X�g�B
	*/
	void PostRender( CRenderContext& renderContext ) override;
private:
	//��ԁB
	enum EState {
		eStateWaitFadeIn,	//!<�t�F�[�h�C���҂��B
		eStateRun,			//!<���s���B
		eStateWaitFadeOut,	//!<�t�F�[�h�A�E�g�҂��B
	};
	CSprite		m_titleBGSprite;		//!<�^�C�g����ʂ̔w�i�̃X�v���C�g�B
	CTexture	m_titleBGTexture;		//!<�^�C�g����ʂ̔w�i�̃e�N�X�`���B
	EState		m_state = eStateRun;	//!<��ԁB
};
