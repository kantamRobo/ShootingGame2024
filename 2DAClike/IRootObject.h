#pragma once
//���ۃN���X

#include <memory>

#include "DEFINE.h"
#include "DEFINE2D.h"
#include "Ammo2D.h"

class IRootObject
{
public:
	IRootObject() {};
	IRootObject(const VECTOR& in_position);
	VECTOR position = VGet(0, 0, 0);
	bool isActive = true;
	bool isEnemy;//���@��������false,�G��true
	//�����Ă���t���O���Ⴄ�I�u�W�F�N�g���m
	//�ɑ΂��čU�����L���ɂȂ�
	int distance = 50;
	int radius = 10;
	int rapid = 10;
	std::shared_ptr<Ammo2D> ammo[256];
	int health = 10;


	int bulletcounter = 0;
	int ammoindex = 0;
	Circle circle;

	void AttackTrigger()
	{
		bulletcounter += 1;
		bulletcounter %= 5000;
		if (bulletcounter % 100 == 0) {
			ammoindex++;
			Attack2D(ammoindex);
		}
		else if (ammoindex == MAX_AMMO - 1)
		{
			ammoindex = 0;
		}
	}

	void Attack2D(int index)
	{



		ammo[index]->Attack2D(this->position);







	}

public:

	virtual void Update() = 0;
	virtual void Update(char* input) = 0;
};

