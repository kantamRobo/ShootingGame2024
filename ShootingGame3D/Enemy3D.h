#pragma once
class RootObject3D;
class Enemy3D:public RootObject3D
{
public:
	void Draw()override;
	void Update()override;
	void Update(char* input)override;
};

