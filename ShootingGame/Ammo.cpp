#include "Ammo.h"
#include "DEFINE.h"


Ammo::Ammo():AMMOVELOCITY(10.0f)
{

}
//Player����e���o��(�v���C���[�̈ʒu����I�t�Z�b�g���v�Z���A
//��������e������)
void Ammo::Shot(int m_x, int m_y)
{
	
	position.x = m_x;
	position.y = m_y;
	
}

void Ammo::Update()
{
	
		DrawCircle(position.x, position.y, 5, GetColor(0, 255, 0), TRUE);
	
		
		position.y -= AMMOVELOCITY;
	
		
	
	
	if (position.x < SCREEN_HEIGHT_MAX || SCREEN_HEIGHT_MAX < position.x ||
		position.y < SCREEN_WIDTH_MIN || SCREEN_WIDTH_MAX < position.y)
	{
		isActive = false;
	}
	

}


void Ammo::EnemyUpdate()
{

	DrawCircle(position.x, position.y, 5, GetColor(0, 255, 0), TRUE);


	position.y += AMMOVELOCITY;




	if (position.x < SCREEN_HEIGHT_MAX || SCREEN_HEIGHT_MAX < position.x ||
		position.y < SCREEN_WIDTH_MIN || SCREEN_WIDTH_MAX < position.y)
	{
		isActive = false;
	}


}
