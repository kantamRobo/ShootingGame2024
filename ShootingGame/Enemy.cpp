#include "Ammo.h"
#include "Player.h"
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
	isEnemy = true;
	radius = 20;
}


void Enemy::Update()
{
	
}


