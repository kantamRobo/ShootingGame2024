
#include "RootObject3D.h"
#include "Camera.h"
#include "Player3.h"



void Player3::Draw()
{
}


void Player3::Update(const MATRIX& transform, Camera* camera, char* input)
{
	Draw3D(position);
	for (int i = 0; i < MAX_AMMO; i++) {
		ammo[i]->Update(50);
		
	}
	
	sphere.DrawDebug(position);
	
Move(transform,camera,input);
	
	
}


void Player3::PlayerInput(char* input){
	

	if(input[KEY_INPUT_A] == 1) {

	
	
		AttackTrigger();
		
	}
	
	
	
	

}


void Player3::Move(const MATRIX& transform, Camera* camera, char* input)
{
	// �J�����̑O�����ƉE������\�� (�f�o�b�O)
	DrawFormatString(320, 180, GetColor(0, 255, 0), L"�O���x�N�g��z %f ", camera->GetCameraForward().z);
	DrawFormatString(320, 160, GetColor(0, 255, 0), L"�O���x�N�g��x %f ", camera->GetCameraForward().x);
	DrawFormatString(320, 200, GetColor(0, 255, 0), L"�E�x�N�g��x %f ", camera->GetCameraRight().x);
	DrawFormatString(320, 220, GetColor(0, 255, 0), L"�E�x�N�g��z %f ", camera->GetCameraRight().z);
	DrawFormatString(320, 280, GetColor(0, 255, 0), L"movetempx_admin %f ", camera->movetempx);
	DrawFormatString(320, 300, GetColor(0, 255, 0), L"movetempy_admin %f ", camera->movetempy);

	// �J�����̑O�����ƉE�����x�N�g�����擾
	VECTOR forward = VGet(camera->GetCameraForward().x, 0.0f, camera->GetCameraForward().z);  // Y������0�ɂ��āA�n�ʂɉ����������ɂ���
	forward = VNorm(forward);  // ���K��

	VECTOR right = VGet(camera->GetCameraRight().x, 0.0f, camera->GetCameraRight().z);  // ���l�ɉE�����x�N�g����Y������0��
	right = VNorm(right);  // ���K��

	// ���������Ɛ��������̈ړ��ʂ����Z�b�g
	VECTOR move = VGet(0.0f, 0.0f, 0.0f);
	int move_horizontal = 0;
	int move_vertical = 0;

	// ���͂ɉ����Ĉړ��ʂ�ݒ� (�㉺���E�L�[�ɂ�鑀��)
	if (input[KEY_INPUT_UP] == 1) {
		move_vertical = -1;  // �O�i
	}
	if (input[KEY_INPUT_DOWN] == 1) {
		move_vertical = 1;  // ���
	}
	if (input[KEY_INPUT_LEFT] == 1) {
		move_horizontal = 1;  // ���ړ�
	}
	if (input[KEY_INPUT_RIGHT] == 1) {
		move_horizontal = -1;  // �E�ړ�
	}

	// �J������ł̈ړ��x�N�g�����v�Z
	VECTOR moveH = VScale(camera->GetCameraRight(), move_horizontal * 5.0f);  // �E�����Ɉړ�
	VECTOR moveV = VScale(camera->GetCameraForward(), move_vertical * 5.0f);  // �O�����Ɉړ�

	// �ŏI�I�Ȉړ��x�N�g�����v�Z
	move = VAdd(moveH, moveV);  // ���������Ɛ��������̈ړ��x�N�g��������
	move.y = 0;  // �n�ʂɉ������ړ��Ƃ��邽��Y������0
	�@
	// �v���C���[�̈ʒu���X�V
	position = VAdd(position, move);

	// �ړ�������}��
	VECTOR endPos = VAdd(position, VScale(move, 1000.0f));  // �ړ����������o��������̏I�_
	DrawLine3D(position, VAdd(position, VScale(forward, 1000)), GetColor(0, 255, 0));  // �ΐF�őO������`��
	DrawLine3D(position, VAdd(position, VScale(right, 1000)), GetColor(255, 255, 255));  // ���F�ŉE������`��
	DrawLine3D(position, endPos, GetColor(255, 0, 0));  // �ԐF�ňړ�������`��
}
/*
void Player3::Move(const MATRIX& transform, Camera* camera,char* input)
{

	
	
	DrawFormatString(320, 180, GetColor(0, 255, 0), L"�O���x�N�g��z %f ", camera->GetCameraForward().z);
	DrawFormatString(320, 160, GetColor(0, 255, 0), L"�O���x�N�g��x %f ", camera->GetCameraForward().x);
	DrawFormatString(320, 200, GetColor(0, 255, 0), L"�E�x�N�g��x %f ", camera->GetCameraRight().x);
	DrawFormatString(320, 220, GetColor(0, 255, 0), L"�E�x�N�g��z %f ", camera->GetCameraRight().z);
	DrawFormatString(320, 280, GetColor(0, 255, 0), L"movetempx_admin %f ", camera->movetempx);
	DrawFormatString(320, 300, GetColor(0, 255, 0), L"movetempy_admin %f ", camera->movetempy);

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
	

	//MV1SetRotationXYZ(handle, VGet(0, MGetRotY(playerRotationY), 0));
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
	move.y = 0;

	// �v���C���[�̈ʒu���X�V
	position = VAdd(position, move);
	//�v���C���[�̈ړ�������}��
	   // �ړ�������}��
	VECTOR endPos = VAdd(position, VScale(VScale(move,100), 5.0f));  // �ړ����������o��������̏I�_
    
	DrawLine3D(position, VAdd(position,VScale(camera->GetCameraForward(), 1000)), GetColor(0, 255, 0));  // �ΐF�Ő���`��
	DrawLine3D(position, VAdd(position,VScale(camera->GetCameraRight(), 1000)), GetColor(255, 255, 255));//���Ő���`�� 
	DrawLine3D(position, endPos, GetColor(255, 0, 0));  // �ԐF�Ő���`��
	
}
*/

