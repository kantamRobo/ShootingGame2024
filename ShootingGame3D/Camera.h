#include <DxLib.h>

class Camera {

public:
	void Init(const VECTOR& playerpos, const VECTOR& enemypos);
	void Update(char* input);
	
	//��{�͌Œ�J�����Ƃ��Ďg���B

	float x = 0;

	VECTOR position; //Imgui�Œ���

	VECTOR target;

	VECTOR CameraLookAtPosition;

	VECTOR temppos =VGet(0,0,0);

};