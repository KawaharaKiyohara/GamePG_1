#include "stdafx.h"
#include "Player.h"
#include "Camera.h"


enum {
	AnimationStand,		//�����B
	AnimationWalk,		//�����B
	AnimationRun,		//����B
	AnimationJump,		//�W�����v�B
	AnimationAttack_00,	//�U��00�B
	AnimationAttack_01,	//�U��01�B
	AnimationAttack_02,	//�U��02�B
	AnimationDamage,	//�_���[�W�B
	AnimationDeath,		//���S�B
	NumAnimation,		//�A�j���[�V�����̐��B
};

Player::Player()
{
}


Player::~Player()
{
}
void Player::Start()
{
	skinModelData.LoadModelData("Assets/modelData/Player.X", &animation);
	skinModel.Init(&skinModelData);
	skinModel.SetLight(&g_defaultLight);	//�f�t�H���g���C�g��ݒ�B
	animation.PlayAnimation(currentAnimationNo);
}
void Player::Update()
{
	//A�{�^����B�{�^���������ꂽ��⊮�Ȃ��̃A�j���[�V�����Đ����s���B
	if (Pad(0).IsTrigger(enButtonA)) {
		//A�{�^���������ꂽ��A�j���[�V�����ԍ����C���N�������g����B
		if (currentAnimationNo < NumAnimation - 1) {
			currentAnimationNo++;
			//�A�j���[�V�������؂�ւ�����̂ōĐ����N�G�X�g���s���B
			animation.PlayAnimation(currentAnimationNo);
		}
	}
	else if (Pad(0).IsTrigger(enButtonB)) {
		//B�{�^���������ꂽ��A�j���[�V�����ԍ����f�N�������g����B
		if (currentAnimationNo > 0) {
			currentAnimationNo--;
			//�A�j���[�V�������؂�ւ�����̂ōĐ����N�G�X�g���s���B
			animation.PlayAnimation(currentAnimationNo);
		}
	}
	//X�{�^����Y�{�^���������ꂽ���Ԃ���̃A�j���[�V�����Đ����s���B
	else if (Pad(0).IsTrigger(enButtonX)) {
		//X�{�^���������ꂽ��A�j���[�V�����ԍ����C���N�������g����B
		if (currentAnimationNo < NumAnimation - 1) {
			currentAnimationNo++;
			//�A�j���[�V�������؂�ւ�����̂ōĐ����N�G�X�g���s���B
			//�������͕�Ԏ��ԁB
			animation.PlayAnimation(currentAnimationNo, 0.3f);
		}
	}
	else if (Pad(0).IsTrigger(enButtonY)) {
		//Y�{�^���������ꂽ��A�j���[�V�����ԍ����f�N�������g����B
		if (currentAnimationNo > 0) {
			currentAnimationNo--;
			//�A�j���[�V�������؂�ւ�����̂ōĐ����N�G�X�g���s���B
			//�������͕�Ԏ��ԁB
			animation.PlayAnimation(currentAnimationNo, 0.3f);
		}
	}

	animation.Update(1.0/60.0f);	
	//���[���h�s��̍X�V�B
	skinModel.Update(CVector3::Zero, CQuaternion::Identity, CVector3::One);
}
void Player::Render(CRenderContext& renderContext)
{
	skinModel.Draw(renderContext, g_gameCamera->GetViewMatrix(), g_gameCamera->GetProjectionMatrix());
}
