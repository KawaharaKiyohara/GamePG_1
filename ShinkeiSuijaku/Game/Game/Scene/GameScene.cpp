#include "stdafx.h"
#include "GameScene.h"
#include "TitleScene.h"

GameScene* g_gameScene = NULL;

GameScene::GameScene()
{
	
}
GameScene::~GameScene()
{
	DeleteGO(bgmSource);
}

bool GameScene::Start()
{
	bgmSource = NewGO<CSoundSource>(0);
	bgmSource->Init("Assets/sound/GameBGM.wav");
	bgmSource->Play(true);
	testModelDataHandle.LoadModelData("Assets/modelData/card.x", NULL);
	testModel.Init(testModelDataHandle.GetBody());
	testModel.SetLight(&light);

	//�J�������������B
	camera.SetPosition({ 0.0f, 0.0f, -700.0f });
	camera.SetNear(400.0f);
	camera.SetFar(1000.0f);
	camera.Update();

	//���C�g���������B
	light.SetAmbinetLight(CVector3::One);

	return true;
}

void GameScene::Update()
{
	//
	if (Pad(0).IsTrigger(enButtonStart)) {
		//�^�C�g����ʂɑJ�ڂ���B
		NewGO<TitleScene>(0);
		DeleteGO(this);
		return;
	}
	testModel.Update(CVector3::Zero, CQuaternion::Identity, CVector3::One);
	
}
/*!
*@brief	�`��֐��B
*/
void GameScene::Render(CRenderContext& renderContext)
{
	testModel.Draw(renderContext, camera.GetViewMatrix(), camera.GetProjectionMatrix());
}