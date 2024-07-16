#include "Camera.h"

void Camera::Init(const VECTOR& playerpos,const VECTOR& enemypos)
{

	auto target =VGet((playerpos.x + enemypos.x) / 2, position.y, (playerpos.x + enemypos.x) / 2);
	
	SetCameraNearFar(100.0f, 15000.0f);
	SetCameraPositionAndTarget_UpVecY(position, target);

}

void Camera::Update()
{
}
