#include "ObjectAdmin.h"
#include "Ammo.h"
void ObjectAdmin::judge()
{
	int bullet_x = Object[i]->GetAmmo(b)->GetPosX();

	int bullet_y = Object[i]->GetAmmo(b)->GetPosY();

	double bullet_area = Object[i]->GetAmmo(b)->GetHitZone();


	int target_x = Object[t]->GetPosX();

	int target_y = Object[t]->GetPosY();

	double target_area = Object[t]->GetHitZone();
	//弾と被弾するUnitとの距離よりこれらの半径の合計が大きく、タイプが飛行タイプなら被弾している事になる

	//弾のx座標を計算する
	float bullet_x = ammo[i].position.x;
	//弾のy座標を計算する
	float bullet_y = ammo[i].position.y;
	//弾の半径を計算する
	float radius = ammo[i].radius;
	if
		((bullet_x - target_x)
			*
			(bullet_x - ((target_x)+
				(bullet_y - target_y)
				*
				(bullet_y - target_y)
				< (bullet_area + target_area)
				*
				(bullet_area + target_area))
	{

		Object[t]->Hit(Object[i]->GetAmmo(b));
		Object[i]->GetAmmo(b)->DestroyAmmo();
		score += 20;
		NumofRepeledEnemy += 20;
	}

}
