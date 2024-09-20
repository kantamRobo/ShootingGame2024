#include "RootObject3D.h"
#include "Player3.h"
#include "Enemy3D.h"
#include "DEFINE3D.h"
#include "ObjectAdmin3D.h"
#include <DxLib.h>


void ObjectAdmin3D::Init3D()
{
	
	object[0] = std::make_shared<Player3>(VGet(100.0f, 580.0f, 500.0f));
	
	
    object[0]->Init3D(L"C:\\Users\\hiz108\\source\\repos\\ShootingGame2024\\ShootingGame3D\\モデル\\無題.mv1");
	object[0]->isEnemy = false;
	for (int enemyindex = 1; enemyindex < ENEMY_INDICES; enemyindex++) {
		auto x = 0;
		object[enemyindex] = std::make_shared<Enemy3D>((VGet(150.0f, 580.0f, 2270.0f)));
	
	
	}
	object[1]->Init3D(L"C:\\Users\\hiz108\\source\\repos\\ShootingGame2024\\ShootingGame3D\\モデル\\Enemy.mv1");
	//x += 100;
	object[1]->isEnemy = true;
	camera.Init(object[0]->position, object[1]->position);
}

void ObjectAdmin3D::Update3D(char* input)
{
	camera.Update(input,object[0]->position);
	object[0]->Update(input);

	//プレイヤーモデルをカメラの座標空間に変換
	
	
	auto ModelScale = MGetScale(VGet(0.1f, 0.1f, 0.1f));
	auto Modelrotworld = MGetRotY(DX_PI_F / 4.0f);
	auto translation = MGetTranslate(object[0]->position);
	MATRIX ModelWorld = MMult(MMult(ModelScale, Modelrotworld), translation);
	
	auto out = MMult(ModelWorld, camera.GetViewMatrix());
	
	for (int enemyindex = 1; enemyindex < ENEMY_INDICES; enemyindex++) {
		auto x = 0;
		//object[enemyindex]->Update(VGet(200, 200, 500));
	
	}
	object[1]->Update();
	object[0]->Update_Core3D();
	object[1]->Update_Core3D();
	Check_ObjectIsActive();


}

void ObjectAdmin3D::Draw3D()
{
}


void ObjectAdmin3D::Check_ObjectIsActive()
{
	for (int i = 0; i < OBJECT_INDICES; i++) {
		if (object[i]->isActive) {
			//敵、プレイヤーが描画されている状態なら
			Trigger_Intersect3D();//衝突判定の第一段階に移る
		}
	}
}
void ObjectAdmin3D::Trigger_Intersect3D()
{
	//objectindexは弾を撃った側のオブジェクトを指す。targetindexは弾が当たった側のオブジェクトを指す。
	//この二つのオブジェクトの、敵フラグが立っているかを比較して、一致しなければ、つまり敵とプレイヤーに分かれていたら
	//衝突判定に移動する。
	for (int objectindex = 0; objectindex < OBJECT_INDICES; objectindex++)
	{
		for (int targetindex = 0; targetindex < OBJECT_INDICES; targetindex++) {
			if (object[objectindex]->isEnemy != object[targetindex]->isEnemy) {
				Test_Intersect3D(objectindex, targetindex);
		}
		}
		
	}
}

void ObjectAdmin3D::Test_Intersect3D(int objectindex,int targetindex) {

	//Trigger_Intersect3D()の、objectindexとtargetindexを引き継ぐ。
	//つまりobjectindex側のオブジェクトが弾を撃った側のオブジェクトで、
	//targetindexは弾が当たった側のオブジェクトになる
	//Sphere::Intersectで衝突判定を行う。
	//弾を撃つ側の弾と、撃たれる側の球体の衝突判定をおこなう
	//真ならHITをコンソールに出力する。
	for (int ammoindex = 0; ammoindex < AMMO_INDICES; ammoindex++) {
		if (Sphere::Intersect(object[objectindex]->ammo[ammoindex]->sphere, object[targetindex]->sphere))
		{
	  		
			DrawFormatString(600, 200, GetColor(255, 100, 0), L"HIT");
			}
		}
	

}


//TODO:球体の位置情報の更新処理を、RootObject3Dに組み込む。この際、Update処理としてUpdate_Core関数を作り、そこに実装する。