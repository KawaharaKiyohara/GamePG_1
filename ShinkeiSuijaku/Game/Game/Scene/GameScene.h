#pragma once

#include "tkEngine/Sound/tkSoundSource.h"

/*!
 *@brief	ゲームシーン。
 */
class GameScene :
	public IGameObject
{
public:
	/*!
	 *@brief	コンストラクタ。
	 */
	GameScene();
	/*!
	 *@brief	デストラクタ。
	 */
	~GameScene();
	/*!
	 *@brief	開始関数。
	 *@details
	 * 初期化などをこの関数に実装してください。</br>
	 * この関数がtrueを返すと本館数は以降のフレームでは呼ばれなくなります。</br>
	 * そしてゲームオブジェクトの状態が初期化完了になりUpdate関数が呼ばれるようになります。</br>
	 *@return	trueが帰ってきたら初期化完了。
	 */
	bool Start() override;
	/*!
	 *@brief	更新関数。
	 */
	void Update() override;
	/*!
	*@brief	描画関数。
	*/
	void Render(CRenderContext& renderContext);
private:
	CCamera camera;								//!<カメラ。
	CLight  light;								//!<ライト。
	CSoundSource* bgmSource;					//!<BGMソース。
	CSkinModelDataHandle testModelDataHandle;	//!<テストモデルデータハンドル。
	CSkinModel testModel;						//!<テストモデル。
};

extern GameScene* g_gameScene;
