#pragma once
//’ŠÛƒNƒ‰ƒX
class RootObject
{
public:
	VECTOR position = VGet(0, 0, 0);
	std::shared_ptr<Ammo> ammo[50];
	int radius = 10;
	virtual void Draw()=0;

	
	virtual void Create(double, double) = 0;
};

