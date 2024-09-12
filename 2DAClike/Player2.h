#pragma once
#include "RootObject2D.h"
class Player2:public RootObject2D
{
public:
	Player2(const VECTOR& vector) { position = vector;
	distance = 10; };
	virtual void  Update(char* input)override;
	
	void Update()override;
	float boostlimit = 10;
	// ボタンの状態を記録する変数
	bool isButtonPressed = false;
	bool isButtonReleased = true; // 初期状態ではボタンは離されている
};

