#pragma once
//���ۃN���X

#include <memory>
#include <DxLib.h>
#include "ICamera.h"
class IRootObject
{
public:
	IRootObject() {};
	IRootObject(const VECTOR& in_position);
	VECTOR position = VGet(0, 0, 0);
	
	bool isActive = true;
	bool isEnemy;//���@��������false,�G��true
	//�����Ă���t���O���Ⴄ�I�u�W�F�N�g���m
	//�ɑ΂��čU�����L���ɂȂ�
	int radius = 0;
	virtual void Draw()=0;
	int rapid = 0;
	
	int health = 10;
public:
	
	
	
};

