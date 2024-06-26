#pragma once
#include <memory>
#include "Player.h"
#include "Enemy.h"
class Ammo;
class RootObject;
class ObjectAdmin
{
public:
	
	std::shared_ptr<RootObject> object[10];
	void judge();
	
public:
	int rapid = 0;
	void Init();
	void Update(char* input);
	void Draw();
};

