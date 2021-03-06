#pragma once
#include "tkEngine/character/tkCharacterController.h"

class Player : public IGameObject
{
public:
	//ここからメンバ関数。
	Player();
	~Player();
	void Start();
	void Update();
	void Render(CRenderContext& renderContext);
	//ここからメンバ変数。
	CSkinModel				skinModel;					//スキンモデル。
	CSkinModelData			skinModelData;				//スキンモデルデータ。
	CCharacterController	characterController;		//キャラクタ―コントローラー。
	CVector3				position = CVector3::Zero;	//座標。
};

