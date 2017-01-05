#include "stdafx.h"
#include "GameScene.h"
#include "ScreenEffect/Fade.h"
#include "Common/CardDeck.h"
#include "Scene/TitleScene.h"
GameScene* g_gameScene = NULL;

GameScene::GameScene()
{
	
}
GameScene::~GameScene()
{
}
void GameScene::OnDestroy()
{
	DeleteGO(&cardDeck);
	for (int i = 0; i < NUM_PLAYER; i++) {
		DeleteGO(&playerList[i]);
	}
}
bool GameScene::Start()
{
	switch (m_initState) {
	case enInitState_ReqFadeIn:
		light.SetAmbinetLight(CVector3::One);
		//カメラを初期化。
		camera.SetPosition({ 0.0f, 0.0f, -700.0f });
		camera.SetNear(400.0f);
		camera.SetFar(1000.0f);
		camera.Update();
		g_fade->StartFadeIn();
		AddGO(0, &cardDeck);
		textureBG = TextureResources().Load("Assets/sprite/BG.jpg");
		spriteBG.Init(textureBG);
		spriteBG.SetSize({1280, 720});
		m_initState = enInitState_WaitFadeIn;
		
		break;
	case enInitState_WaitFadeIn:
		if (!g_fade->IsExecute()) {
			//初期化完了
			return true;
		}
		break;
	}
	return false;
}
/*!
*@brief	勝敗判定。
*/
bool GameScene::Judgement()
{
	if (playerList[0].GetCardList().empty()) {
		//プレイヤー0の勝ち
		return true;
	}
	else if (playerList[1].GetCardList().empty()) {
		//COMの勝ち
		return true;
	}
	return false;
}
void GameScene::Update()
{
	switch (gameStep) {
	case enGameStep_DealCards: {
		//カードを配る。
		int numPlayerNo = 0;
		while (true) {
			Card* card = cardDeck.GetUnuseCardRandom();
			if (card == NULL) {
				//全部配り終わった。
				break;
			}
			playerList[numPlayerNo].AddCard(card);
			numPlayerNo = (numPlayerNo + 1) % NUM_PLAYER;
		}
		for (int i = 0; i < NUM_PLAYER; i++) {
			AddGO(0, &playerList[i]);
			playerList[i].SetPlayerNo(i);
		}
		//カードの引く相手になるプレイヤーを設定。
		playerList[0].SetTargetPlayer(&playerList[1]);
		playerList[1].SetTargetPlayer(&playerList[0]);
		//まずはプレイヤーの手番。
		playerList[0].ChangeState(Player::enStateSelectCard);
		gameStep = enGameStep_SelectPlayer;
	}break;
	case enGameStep_SelectPlayer:
		if (playerList[0].GetState() == Player::enStateIdle) {
			playerList[0].UpdateCardPosition();
			playerList[1].UpdateCardPosition();
			//プレイヤー選択終わり。
			if (Judgement()) {
				//決着がついた。
				gameStep = enGameStep_Over;
			}
			else {
				//COMの手番。
				playerList[1].ChangeState(Player::enStateSelectCard);
				gameStep = enGameStep_SelectCom;
			}
		}
		break;
	case enGameStep_SelectCom:
		if (playerList[1].GetState() == Player::enStateIdle) {
			//COM選択終わり。
			playerList[0].UpdateCardPosition();
			playerList[1].UpdateCardPosition();
			if (Judgement()) {
				//決着がついた。
				gameStep = enGameStep_Over;
			}
			else {
				//プレイヤーの手番。
				playerList[0].ChangeState(Player::enStateSelectCard);
				gameStep = enGameStep_SelectPlayer;
			}
		}
		break;
	case enGameStep_Over:
		MessageBox(NULL, "結果", "おわり", MB_OK);
		g_fade->StartFadeOut();
		gameStep = enGameStep_WaitFadeOut;
		break;
	case enGameStep_WaitFadeOut:
		if (!g_fade->IsExecute()) {
			//タイトルに戻る。
			DeleteGO(this);
			NewGO<TitleScene>(0);
		}
		break;
	}
}
void GameScene::Render(CRenderContext& rc)
{
	rc.SetRenderState(RS_ZWRITEENABLE, FALSE);
	spriteBG.Draw(rc);
	rc.SetRenderState(RS_ZWRITEENABLE, TRUE);
}