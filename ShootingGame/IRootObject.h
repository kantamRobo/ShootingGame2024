#pragma once
//���ۃN���X

#include <memory>
#include <DxLib.h>
class Ammo3D;
class IRootObject
{
public:
	
	VECTOR position = VGet(0, 0, 0);
	std::shared_ptr<Ammo3D> ammo[10];
	bool isActive = true;
	bool isEnemy;//���@��������false,�G��true
	//�����Ă���t���O���Ⴄ�I�u�W�F�N�g���m
	//�ɑ΂��čU�����L���ɂȂ�
	int radius = 0;
	virtual void Draw()=0;
	int rapid = 0;
	
	int health = 10;
public:
	
	virtual void Update() = 0;
	virtual void Update(char* input) = 0;
};

