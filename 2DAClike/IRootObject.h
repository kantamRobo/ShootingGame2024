#pragma once
//���ۃN���X

#include <memory>
#include <DxLib.h>

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

