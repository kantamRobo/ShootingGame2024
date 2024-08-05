
#include "RootObject3D.h"

#include "Enemy3D.h"


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

	sphere.DrawDebug(position);
	for (int i = 0; i < 10; i++)
	{
		ammo[i]->Update3D();
		if (isEnemy)
		{
			position.x -= 20;
			if (this->position.x < X_LIMIT)
			{
				position.z -= 50;
			}
		}


	}
}

void Enemy3D::Update(char* input)
{
}
