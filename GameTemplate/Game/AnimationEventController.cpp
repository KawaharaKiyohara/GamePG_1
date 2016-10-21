/*!
 * @brief	�A�j���[�V�����C�x���g�R���g���[���B
 */

#include "stdafx.h"
#include "AnimationEventController.h"
#include "DamageCollisionWorld.h"

AnimationEventController::AnimationEventController() :
	animation(nullptr),
	animNoLastFrame(-1),
	skinModel(nullptr)
{
}
AnimationEventController::~AnimationEventController()
{
}
void AnimationEventController::Init(CSkinModel* skinModel, CAnimation* animation, AnimationEventGroup* eventGroupTbl, int tblSize )
{
	TK_ASSERT(animation->GetNumAnimationSet() == tblSize, "tblSize is invalid");
	this->skinModel = skinModel;
	this->animation = animation;
	eventGroupExTbl.resize(tblSize);
	for (int i = 0; i < tblSize; i++) {
		eventGroupExTbl[i].eventGroup = eventGroupTbl[i];
		memset(eventGroupExTbl[i].invokeFlags, 0, sizeof(eventGroupExTbl[i].invokeFlags));
	}
}
void AnimationEventController::InvokeAnimationEvent(const AnimationEvent& event)
{
	switch (event.eventType) {
	case eAnimationEventType_EmitDamageToEnemyCollision: {
		//�G�Ƀ_���[�W��^����R���W�����̔����B
		CMatrix* bone = skinModel->FindBoneWorldMatrix(event.strArg[0]);
		CVector3 pos = event.vArg[0];
		bone->Mul(pos);
		g_damageCollisionWorld->Add(event.fArg[1], pos, event.fArg[0], event.iArg[0], DamageCollisionWorld::enDamageToEnemy, event.iArg[1]);
	}break;
	case eAnimationEventType_EmitDamageToPlayerCollision: {
		//�v���C���[�Ƀ_���[�W��^����R���W�����̔����B
		CMatrix* bone = skinModel->FindBoneWorldMatrix(event.strArg[0]);
		CVector3 pos = event.vArg[0];
		bone->Mul(pos);
		g_damageCollisionWorld->Add(event.fArg[1], event.vArg[0], event.fArg[0], event.iArg[0], DamageCollisionWorld::enDamageToPlayer, event.iArg[1]);
	}break;
	default:
		break;
	}
}
void AnimationEventController::Update()
{
	TK_ASSERT(animation != nullptr, "animation is null");
	int currentAnimNo = animation->GetPlayAnimNo();
	if (animNoLastFrame != -1 && animNoLastFrame != currentAnimNo) {
		//�A�j���[�V�������؂�ւ�����B
		//�O�̃A�j���[�V�����̃C�x���g�����t���O������������B
		memset(eventGroupExTbl[animNoLastFrame].invokeFlags, 0, sizeof(eventGroupExTbl[animNoLastFrame].invokeFlags));
	}
	float animTime = animation->GetLocalAnimationTime();
	AnimationEventGroupEx& eventGroupEx = eventGroupExTbl[currentAnimNo];
	for (
		int i = 0;
		eventGroupEx.eventGroup.event[i].eventType != eAnimationEventType_Invalid;
		i++
		) {
		if (eventGroupEx.invokeFlags[i] == false) {
			//�܂��C�x���g���������Ă��Ȃ��B
			if (eventGroupEx.eventGroup.event[i].time <= animTime) {
				//�C�x���g�������鎞�Ԃ��o�߂����B
				InvokeAnimationEvent(eventGroupEx.eventGroup.event[i]);
				//�����ς݂̈�B
				eventGroupEx.invokeFlags[i] = true;
			}
		}
	}
	animNoLastFrame = currentAnimNo;
	
}