#include "stdafx.h"
#include "Camera.h"


Camera* g_gameCamera;

Camera::Camera()
{
}


Camera::~Camera()
{
}
void Camera::Start()
{
	//�΂ߏォ�猩���낷�����̃J�����ɂ���
	camera.SetPosition( {8.0f, 8.0f, 8.0f});
	camera.SetTarget( {0.0f, 0.0f, 0.0f} );
}
void Camera::Update()
{
	camera.Update();
}