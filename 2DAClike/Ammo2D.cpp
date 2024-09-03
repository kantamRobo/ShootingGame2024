#include "Ammo2D.h"
#include <math.h>




Ammo2D::Ammo2D(const VECTOR& pos)
{
	circle.position = pos;

	circle.radius = 40;
	//ammomodel = MV1LoadModel(L"C:\\Users\\hatte\\source\\repos\\ShootingGame2024\\ShootingGame3D\\モデル\\弾.mv1");
}



void Ammo2D::Draw()
{
	if (isActive) {
		DrawCircle(position.x, position.y, static_cast<int>(radius), GetColor(0, 255, 0), TRUE);
	}
}
void Ammo2D::Update(const float AMMOVELOCITY,const VECTOR& objectpos,float objectangle)
{

	Draw();


	
	if (GetIsActive() == true) {
		Move2D(AMMOVELOCITY,objectpos,objectangle);
	}

}


//弾が移動する
void Ammo2D::Move2D(const float AMMOVELOCITY,const VECTOR& objectpos,float objectangle)
{
	
	
	
	
	
	position.x = (position.x + cos(m_angle) * -AMMOVELOCITY);
	position.y = (position.y + sin(m_angle) * -AMMOVELOCITY);
	
	
}
//まだ撃ってない弾を探索する。
void Ammo2D::Attack2D(const VECTOR& shotpos,float objectangle)
{

	Trigger(shotpos,objectangle);



}



void Ammo2D::Trigger(const VECTOR& shotpos,float objectangle)
{


	//ダーティフラグを使う

		//Attack3Dが毎度呼び出されてしまい、結果位置がプレイヤーの位置に更新されている。
		//→一回だけ呼ぶ
	Shot2D(shotpos.x, shotpos.y,objectangle);
	SetIsActive(true);
	


}


//弾を発射する。正確に言うと、弾の位置を引数の位置に更新する。
void Ammo2D::Shot2D(int m_x, int m_y,float angle)
{
	SetPosition(VGet(m_x, m_y,0));



	m_angle = angle;


}


