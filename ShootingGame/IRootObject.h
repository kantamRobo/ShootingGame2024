#pragma once
//抽象クラス

#include <memory>
#include <DxLib.h>
#include "ICamera.h"
class IRootObject
{
public:
	IRootObject() {};
	IRootObject(const VECTOR& in_position);
	VECTOR position = VGet(0, 0, 0);
	
	bool isActive = true;
	bool isEnemy;//自機だったらfalse,敵はtrue
	//立っているフラグが違うオブジェクト同士
	//に対して攻撃が有効になる
	int radius = 0;
	virtual void Draw()=0;
	int rapid = 0;
	
	int health = 10;
public:
	
	
	
};

