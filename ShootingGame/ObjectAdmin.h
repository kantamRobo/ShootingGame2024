#pragma once
#include <memory>
#include "Player.h"
#include "Enemy.h"
#include "SceneAdmin.h"
class Ammo;
class RootObject;
class ObjectAdmin
{
public:
	int TITLE = 0;
	int GAMEOVER = 0;
	int CLEAR = 0;
	std::shared_ptr<RootObject> object[10];
	
	STATUS status = STATUS::TITLE;
public:
	int rapid = 0;
	virtual void Init();
	virtual void Update(char* input);
	virtual void Draw();
	void judge();
};

