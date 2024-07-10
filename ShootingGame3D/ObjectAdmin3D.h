#pragma once
#include <memory>
#include "SceneAdmin.h"
#include "SphereCollision.h"
class RootObject3D;
class ObjectAdmin3D
{
public:
	int TITLE = 0;
	int GAMEOVER = 0;
	int CLEAR = 0;
	std::shared_ptr<RootObject3D> object[10];

	STATUS status = STATUS::TITLE;
public:
	int rapid = 0;
	virtual void Init3D();
	virtual void Update3D(char* input);
	virtual void Draw3D();
	void judge3D();

	bool Intersect(const Sphere& r1, const Sphere& r2)
	{
		if (!(r2.position.x - r1.position.x)* (r2.position.x - r1.position.x) + (r2.position.x - r1.position.x)* (r2.position.x - r1.position.x) + (r2.position.x - r1.position.x) * (r2.position.x - r1.position.x)
			<= (r2.radius + r1.radius) * (r2.radius + r1.radius))
		{
			return false;
	    }
		
		return true ;
	}
	
};

