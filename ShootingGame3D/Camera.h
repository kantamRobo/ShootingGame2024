#include <DxLib.h>

class Camera {

public:
	void Init(const VECTOR& playerpos, const VECTOR& enemypos);
	void Update(char* input);
	//��{�͌Œ�J�����Ƃ��Ďg���B

	

	VECTOR position; //Imgui�Œ���

	VECTOR target;

	

};