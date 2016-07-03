#include "stdafx.h"
#include "UnityChan.h"


extern CCamera*			g_camera;				//�J�����B
/*!
 * @brief	�J�n
 */
void UnityChan::Start()
{
	skinModelData.LoadModelData("Assets/modelData/Unity.X", &animation);
	normalMap.Load("Assets/modelData/utc_nomal.tga");
	//���W���������B
	position.x = 0.0f;
	position.y = 0.0f;
	position.z = 0.0f;
	skinModel.Init(&skinModelData);
	skinModel.SetLight(&light);
	skinModel.SetNormalMap(&normalMap);

	camera.SetPosition(CVector3(0.0f, 1.0f, 2.0f));
	camera.SetTarget(CVector3(0.0f, 0.5f, 0.0f));

	camera.SetFar(1000.0f);
	camera.Update();
	g_camera = &camera;
	light.SetDiffuseLightDirection(0,  CVector3(0.707f, 0.0f, -0.707f));
	light.SetDiffuseLightDirection(1, CVector3(-0.707f, 0.0f, -0.707f));
	light.SetDiffuseLightDirection(2, CVector3(0.0f, 0.707f, -0.707f));
	light.SetDiffuseLightDirection(3, CVector3(0.0f, -0.707f, -0.707f));

	light.SetDiffuseLightColor(0, CVector4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetDiffuseLightColor(1, CVector4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetDiffuseLightColor(2, CVector4(0.3f, 0.3f, 0.3f, 1.0f));
	light.SetDiffuseLightColor(3, CVector4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetAmbinetLight(CVector3(0.3f, 0.3f, 0.3f));
	animation.SetAnimationEndTime(AnimationRun, 0.8);
	currentAnimSetNo = AnimationStand;
	animation.PlayAnimation(AnimationStand);
}
/*!
 * @brief	�X�V�B
 */
void UnityChan::Update()  
{
	//�A�j���[�V�����Đ��̃T���v���R�[�h�B
	animation.Update(1.0f / 60.0f);
	static float angle = 0.0f;
	if (KeyInput().IsRightPress()) {
		angle += 0.01f;
	}
	else if (KeyInput().IsLeftPress()) {
		angle -= 0.01;
	}
	camera.Update();

	CVector3 rotAxis(-1.0f, 1.0f, 0.0f);
	rotAxis.Normalize();
	//Unity�������񂷁B
	CQuaternion qRot = CQuaternion::Identity;
	qRot.SetRotation(rotAxis, CMath::DegToRad(-90.0f));
	
	skinModel.UpdateWorldMatrix(position, qRot, CVector3::One);
	if (KeyInput().IsTrgger(CKeyInput::enKeyA)) {
		currentAnimSetNo++;
		currentAnimSetNo %= animation.GetNumAnimationSet();
		animation.PlayAnimation(currentAnimSetNo);
	}
	if (KeyInput().IsTrgger(CKeyInput::enKeyB)) {
		currentAnimSetNo++;
		currentAnimSetNo %= animation.GetNumAnimationSet();
		animation.PlayAnimation(currentAnimSetNo, 0.1f);
	}
}
/*!
 * @brief	�`��B
 */
void UnityChan::Render( CRenderContext& renderContext ) 
{
	skinModel.Draw(renderContext, camera.GetViewMatrix(), camera.GetProjectionMatrix());
}