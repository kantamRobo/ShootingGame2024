#include <DxLib.h>

class Circle
{
public:
	VECTOR position;
	double radius = 0;
	static bool Intersect(const Circle& r1, const Circle& r2);
	void DrawDebug(const VECTOR& objectpos)
	{
		DrawCircle(static_cast<int>(position.x), static_cast<int>(position.y), (0, 255, 0), FALSE, 1);
	}
};





