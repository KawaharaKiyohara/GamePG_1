#pragma once
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
private:
	//�������X�e�[�^�X
	enum EnInitState{
		enInitState_ReqFadeIn,		//�t�F�[�h�C���̃��N�G�X�g�𓊂���B
		enInitState_WaitFadeIn,		//�t�F�[�h�C���҂��B
	};
	EnInitState m_initState = enInitState_ReqFadeIn;
};

