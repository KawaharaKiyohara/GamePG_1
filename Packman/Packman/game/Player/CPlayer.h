/*!
 * @brief	プレイヤー
 */

#ifndef _CPLAYER_H_
#define _CPLAYER_H_

#include "tkEngine/shape/tkSphereShape.h"

class CPlayer : public tkEngine::IGameObject{
public:
	CPlayer() :
		m_position(CVector3::Zero)
	{
	}
	~CPlayer(){}
	/*!
	 *@brief	Updateが初めて呼ばれる直前に一度だけ呼ばれる処理。
	 */
	void Start() override final;
	/*!
	*@brief	Update関数が実行される前に呼ばれる更新関数。
	*/
	void PreUpdate() override final;
	/*!
	 *@brief	更新処理。60fpsなら16ミリ秒に一度。30fpsなら32ミリ秒に一度呼ばれる。
	 */
	void Update() override final;
	/*!
	 *@brief	描画処理。60fpsなら16ミリ秒に一度。30fpsなら32ミリ秒に一度呼ばれる。
	 */
	void Render(tkEngine::CRenderContext& renderContext) override final;
	/*!
	 *@brief	構築。
	 *必ず先にCreateShapeを一度コールしておく必要がある。
	 */
	void Build( const CVector3& pos );
	/*!
	*@brief	移動処理。
	*/
	void Move();
	/*!
	*@brief	座標を取得。
	*/
	const CVector3& GetPosition() const 
	{
		return m_position;
	}
	bool rightmoveflg = true;
	bool leftmoveflg = true;
	bool upmoveflg = true;
	bool downmoveflg = true;
	CVector3				m_position;
private:
	/*!
	*@brief	AABBの更新。
	*/
	void UpdateAABB();
private:
	tkEngine::CSphereShape	m_sphere;
	CMatrix					m_wvpMatrix;	//<ワールドビュープロジェクション行列。
	tkEngine::CIDMapModel	m_idMapModel;
	tkEngine::CShadowModel	m_shadowModel;	//!<シャドウマップへの書き込み用のモデル。
	float m_radius;		//!<半径。
	CVector3 Scale;
	CVector3 m_position2;
	CVector3 m_aabbMin;
	CVector3 m_aabbMax;
};

#endif 