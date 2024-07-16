#include <DxLib.h>

class Camera {

public:
	void Init(const VECTOR& playerpos, const VECTOR& enemypos);//基本は固定カメラとして使う。

	void Update(); //Imguiでの編集に使用。位置調整

	VECTOR position; //Imguiで調整

	VECTOR target;

	

};