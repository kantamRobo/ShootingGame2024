#include "Camera.h"
#include "RootObject3D.h"

#include "Player3.h"



void Player3::Draw()
{
}

void Player3::Update()
{
	
}

void Player3::Update(char* input)
{
	Draw3D(position);
	for (int i = 0; i < MAX_AMMO; i++) {
		ammo[i]->Update(50);
		
	}
	
	sphere.DrawDebug(position);
	
Move(input);
	
	
}


void Player3::PlayerInput(char* input){
	

	if(input[KEY_INPUT_A] == 1) {

	
	
		AttackTrigger();
		
	}
	
	
	
	

}

void Player3::Move(char* input)
{


	auto forward = camera.GetCameraForward(); // �J�����̑O�����x�N�g��
	auto right = camera.GetCameraRight();     // �J�����̉E�����x�N�g��

	// forward��right�̏����� (Y������0�ɂ��Đ��K��)
	forward.y = 0;  // �n�ʂɉ������ړ����l������Y����0��
	forward = VNorm(forward); // ���K��
	right.y = 0;
	right = VNorm(right);     // ���K��

	// ���������Ɛ��������̈ړ������Z�b�g
	VECTOR move = VGet(0.0f, 0.0f, 0.0f);
	int move_horizontal = 0;
	int move_vertical = 0;

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
	VECTOR moveH = VScale(right, move_horizontal * 5);  // �E�����Ɉړ�
	VECTOR moveV = VScale(forward, move_vertical * 5);  // �O�����Ɉړ�

	// �ŏI�I�Ȉړ��x�N�g�����v�Z
	move = VAdd(moveH, moveV);

	// �v���C���[�̈ʒu���X�V
	position = VAdd(position, move);
}


