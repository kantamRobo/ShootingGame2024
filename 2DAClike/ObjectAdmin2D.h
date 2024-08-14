#pragma once
#include <memory>
#include <DxLib.h>
#include "SceneAdmin.h"
#include "RootObject2D.h"



class ObjectAdmin2D
{
public:
	int TITLE = 0;
	int GAMEOVER = 0;
	int CLEAR = 0;
	std::shared_ptr<RootObject2D> object[256];

	STATUS status = STATUS::TITLE;
	
public:
	int rapid = 0;
	
	void Init2D();
	void Update2D(char* input);
	void Draw2D();
	void Check_ObjectIsActive();
	void Trigger_Intersect2D();
	
	void Test_Intersect2D(int objectindex, int targetindex);
	

	



};

