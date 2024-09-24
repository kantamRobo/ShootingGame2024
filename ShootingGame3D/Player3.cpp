
#include "RootObject3D.h"
#include "Camera.h"
#include "Player3.h"



void Player3::Draw()
{
}


void Player3::Update(Camera* camera,char* input)
{
	Draw3D(position);
	for (int i = 0; i < MAX_AMMO; i++) {
		ammo[i]->Update(50);
		
	}
	
	sphere.DrawDebug(position);
	
Move(camera,input);
	
	
}


void Player3::PlayerInput(char* input){
	

	if(input[KEY_INPUT_A] == 1) {

	
	
		AttackTrigger();
		
	}
	
	
	
	

}

void Player3::Move(Camera* camera,char* input)
{

	
	
	DrawFormatString(320, 180, GetColor(0, 255, 0), L"�O���x�N�g��z %f ", camera->GetCameraForward().z);
	DrawFormatString(320, 160, GetColor(0, 255, 0), L"�O���x�N�g��x %f ", camera->GetCameraForward().x);
	DrawFormatString(320, 200, GetColor(0, 255, 0), L"�E�x�N�g��x %f ", camera->GetCameraRight().x);
	DrawFormatString(320, 220, GetColor(0, 255, 0), L"�E�x�N�g��z %f ", camera->GetCameraRight().z);
	// forward��right�̏����� (Y������0�ɂ��Đ��K��)
	  // �n�ʂɉ������ړ����l������Y����0��
	camera->SetForward(VGet(camera->GetCameraForward().x, 0, camera->GetCameraForward().z));
	camera->SetForward(VNorm(camera->GetCameraForward())); // ���K��

	 
	camera->SetRight(VGet(camera->GetCameraRight().x, 0, camera->GetCameraRight().z));
	camera->SetRight(VNorm(camera->GetCameraRight())); // ���K��

	// ���������Ɛ��������̈ړ������Z�b�g
	VECTOR move = VGet(0.0f, 0.0f, 0.0f);
	int move_horizontal = 0;
	int move_vertical = 0;
	// �v���C���[�̌����ɃJ�����̌����𔽉f������
   // forward�x�N�g���Ɋ�Â���Y����]�p�x���v�Z
	float playerRotationY = atan2(camera->GetCameraForward().z, camera->GetCameraForward().x);
	
	// �v���C���[�̉�]�s���ݒ�
	MATRIX rotationMatrix = MGetRotY(playerRotationY);
	DrawFormatString(320, 240, GetColor(0, 255, 0), L"PlayerRotation %f ", playerRotationY);
	MV1SetRotationXYZ(handle, VGet(0, playerRotationY, 0));
	// ���͂ɉ����Ĉړ��ʂ�ݒ�
	if (input[KEY_INPUT_UP] == 1) {
		move_vertical = 1; // �O�i
	}
	if (input[KEY_INPUT_DOWN] == 1) {
		move_vertical = -1; // ���
	}
	if (input[KEY_INPUT_LEFT] == 1) {
		move_horizontal = -1; // ���ړ�
	}
	if (input[KEY_INPUT_RIGHT] == 1) {
		move_horizontal = 1; // �E�ړ�
	}

	// �J������ł̈ړ��x�N�g�����v�Z
	VECTOR moveH = VScale(camera->GetCameraRight(), move_horizontal * 5);  // �E�����Ɉړ�
	VECTOR moveV = VScale(camera->GetCameraForward(), move_vertical * 5);  // �O�����Ɉړ�

	// �ŏI�I�Ȉړ��x�N�g�����v�Z
	move = VAdd(moveH, moveV);

	// �v���C���[�̈ʒu���X�V
	position = VAdd(position, move);
}


