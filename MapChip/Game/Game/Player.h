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
	CSkinModel			skinModel;		//スキンモデル。
	CSkinModelData		skinModelData;	//スキンモデルデータ。

};

