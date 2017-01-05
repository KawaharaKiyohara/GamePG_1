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
		//�J�������������B
		camera.SetPosition({ 0.0f, 0.0f, -700.0f });
		camera.SetNear(400.0f);
		camera.SetFar(1000.0f);
		camera.Update();
		g_fade->StartFadeIn();
		AddGO(0, &cardDeck);

		m_initState = enInitState_WaitFadeIn;
		
		break;
	case enInitState_WaitFadeIn:
		if (!g_fade->IsExecute()) {
			//����������
			return true;
		}
		break;
	}
	return false;
}
/*!
*@brief	���s����B
*/
bool GameScene::Judgement()
{
	if (playerList[0].GetCardList().empty()) {
		//�v���C���[0�̏���
		return true;
	}
	else if (playerList[1].GetCardList().empty()) {
		//COM�̏���
		return true;
	}
	return false;
}
void GameScene::Update()
{
	switch (gameStep) {
	case enGameStep_DealCards: {
		//�J�[�h��z��B
		int numPlayerNo = 0;
		while (true) {
			Card* card = cardDeck.GetUnuseCardRandom();
			if (card == NULL) {
				//�S���z��I������B
				break;
			}
			playerList[numPlayerNo].AddCard(card);
			numPlayerNo = (numPlayerNo + 1) % NUM_PLAYER;
		}
		for (int i = 0; i < NUM_PLAYER; i++) {
			AddGO(0, &playerList[i]);
			playerList[i].SetPlayerNo(i);
		}
		//�J�[�h�̈�������ɂȂ�v���C���[��ݒ�B
		playerList[0].SetTargetPlayer(&playerList[1]);
		playerList[1].SetTargetPlayer(&playerList[0]);
		//�܂��̓v���C���[�̎�ԁB
		playerList[0].ChangeState(Player::enStateSelectCard);
		gameStep = enGameStep_SelectPlayer;
	}break;
	case enGameStep_SelectPlayer:
		if (playerList[0].GetState() == Player::enStateIdle) {
			//�v���C���[�I���I���B
			if (Judgement()) {
				//�����������B
				gameStep = enGameStep_Over;
			}
			else {
				//COM�̎�ԁB
				playerList[1].ChangeState(Player::enStateSelectCard);
				gameStep = enGameStep_SelectCom;
			}
		}
		break;
	case enGameStep_SelectCom:
		if (playerList[1].GetState() == Player::enStateIdle) {
			//COM�I���I���B
			if (Judgement()) {
				//�����������B
				gameStep = enGameStep_Over;
			}
			else {
				//�v���C���[�̎�ԁB
				playerList[0].ChangeState(Player::enStateSelectCard);
				gameStep = enGameStep_SelectPlayer;
			}
		}
		break;
	case enGameStep_Over:
		MessageBox(NULL, "����", "�����", MB_OK);
		//�^�C�g���ɖ߂�B
		DeleteGO(this);
		NewGO<TitleScene>(0);
		break;
	}
}