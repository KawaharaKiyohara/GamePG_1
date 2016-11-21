#pragma once

class Player : public IGameObject
{
public:
	//�������烁���o�֐��B
	Player();
	~Player();
	void Start();
	void Update();
	void Render(CRenderContext& renderContext);
	//�������烁���o�ϐ��B
	CSkinModel				skinModel;					//�X�L�����f���B
	CSkinModelData			skinModelData;				//�X�L�����f���f�[�^�B
	CAnimation				animation;					//�A�j���[�V�����B
	CVector3				position = CVector3::Zero;	//���W�B
	int						currentAnimationNo = 0;		//���݂̃A�j���[�V�����ԍ��B
};

