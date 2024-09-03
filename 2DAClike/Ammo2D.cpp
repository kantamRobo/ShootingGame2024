#include "Ammo2D.h"




Ammo2D::Ammo2D(const VECTOR& pos)
{
	circle.position = pos;

	circle.radius = 40;
	//ammomodel = MV1LoadModel(L"C:\\Users\\hatte\\source\\repos\\ShootingGame2024\\ShootingGame3D\\モデル\\弾.mv1");
}



void Ammo2D::Draw()
{
	DrawCircle(position.x, position.y, static_cast<int>(radius), GetColor(255,255,255), TRUE);

}
void Ammo2D::Update(const float AMMOVELOCITY)
{

	Draw();


	
	if (GetIsActive() == true) {
		Move2D(AMMOVELOCITY);
	}

}


//弾が移動する
void Ammo2D::Move2D(const float AMMOVELOCITY)
{
	position.y += AMMOVELOCITY;
}
//まだ撃ってない弾を探索する。
void Ammo2D::Attack2D(const VECTOR& shotpos)
{

	Trigger(shotpos);



}



void Ammo2D::Trigger(const VECTOR& shotpos)
{


	//ダーティフラグを使う

		//Attack3Dが毎度呼び出されてしまい、結果位置がプレイヤーの位置に更新されている。
		//→一回だけ呼ぶ
	Shot2D(shotpos.x, shotpos.y);

	SetIsActive(true);
	


}


//弾を発射する。正確に言うと、弾の位置を引数の位置に更新する。
void Ammo2D::Shot2D(int m_x, int m_y)
{


	SetPosition(VGet(m_x, m_y,0));






}


