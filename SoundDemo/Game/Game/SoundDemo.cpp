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
	//サウンドソースのインスタンスを生成して、ゲームオブジェクトマネージャーに登録する。
	bgmSource = NewGO<CSoundSource>(0);
	//BGMをロードして初期化。
	bgmSource->Init("Assets/sound/BGM.wav");
	//ループフラグをtrueにして再生。
	bgmSource->Play(true);
}
void SoundDemo::Update()
{
	if (Pad(0).IsTrigger(enButtonA)) {
		if (bgmSource->IsPlaying()) {
			//BGM再生中なら止める。
			bgmSource->Stop();
		}
		else {
			//BGMを再生する。
			bgmSource->Play(true);
		}
	}
}