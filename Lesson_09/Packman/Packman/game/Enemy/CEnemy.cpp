/*!
 * @brief	“G
 */

#include "stdafx.h"
#include "Packman/game/enemy/CEnemy.h"
#include "tkEngine/graphics/tkEffect.h"
#include "Packman/game/CGameManager.h"

CSphereShape*	CEnemy::m_sphere = nullptr;
void CEnemy::Awake()
{
	m_position = CVector3::Zero;
}
void CEnemy::Start()
{
}
void CEnemy::Update()
{
}
void CEnemy::Render(tkEngine::CRenderContext& renderContext)
{
}
void CEnemy::Build( const CVector3& pos )
{
}
void CEnemy::CreateShape(float radius)
{
}
void CEnemy::ReleaseShape()
{
}