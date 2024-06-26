#pragma once
//���ۃN���X

#include <memory>
class Ammo;
class RootObject
{
public:
	VECTOR position = VGet(0, 0, 0);
	std::shared_ptr<Ammo> ammo[10];
	bool isActive = true;
	bool isEnemy;//���@��������false,�G��true
	//�����Ă���t���O���Ⴄ�I�u�W�F�N�g���m
	//�ɑ΂��čU�����L���ɂȂ�
	int radius = 0;
	virtual void Draw()=0;
	int rapid = 0;
	int ammoindex = 0;
	int health = 10;
public:
	virtual void Create(double, double);
	void Attack();
	void EnemyMove();
	virtual void Update() = 0;
	virtual void Update(char* input) = 0;
};

