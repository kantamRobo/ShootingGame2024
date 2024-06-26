#pragma once
//抽象クラス

#include <memory>
class Ammo;
class RootObject
{
public:
	VECTOR position = VGet(0, 0, 0);
	std::shared_ptr<Ammo> ammo[10];
	bool isActive = true;
	bool isEnemy;//自機だったらfalse,敵はtrue
	//立っているフラグが違うオブジェクト同士
	//に対して攻撃が有効になる
	int radius = 0;
	virtual void Draw()=0;
	int rapid = 0;
	int ammoindex = 0;
	int health = 10;
public:
	virtual void Create(double, double);
	void Attack();
	void EnemyMove();
	virtual void Update() = 0;
	virtual void Update(char* input) = 0;
};

