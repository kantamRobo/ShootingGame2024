#include "SphereCollision.h"


bool Sphere::Intersect(const Sphere& r1, const Sphere& r2)
{
    //‹…‚Æ‹…“¯Žm‚Ì“–‚½‚è”»’è
    auto x2x1 = (r2.position.x - r1.position.x) * (r2.position.x - r1.position.x);
    auto y2y1 = (r2.position.y - r1.position.y) * (r2.position.y - r1.position.y);
    auto z2z1 = (r2.position.z - r1.position.z) * (r2.position.z - r1.position.z);

    auto r1radius = r1.radius;
    auto r2radius = r2.radius;

  
    auto radius2 = (r1radius + r2radius) * (r1radius + r2radius);
    bool intersect = x2x1 + y2y1 + z2z1 <= radius2;
    
    if (!intersect)
    {
        return false;
    }

    return true;
}
