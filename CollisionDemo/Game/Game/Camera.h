#pragma once
class Camera : public IGameObject
{
public:
	//�������烁���o�֐��B
	Camera();
	~Camera();
	void Start();
	void Update();
	const CMatrix& GetViewMatrix() const
	{
		return camera.GetViewMatrix();
	}
	const CMatrix& GetProjectionMatrix() const
	{
		return camera.GetProjectionMatrix();
	}
	//�������烁���o�ϐ��B
	CCamera camera;	//�J�����B
};

extern Camera* g_gameCamera ;

