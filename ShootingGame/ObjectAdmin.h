#pragma once
#include <memory>
#include "Player.h"
#include "Enemy.h"
class Ammo;
class RootObject;
class ObjectAdmin
{
public:
	
	std::shared_ptr<Player> player;
	std::shared_ptr<Enemy> enemy[20];
	std::shared_ptr<RootObject> object[256];
	void judge();
	
public:
	void Init();
	void Update(char* input);
	void Draw();
};

