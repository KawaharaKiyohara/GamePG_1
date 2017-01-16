#include "stdafx.h"
#include "TitleScene.h"
#include "GameScene.h"

TitleScene::TitleScene()
{
}


TitleScene::~TitleScene()
{
	DeleteGO(bgmSource);
}
bool TitleScene::Start()
{
	bgmSource = NewGO<CSoundSource>(0);
	bgmSource->Init("Assets/sound/TitleBGM.wav");
	bgmSource->Play(true);
	return true;
}
void TitleScene::Update()
{
	if (Pad(0).IsTrigger(enButtonStart)) {
		g_gameScene = NewGO<GameScene>(0);
		//©•ª‚ğíœB
		DeleteGO(this);
	}
}
void TitleScene::PostRender(CRenderContext& renderContext)
{
}