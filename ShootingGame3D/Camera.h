#include <DxLib.h>

class Camera {

public:
	void Init(const VECTOR& playerpos, const VECTOR& enemypos);//��{�͌Œ�J�����Ƃ��Ďg���B

	void Update(); //Imgui�ł̕ҏW�Ɏg�p�B�ʒu����

	VECTOR position; //Imgui�Œ���

	VECTOR target;

	

};