#include "stdafx.h"
#include "GameScene.h"
#include "ScreenEffect/Fade.h"

GameScene::GameScene()
{
}


GameScene::~GameScene()
{
}
bool GameScene::Start()
{
	switch (m_initState) {
	case enInitState_ReqFadeIn:
		g_fade->StartFadeIn();
		m_initState = enInitState_WaitFadeIn;
		break;
	case enInitState_WaitFadeIn:
		if (!g_fade->IsExecute()) {
			//‰Šú‰»Š®—¹
			return true;
		}
		break;
	}
	return false;
}
void GameScene::Update()
{
}