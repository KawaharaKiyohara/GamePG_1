#include "stdafx.h"
#include "Player.h"
#include "Camera.h"

Player::Player()
{
}


Player::~Player()
{
}
void Player::Start()
{
	skinModelData.LoadModelData("Assets/modelData/Player.X", NULL);
	skinModel.Init(&skinModelData);
	skinModel.SetLight(&g_defaultLight);	//�f�t�H���g���C�g��ݒ�B
	//�L�����N�^�R���g���[���̏������B
	characterController.Init(0.5f, 1.0f, position);
}
void Player::Update()
{
	//�L�����N�^�[�̈ړ����x������B
	CVector3 move = characterController.GetMoveSpeed();
	move.x = -Pad(0).GetLStickXF() * 5.0f;
	move.z = -Pad(0).GetLStickYF() * 5.0f;

	//���肵���ړ����x���L�����N�^�R���g���[���[�ɐݒ�B
	characterController.SetMoveSpeed(move);
	//�L�����N�^�[�R���g���[���[�����s�B
	characterController.Execute();
	//���s���ʂ��󂯎��B
	position = characterController.GetPosition();
	//���[���h�s��̍X�V�B
	skinModel.Update(position, CQuaternion::Identity, CVector3::One);
}
void Player::Render(CRenderContext& renderContext)
{
	skinModel.Draw(renderContext, g_gameCamera->GetViewMatrix(), g_gameCamera->GetProjectionMatrix());
}
