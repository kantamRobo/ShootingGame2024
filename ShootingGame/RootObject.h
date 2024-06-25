#pragma once
//’ŠÛƒNƒ‰ƒX

#include <memory>
class Ammo;
class RootObject
{
public:
	VECTOR position = VGet(0, 0, 0);
	std::shared_ptr<Ammo> ammo[10];
	int radius = 10;
	virtual void Draw()=0;

	
	virtual void Create(double, double) = 0;
	virtual void Update() = 0;
	virtual void Update(char* input) = 0;
};

