#pragma once
//抽象クラス

#include <memory>
#include <DxLib.h>
class Ammo3D;
class IRootObject
{
public:
	
	VECTOR position = VGet(0, 0, 0);
	std::shared_ptr<Ammo3D> ammo[10];
	bool isActive = true;
	bool isEnemy;//自機だったらfalse,敵はtrue
	//立っているフラグが違うオブジェクト同士
	//に対して攻撃が有効になる
	int radius = 0;
	virtual void Draw()=0;
	int rapid = 0;
	
	int health = 10;
public:
	
	virtual void Update() = 0;
	virtual void Update(char* input) = 0;
};

