#include "SphereCollision.h"


bool Sphere::Intersect(const Sphere& r1, const Sphere& r2)
{
    auto r1pos = r1.position;
    auto r2pos = r2.position;

    // �����̓����v�Z
    float distanceSquared = (r2pos.x - r1pos.x) * (r2pos.x - r1pos.x) +
        (r2pos.y - r1pos.y) * (r2pos.y - r1pos.y) +
        (r2pos.z - r1pos.z) * (r2pos.z - r1pos.z);

    // ���a�̍��v�̓����v�Z
    float radiusSumSquared = (r2.radius + r1.radius) * (r2.radius + r1.radius);

    // ���̂��������Ă��邩�ǂ����𔻒�
    bool intersect = distanceSquared <= radiusSumSquared;
    return intersect;
}
