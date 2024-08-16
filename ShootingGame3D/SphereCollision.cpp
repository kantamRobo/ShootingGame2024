#include "SphereCollision.h"


bool Sphere::Intersect(const Sphere& r1, const Sphere& r2)
{
    //球と球同士の当たり判定

    double x2x1 = (r2.position.x - r1.position.x) * (r2.position.x - r1.position.x)/10;
    double y2y1 = (r2.position.y - r1.position.y) * (r2.position.y - r1.position.y)/10;
    double z2z1 = (r2.position.z - r1.position.z) * (r2.position.z - r1.position.z)/10;

    double r1radius = r1.radius;
    double r2radius = r2.radius;

  //アンダーフローが起こっている
    double radius2 = (r1radius + r2radius) * (r1radius + r2radius);
    bool intersect = x2x1 + y2y1 + z2z1 <= radius2;
    
    if (!intersect)
    {
        return false;
    }

    return intersect;
}


//TODO:値のスケーリング