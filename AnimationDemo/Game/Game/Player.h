#pragma once

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
	CAnimation				animation;					//アニメーション。
	CVector3				position = CVector3::Zero;	//座標。
	int						currentAnimationNo = 0;		//現在のアニメーション番号。
};

