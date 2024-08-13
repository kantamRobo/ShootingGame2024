#pragma once
#include <memory>
#include "DEFINE.h"
#include "IRootObject.h"
#include "SphereCollision.h"
#include "Ammo3D.h"
class RootObject3D:public IRootObject
{
public:
	int handle=0;
	
	
	Sphere sphere;
	virtual void Init3D(const TCHAR* filepath, const VECTOR& position);
	std::shared_ptr<Ammo3D> ammo[256];
	virtual void Draw3D(const VECTOR& vector);

	

	

	virtual void Update(char* input) = 0;
	virtual void Update()=0;
	int bulletcounter = 0;
	int ammoindex = 0;


	void AttackTrigger()
	{
		bulletcounter++;
		bulletcounter %= 1200;
		if (bulletcounter % 4 == 0) {
			ammoindex++;
			Attack3D(ammoindex);
		}
		else if (ammoindex == MAX_AMMO-1)
		{
			ammoindex = 0;
		}
	}

	void Attack3D(int index)
	{



		ammo[index]->Attack3D(this->position);






	}
};

