#pragma once

class Ball {
public:
	Ball();
	~Ball();
	void Init();
	void Update();
	void Render(CRenderContext& renderContext);
	/////////////////////////////////////////
	//�������烁���o�ϐ��B
	/////////////////////////////////////////
	CSkinModelData	modelData;		//���f���f�[�^�B
	CSkinModel		model;			//���f���B
	CVector3		position;		//���W�B
	CVector3		moveSpeed;		//�ړ����x�B
};