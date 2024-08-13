
#include "RootObject3D.h"

#include "Enemy3D.h"
#include <DEFINE2D.h>


Enemy3D::Enemy3D()
{
	
	sphere.position = position;
	sphere.radius = 150;
	
}
void Enemy3D::Draw()
{
}

void Enemy3D::Update()
{
	Draw3D(position);
	for (int i = 0; i < MAX_AMMO; i++) {
		ammo[i]->Update(-50);

	}
	sphere.DrawDebug(position);
	
		/*
		//Attack3D(-10);
		if (isEnemy)
		{
			position.x += 5;
			if (this->position.x > X_LIMIT)
			{
				position.z -= 10;
				position.x = ENEMY_START;
			}
		}
		*/
		AttackTrigger();

	
}

void Enemy3D::Update(char* input)
{
}
