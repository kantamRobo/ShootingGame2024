#pragma once

class RootObject3D;

class Enemy3D:public RootObject3D
{
public:
	Enemy3D();
	void Draw()override;
	virtual void Update()override;
	const int X_LIMIT = 200;
	const int Z_LMIIT = 50;
	void Update(char* input)override;
	
};

