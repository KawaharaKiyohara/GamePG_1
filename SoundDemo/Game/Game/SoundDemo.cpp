#include "stdafx.h"
#include "SoundDemo.h"
#include "tkEngine/Sound/tkSoundSource.h"

SoundDemo::SoundDemo()
{
	bgmSource = NULL;
}


SoundDemo::~SoundDemo()
{
	if (bgmSource != NULL) {
		DeleteGO(bgmSource);
	}
}
void SoundDemo::Start()
{
	//�T�E���h�\�[�X�̃C���X�^���X�𐶐����āA�Q�[���I�u�W�F�N�g�}�l�[�W���[�ɓo�^����B
	bgmSource = NewGO<CSoundSource>(0);
	//BGM�����[�h���ď������B
	bgmSource->Init("Assets/sound/BGM.wav");
	//���[�v�t���O��true�ɂ��čĐ��B
	bgmSource->Play(true);
}
void SoundDemo::Update()
{
	if (Pad(0).IsTrigger(enButtonA)) {
		if (bgmSource->IsPlaying()) {
			//BGM�Đ����Ȃ�~�߂�B
			bgmSource->Stop();
		}
		else {
			//BGM���Đ�����B
			bgmSource->Play(true);
		}
	}
}