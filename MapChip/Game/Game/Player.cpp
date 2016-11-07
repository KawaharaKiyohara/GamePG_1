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
	skinModel.SetLight(&g_defaultLight);	//デフォルトライトを設定。
}
void Player::Update()
{
	skinModel.Update(CVector3::Zero, CQuaternion::Identity, CVector3::One);
}
void Player::Render(CRenderContext& renderContext)
{
	skinModel.Draw(renderContext, g_gameCamera->GetViewMatrix(), g_gameCamera->GetProjectionMatrix());
}
