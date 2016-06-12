/*!
* @brief	敵。
*/
#pragma once

#include "tkEngine/shape/tkSphereShape.h"
#include "tkEngine/AI/tkPathFinding.h"

class CEnemy : public tkEngine::IGameObject {
public:
	/*!
	*@brief	コンストラクタ。
	*/
	CEnemy();
	/*!
	*@brief	デストラクタ。
	*/
	~CEnemy();
	/*!
	*@brief	インスタンスを生成した直後に一度だけ呼ばれる処理。</br>
	* Startより速いタイミングでコールされる。
	*/
	void Awake() override final;
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
	void Build(const CVector3& pos);
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
	/*!
	*@brief	経路探索用のノードを構築。
	*/
	void BuildNodes();
	/*!
	*@brief	移動処理。
	*/
	void Move();
private:
	static tkEngine::CSphereShape*		m_sphere;
	CMatrix								m_wvpMatrix;			//<ワールドビュープロジェクション行列。
	tkEngine::CIDMapModel				m_idMapModel;
	CVector3							m_position;
	CMatrix								m_worldMatrix;			//!<ワールド行列。
	tkEngine::CPathFinding				m_pathFinding;			//!<経路探索。
	std::vector<CPathFinding::SNode*>	m_nodes;				//!<経路探索用のノード。
	int									m_intervalFrame;		//!<インターバルタイム。
	std::vector<CPathFinding::SNode*>	m_root;					//!<プレイヤーまでのルート。
	int									currentRoot;			//!<プレイヤーまでのルート上で今どこのノードにいるか。
};
