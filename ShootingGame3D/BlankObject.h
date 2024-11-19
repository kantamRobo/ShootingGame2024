#pragma once

#include "RootObject3D.h"
class BlankObject:public RootObject3D
{

public:
	BlankObject() {};
	BlankObject(const VECTOR& in_pos,const std::shared_ptr<RootObject3D> parentobj =nullptr) { 
		position = in_pos;
	    parent = parentobj;
		//TODO:“–‚½‚è”»’è
	}
};
	
