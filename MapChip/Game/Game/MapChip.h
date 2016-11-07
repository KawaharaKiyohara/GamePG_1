#pragma once
class MapChip : public IGameObject
{
public:
	//�������烁���o�֐��B
	MapChip();
	~MapChip();
	void Init( const char* modelName, CVector3 position, CQuaternion rotation );
	void Update();
	void Render(CRenderContext& renderContext);

	//�������烁���o�ϐ��B
	CSkinModel			skinModel;		//�X�L�����f���B
	CSkinModelData		skinModelData;	//�X�L�����f���f�[�^�B
};

