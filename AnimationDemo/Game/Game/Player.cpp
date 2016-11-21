#include "stdafx.h"
#include "Player.h"
#include "Camera.h"


enum {
	AnimationStand,		//立ち。
	AnimationWalk,		//歩き。
	AnimationRun,		//走り。
	AnimationJump,		//ジャンプ。
	AnimationAttack_00,	//攻撃00。
	AnimationAttack_01,	//攻撃01。
	AnimationAttack_02,	//攻撃02。
	AnimationDamage,	//ダメージ。
	AnimationDeath,		//死亡。
	NumAnimation,		//アニメーションの数。
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
	skinModel.SetLight(&g_defaultLight);	//デフォルトライトを設定。
	animation.PlayAnimation(currentAnimationNo);
}
void Player::Update()
{
	//AボタンとBボタンが押されたら補完なしのアニメーション再生を行う。
	if (Pad(0).IsTrigger(enButtonA)) {
		//Aボタンが押されたらアニメーション番号をインクリメントする。
		if (currentAnimationNo < NumAnimation - 1) {
			currentAnimationNo++;
			//アニメーションが切り替わったので再生リクエストを行う。
			animation.PlayAnimation(currentAnimationNo);
		}
	}
	else if (Pad(0).IsTrigger(enButtonB)) {
		//Bボタンが押されたらアニメーション番号をデクリメントする。
		if (currentAnimationNo > 0) {
			currentAnimationNo--;
			//アニメーションが切り替わったので再生リクエストを行う。
			animation.PlayAnimation(currentAnimationNo);
		}
	}
	//XボタンをYボタンが押されたら補間ありのアニメーション再生を行う。
	else if (Pad(0).IsTrigger(enButtonX)) {
		//Xボタンが押されたらアニメーション番号をインクリメントする。
		if (currentAnimationNo < NumAnimation - 1) {
			currentAnimationNo++;
			//アニメーションが切り替わったので再生リクエストを行う。
			//第二引数は補間時間。
			animation.PlayAnimation(currentAnimationNo, 0.3f);
		}
	}
	else if (Pad(0).IsTrigger(enButtonY)) {
		//Yボタンが押されたらアニメーション番号をデクリメントする。
		if (currentAnimationNo > 0) {
			currentAnimationNo--;
			//アニメーションが切り替わったので再生リクエストを行う。
			//第二引数は補間時間。
			animation.PlayAnimation(currentAnimationNo, 0.3f);
		}
	}

	animation.Update(1.0/60.0f);	
	//ワールド行列の更新。
	skinModel.Update(CVector3::Zero, CQuaternion::Identity, CVector3::One);
}
void Player::Render(CRenderContext& renderContext)
{
	skinModel.Draw(renderContext, g_gameCamera->GetViewMatrix(), g_gameCamera->GetProjectionMatrix());
}
