#include "DEFINE3D.h"
#include "RootObject3D.h"

#include "Enemy3D.h"





void Enemy3D::Draw()
{
}


void Enemy3D::Update(Camera* camera,char* input)
{
	Draw3D(position);
	for (int i = 0; i < MAX_AMMO; i++) {
		ammo[i]->Update(ENEMY_BULLET_SPEED);

	}



	AttackTrigger();
}
