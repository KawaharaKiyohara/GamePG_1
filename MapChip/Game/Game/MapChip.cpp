#include "stdafx.h"
#include "MapChip.h"
#include "Camera.h"

MapChip::MapChip()
{
}


MapChip::~MapChip()
{
}
void MapChip::Init(const char* modelName, CVector3 position, CQuaternion rotation)
{
	//�t�@�C���p�X���쐬����B
	char filePath[256];
	sprintf(filePath, "Assets/modelData/%s.x", modelName );
	//���f���f�[�^�����[�h�B
	skinModelData.LoadModelData(filePath, NULL);
	//CSkinModel���������B
	skinModel.Init(&skinModelData);
	//�f�t�H���g���C�g��ݒ肵�āB
	skinModel.SetLight(&g_defaultLight);
	//���[���h�s����X�V����B
	//���̃I�u�W�F�N�g�͓����Ȃ��̂ŁA�������ň�񂾂����[���h�s����쐬����΂����B
	skinModel.Update(position, rotation, CVector3::One);
}
void MapChip::Update()
{
	//�������̎��ɍ쐬���Ă���̂ŉ������Ȃ��B
}
void MapChip::Render(CRenderContext& renderContext)
{
	skinModel.Draw(renderContext, g_gameCamera->GetViewMatrix(), g_gameCamera->GetProjectionMatrix());
}