#pragma once

//ゲームカメラクラス。
class GameCamera {
public:
	GameCamera();
	~GameCamera();
	void Update();
	//ビュー行列の取得。
	CMatrix GetViewMatrix();
	//プロジェクション行列の取得。
	CMatrix GetProjectionMatrix();
	/////////////////////////////////////////
	//ここからメンバ変数。
	/////////////////////////////////////////
	CCamera  camera;		//カメラ。
};

extern GameCamera* gameCamera;

