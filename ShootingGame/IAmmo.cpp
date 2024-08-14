#include "IAmmo.h"
#include "IAmmo.h"



IAmmo::IAmmo(const VECTOR& pos)
{
	//sphere.position = pos;

	//sphere.radius = 40;
	//ammomodel = MV1LoadModel(L"C:\\Users\\hatte\\source\\repos\\ShootingGame2024\\ShootingGame3D\\モデル\\弾.mv1");
}



void IAmmo::Draw()
{
	/*
	if (GetIsActive() == true) {
		MV1DrawModel(ammomodel);
		sphere.DrawDebug(position);
	}
	*/

}
void IAmmo::Update(const float AMMOVELOCITY)
{

	Draw();


	MV1SetPosition(ammomodel, position);
	if (GetIsActive() == true) {
		Move3D(AMMOVELOCITY);
	}

}


//弾が移動する
void IAmmo::Move(const float AMMOVELOCITY)
{
	position.z += AMMOVELOCITY;
}
//まだ撃ってない弾を探索する。
void Ammo::Attack3D(const VECTOR& shotpos)
{

	Trigger(shotpos);



}



void IAmmo::Trigger(const VECTOR& shotpos)
{


	//ダーティフラグを使う

		//Attack3Dが毎度呼び出されてしまい、結果位置がプレイヤーの位置に更新されている。
		//→一回だけ呼ぶ
	Shot3D(shotpos.x, shotpos.y, shotpos.z);

	SetIsActive(true);
	SetIsDirty(true);


}


//弾を発射する。正確に言うと、弾の位置を引数の位置に更新する。
void IAmmo::Shot3D(int m_x, int m_y, int m_z)
{


	SetPosition(VGet(m_x, m_y, m_z));






}


