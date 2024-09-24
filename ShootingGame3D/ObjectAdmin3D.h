#pragma once
#include <memory>
#include "SceneAdmin.h"
#include "RootObject3D.h"

class ObjectAdmin3D
{
public:
	int TITLE = 0;
	int GAMEOVER = 0;
	int CLEAR = 0;
	std::shared_ptr<RootObject3D> object[256];
	Camera camera;
	STATUS status = STATUS::TITLE;
	
public:
	int rapid = 0;
	virtual void Init3D();
	virtual void Update3D(char* input);
	virtual void Draw3D();
	void Check_ObjectIsActive();
	void Trigger_Intersect3D();
	void Test_Intersect3D(int objectindex, int targetindex);
	

	
	
};

