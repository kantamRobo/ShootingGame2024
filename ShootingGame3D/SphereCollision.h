#include <DxLib.h>
class Sphere
{
public:
	VECTOR position;
	float radius=150;
	static    bool Intersect(const Sphere& r1, const Sphere& r2);
void DrawDebug(const VECTOR& objectpos)
{
    DrawSphere3D(objectpos, radius, 5, GetColor(0, 255, 0), GetColor(0, 255, 0), FALSE);
}
};





