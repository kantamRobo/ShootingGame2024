#pragma once
//抽象クラス

#include <memory>
#include <DxLib.h>

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
	virtual void Draw() = 0;
	int rapid = 0;

	int health = 10;


	int bulletcounter = 0;
	int ammoindex = 0;


	void AttackTrigger()
	{
		bulletcounter += 1;
		bulletcounter %= 5000;
		if (bulletcounter % 100 == 0) {
			ammoindex++;
			Attack3D(ammoindex);
		}
		else if (ammoindex == MAX_AMMO - 1)
		{
			ammoindex = 0;
		}
	}

	void Attack3D(int index)
	{



		ammo[index]->Attack3D(this->position);






	}

public:

	virtual void Update() = 0;
	virtual void Update(char* input) = 0;
};

