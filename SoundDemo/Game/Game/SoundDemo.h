#pragma once
//�T�E���h�f���̃N���X�B
class SoundDemo : public IGameObject
{
public:
	SoundDemo();
	~SoundDemo();
	void Start();
	void Update();
private:
	CSoundSource* bgmSource;		//BGM�̃T�E���h�\�[�X�B
};

