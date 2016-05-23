/*!
 * @brief	パックマンが食べるアイテム。
 */

#pragma once

#include "tkEngine/shape/tkSphereShape.h"

class CFood : public tkEngine::IGameObject{
public:
	/*!
	*@brief	コンストラクタ。
	*@details
	* コンストラクタとはインスタンスが生成されたときに一度だけ呼ばれる特殊な関数。
	* クラス名が関数名になります。
	*/
	CFood();
	/*!
	 *@brief	Updateが初めて呼ばれる直前に一度だけ呼ばれる処理。
	 */
	void Start() override final;
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
	 *@brief	形状の生成。
	 *@param[in]	radius		半径。
	 */
	static void CreateShape(float radius);
	/*!
	 *@brief	形状の解放。
	 */
	static void ReleaseShape();
private:
	static tkEngine::CSphereShape*	m_sphere;
	CMatrix							m_wvpMatrix;			//<ワールドビュープロジェクション行列。
	tkEngine::CIDMapModel			m_idMapModel;
	CVector3						m_position;				//!<座標。
	CMatrix							m_worldMatrix;			//!<ワールド行列。
};
