#include "RootObject3D.h"
#include "Player3.h"
#include "Enemy3D.h"
#include "DEFINE3D.h"
#include "ObjectAdmin3D.h"
#include <DxLib.h>


void ObjectAdmin3D::Init3D()
{
	
	object[0] = std::make_shared<Player3>(VGet(100.0f, 580.0f, 500.0f));
	
	
    object[0]->Init3D(L"C:\\Users\\hiz108\\source\\repos\\ShootingGame2024\\ShootingGame3D\\���f��\\����.mv1");
	object[0]->isEnemy = false;
	for (int enemyindex = 1; enemyindex < ENEMY_INDICES; enemyindex++) {
		auto x = 0;
		object[enemyindex] = std::make_shared<Enemy3D>((VGet(150.0f, 580.0f, 2270.0f)));
	
	
	}
	object[1]->Init3D(L"C:\\Users\\hiz108\\source\\repos\\ShootingGame2024\\ShootingGame3D\\���f��\\Enemy.mv1");
	//x += 100;
	object[1]->isEnemy = true;
	camera.Init(object[0]->position, object[1]->position);
}

void ObjectAdmin3D::Update3D(char* input)
{
	camera.Update(input,object[0]->position);
	object[0]->Update(input);

	//�v���C���[���f�����J�����̍��W��Ԃɕϊ�
	
	
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
			//�G�A�v���C���[���`�悳��Ă����ԂȂ�
			Trigger_Intersect3D();//�Փ˔���̑��i�K�Ɉڂ�
		}
	}
}
void ObjectAdmin3D::Trigger_Intersect3D()
{
	//objectindex�͒e�����������̃I�u�W�F�N�g���w���Btargetindex�͒e�������������̃I�u�W�F�N�g���w���B
	//���̓�̃I�u�W�F�N�g�́A�G�t���O�������Ă��邩���r���āA��v���Ȃ���΁A�܂�G�ƃv���C���[�ɕ�����Ă�����
	//�Փ˔���Ɉړ�����B
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

	//Trigger_Intersect3D()�́Aobjectindex��targetindex�������p���B
	//�܂�objectindex���̃I�u�W�F�N�g���e�����������̃I�u�W�F�N�g�ŁA
	//targetindex�͒e�������������̃I�u�W�F�N�g�ɂȂ�
	//Sphere::Intersect�ŏՓ˔�����s���B
	//�e�������̒e�ƁA������鑤�̋��̂̏Փ˔���������Ȃ�
	//�^�Ȃ�HIT���R���\�[���ɏo�͂���B
	for (int ammoindex = 0; ammoindex < AMMO_INDICES; ammoindex++) {
		if (Sphere::Intersect(object[objectindex]->ammo[ammoindex]->sphere, object[targetindex]->sphere))
		{
	  		
			DrawFormatString(600, 200, GetColor(255, 100, 0), L"HIT");
			}
		}
	

}


//TODO:���̂̈ʒu���̍X�V�������ARootObject3D�ɑg�ݍ��ށB���̍ہAUpdate�����Ƃ���Update_Core�֐������A�����Ɏ�������B