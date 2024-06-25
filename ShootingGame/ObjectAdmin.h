#pragma once
#include <memory>
class Ammo;
class ObjectAdmin
{
	std::shared_ptr<RootObject> object[256];
	void judge();
};

