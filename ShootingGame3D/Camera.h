#include <DxLib.h>

class Camera {

public:
	void Init(const VECTOR& playerpos, const VECTOR& enemypos);
	void Update(char* input);
	//基本は固定カメラとして使う。

	

	VECTOR position; //Imguiで調整

	VECTOR target;

	

};