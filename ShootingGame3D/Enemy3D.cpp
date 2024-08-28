
#include "RootObject3D.h"

#include "Enemy3D.h"
#include "DEFINE3D.h"



void Enemy3D::Draw()
{
}

void Enemy3D::Update()
{
	Draw3D(position);
	for (int i = 0; i < MAX_AMMO; i++) {
		ammo[i]->Update(ENEMY_BULLET_SPEED);

	}
	
	
	
		AttackTrigger();

	
}

void Enemy3D::Update(char* input)
{
}
