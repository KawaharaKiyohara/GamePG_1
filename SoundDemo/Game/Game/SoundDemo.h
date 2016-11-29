#pragma once
//サウンドデモのクラス。
class SoundDemo : public IGameObject
{
public:
	SoundDemo();
	~SoundDemo();
	void Start();
	void Update();
private:
	CSoundSource* bgmSource;		//BGMのサウンドソース。
};

