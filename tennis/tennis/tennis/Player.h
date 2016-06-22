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
	//�������烁���o�ϐ��B
	/////////////////////////////////////////
	CSkinModelData	modelData;		//���f���f�[�^�B
	CSkinModel		model;			//���f���B
	CVector3		position;		//���W�B
};