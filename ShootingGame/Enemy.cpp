#include "Enemy.h"
#include "DEFINE.h"

void Enemy::Draw()
{
	DrawCircle(position.x, position.y, radius, Color, TRUE);
}


void Enemy::Create(double xpos, double ypos)
{
	position.x = xpos;
	position.y = ypos;
	//プレイヤーキャラクターの場所を決める。
 //xpos,yposというのは、「関数(かんすう)の引数(ひきすう)」と言われるもので、
//この関数を呼び出すときに、ゲームが始まったときに、プレイヤーが出てくる場所
//はどこにするか？というのを決めるのに使う。
	for (int i = 0; i < 10; i++)
	{
		ammo[i] = std::make_shared<Ammo>();
	}
}

void Enemy::Move()
{
	position.x += 2;

	if (position.x > SCREEN_WIDTH_MAX)
	{
		position.x = 0;
		position.y += 50;
	}

	if (position.y > SCREEN_HEIGHT_MAX)
	{
		position.y = 0;
	}
	for (int i = 0; i < 10; i++)
	{

		ammo[i]->EnemyUpdate();

	}

}

void Enemy::Attack(const Player& player)
{
	
		if (ammo[ammoindex]->GetIsActive() == false) {
			ammo[ammoindex]->Shot(this->position.x, this->position.y);
			DrawFormatString(50, 70, GetColor(0, 255, 0), L"弾:%d", ammoindex);
			ammo[ammoindex]->isActive = true;
			ammoindex++;
			if (ammoindex == MAX_AMMO - 1) {
				for (int j = 0; j < MAX_AMMO; j++)
				{
					if (ammo[j]->isActive == true) {
						ammo[j]->isActive = false;
					}
					ammoindex = 0;
				}

				//この全探索では計算量が敵ユニットと被るとどうなるのか・・・・最大でn^10?
				//そん時考えるが、念のため二分探索を書けるよう練習しておく。
			}
		}
	
	
}

