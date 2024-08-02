

#include "RootObject3D.h"


void RootObject3D::Init3D( const TCHAR* filepath,const VECTOR& in_position)
{
	position = in_position;
	
	
	handle = MV1LoadModel(filepath);
	for (int i = 0; i < 10; i++)
	{
		ammo[i] = std::make_shared<Ammo3D>();
	}
}

void RootObject3D::Draw3D(const VECTOR& vector)
{

	MV1SetPosition(handle, position);

	MV1DrawModel(handle);
}

void RootObject3D::Update(const VECTOR& vec)
{
	Draw3D(vec);
	
	sphere.DrawDebug(position);
	for (int i = 0; i < 10; i++)
	{
		ammo[i] -> Update3D();
	}
}

void RootObject3D::Attack3D()
{
	rapid++;

	rapid %= RAPID_RATE;

	if (rapid == 1) {

		if (ammo[ammoindex]->isActive == false) {
			ammo[ammoindex]->Shot3D(this->position.x, this->position.y,this->position.z);
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
		ammo[i] = std::make_shared<Ammo3D>();
		ammo[i]->isActive = false;
	}
}
