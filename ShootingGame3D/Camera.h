#include <DxLib.h>

class Camera {

public:
	
	MATRIX View;
	MATRIX Projection;
	MATRIX Modelmat;
	VECTOR rotation;
	void Init(const VECTOR& playerpos, const VECTOR& enemypos);
	void Update(char* input);
	
	//基本は固定カメラとして使う。

	float camrot = -5.67999601;


	VECTOR position; //Imguiで調整

	VECTOR target;

	VECTOR CameraLookAtPosition;

	VECTOR temppos =VGet(0,0,0);

	MATRIX GetViewMatrix() {
		return GetCameraViewMatrix();
	}


};