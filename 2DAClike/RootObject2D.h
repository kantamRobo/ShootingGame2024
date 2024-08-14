#pragma once
#include <DxLib.h>
#include <memory>
class RootObject2D
{


public:
	RootObject2D() {};
	int handle = 0;


	Circle sphere;
	RootObject2D(const Circle& in_sphere);
	void Init2D(const TCHAR* filepath);
	std::shared_ptr<Ammo2D> ammo[256];
	virtual void Draw2D(const VECTOR& vector);





	virtual void Update(char* input) = 0;
	virtual void Update() = 0;
	int bulletcounter = 0;
	int ammoindex = 0;

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



		ammo[index]->Attack3D(this->position);






	}
};