//�~�X�R�[�h
/*


�J�����̑O�����x�N�g���ƉE�����x�N�g���̌v�Z������ɓ��삵�Ȃ�
void ObjectAdmin3D::Update3D(char* input)
{
	camera.Update(input,object[0]->position);
	camera.UpdateDirection(camera.moveX, camera.moveY);
...
}

void Camera::Update(char* input, VECTOR targetpos)
{

	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	//�}�E�X�̓�������ɓ���

	if (input[KEY_INPUT_A] == 1)
	{
		movetempx -= 10;
	}

	if (input[KEY_INPUT_D] == 1)
	{
		movetempx += 10;
	}

	if (input[KEY_INPUT_W] == 1)
	{
		movetempy -= 10;
	}

	if (input[KEY_INPUT_S] == 1)
	{
		movetempy += 10;
	}
	auto mouseX_F = movetempx * 0.001;
	auto mouseY_F = movetempy * 0.001;


	 moveX = 2000 * sin(mouseX_F) * cos(mouseY_F);
	 moveY = 2000 * sin(mouseY_F); // Y�������̈ړ�
	 moveZ = 2000 * cos(mouseX_F) * cos(mouseY_F);


	auto debug = temppos;

	temppos = VGet(targetpos.x + moveX, targetpos.y + moveY, targetpos.z + moveZ);
	position = temppos;
	CameraLookAtPosition = targetpos;




	// �J�����̐ݒ�ɔ��f����
	SetCameraPositionAndTarget_UpVecY(position, CameraLookAtPosition);






}


void Camera::UpdateDirection(float in_x,float in_y)
{
	DrawFormatString(320, 250, GetColor(0, 255, 0), L"movetempy_cam %f ", in_x);
	DrawFormatString(320, 270, GetColor(0, 255, 0), L"movetempx_cam %f ", in_y);
	forward = VNorm(VGet(
		cos(in_x) * sin(in_y),
		sin(in_y),
		cos(in_y) * cos(in_x)
	));

	right = VNorm(VGet(
		cos(in_x),
		0.0f,
		-sin(in_y)
	));


		//Camera_FORWARD = VGet(View.m[2][0], View.m[2][1], View.m[2][2]);
		//Camera_Right = VGet(View.m[0][0], View.m[0][1], View.m[0][2]);

}
*/