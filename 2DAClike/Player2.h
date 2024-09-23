#pragma once
#include "RootObject2D.h"
class Player2:public RootObject2D
{
public:
	Player2(const VECTOR& vector) {
		position = vector;
		distance = 10;
		boostlimit = EditableBoostLimitParam;
		// コンストラクタで初期化
		moveDuration = 0.2f;  // 0.2秒間移動
		isMoving = false;
	};
	virtual void  Update(char* input)override;
	float inputdelta = 0;
	void Update()override;
	float boostlimit = 0;
	const float EditableBoostLimitParam = 0.4f;
	// ボタンの状態を記録する変数
	bool isButtonPressed = false;
	bool isButtonReleased = true; // 初期状態ではボタンは離されている

private:
	bool isMoving;          // プレイヤーが移動中かどうか
	float moveDuration;     // 移動する時間（秒）
	float moveStartTime;    // 移動を開始した時間
};

