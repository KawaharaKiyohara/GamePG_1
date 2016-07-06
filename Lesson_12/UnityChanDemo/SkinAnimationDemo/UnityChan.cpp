#include "stdafx.h"
#include "UnityChan.h"


extern CCamera*			g_camera;				//�J�����B
/*!
 * @brief	�J�n
 */
void UnityChan::Start()
{
	rotation.x = 0.0f;
	rotation.y = 0.0f;
	rotation.z = 0.0f;
	rotation.w = 1.0f;
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
	int nextAnimNo = AnimationStand;
	CQuaternion qAdd = CQuaternion::Identity;
	if (KeyInput().IsRightPress()) {
		qAdd.SetRotation(CVector3(0.0f, 1.0f, 0.0f), CMath::DegToRad(-1.0f));
	}
	else if (KeyInput().IsLeftPress()) {
		qAdd.SetRotation(CVector3(0.0f, 1.0f, 0.0f), CMath::DegToRad(1.0f));
	}
	else if (KeyInput().IsUpPress()) {
		qAdd.SetRotation(CVector3(1.0f, 0.0f, 0.0f), CMath::DegToRad(1.0f));
	}
	else if (KeyInput().IsDownPress()) {
		qAdd.SetRotation(CVector3(1.0f, 0.0f, 0.0f), CMath::DegToRad(-1.0f));
	}
	if (nextAnimNo != currentAnimSetNo) {
		currentAnimSetNo = nextAnimNo;
		animation.PlayAnimation(nextAnimNo, 0.2f);
	}
	camera.Update();

	CVector3 rotAxis(-1.0f, 1.0f, 0.0f);
	rotAxis.Normalize();
	//Unity�������񂷁B
	rotation.Multiply(rotation, qAdd);
	skinModel.UpdateWorldMatrix(position, rotation, CVector3(1.0f, 1.0f, 1.0f));
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
