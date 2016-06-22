#pragma once

#include <iostream>

class Player{
public:
	Player();
	~Player();
	void Init();
	void Update();
	void Render( CRenderContext& renderContext );
	bool IsHit(CVector3 pos);
	/////////////////////////////////////////
	//ここからメンバ変数。
	/////////////////////////////////////////
	CSkinModelData	modelData;		//モデルデータ。
	CSkinModel		model;			//モデル。
	CVector3		position;		//座標。
};