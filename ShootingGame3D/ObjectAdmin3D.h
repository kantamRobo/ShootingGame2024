#pragma once
#include <memory>
#include "SceneAdmin.h"

#include "Camera.h"
class RootObject3D;
class Ammo3D;
struct Sphere;
class ObjectAdmin3D
{
public:
	int TITLE = 0;
	int GAMEOVER = 0;
	int CLEAR = 0;
	std::shared_ptr<RootObject3D> object[256];
	std::shared_ptr<Ammo3D> ammo3d[10];
	STATUS status = STATUS::TITLE;
	Camera camera;
public:
	int rapid = 0;
	virtual void Init3D();
	virtual void Update3D(char* input);
	virtual void Draw3D();
	void judge3D();
	std::shared_ptr<Ammo3D> ammo[10];
	
	
};

