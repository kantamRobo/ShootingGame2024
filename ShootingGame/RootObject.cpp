#include "Ammo.h"
#include "RootObject.h"
#include "DEFINE.h"
void RootObject::Create(double in_x, double in_y)
{

	position.x = in_x;
	position.y = in_y;
	//プレイヤーキャラクターの場所を決める。
 //xpos,yposというのは、「関数(かんすう)の引数(ひきすう)」と言われるもので、
//この関数を呼び出すときに、ゲームが始まったときに、プレイヤーが出てくる場所
//はどこにするか？というのを決めるのに使う。
	for (int i = 0; i < 10; i++)
	{
		ammo[i] = std::make_shared<Ammo>();
		ammo[i]->isActive = false;
	}
}

void RootObject::Attack()
{

	rapid++;

	rapid %= RAPID_RATE;

	if (rapid == 1) {

		if (ammo[ammoindex]->isActive == false) {
			ammo[ammoindex]->Shot(this->position.x, this->position.y - );
			ammo[ammoindex]->isActive = true;
			DrawFormatString(50, 70, GetColor(0, 255, 0), L"弾:%d", ammoindex);
			
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
}

void RootObject::EnemyMove()
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
