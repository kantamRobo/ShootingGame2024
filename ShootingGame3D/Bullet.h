#include <DxLib.h>


#include "../bullet_lib/src/src/btBulletDynamicsCommon.h"

#include "../bullet_lib/src/src/LinearMath/btTransformUtil.h"
#pragma once


class Bullet_RigidBody
{
	btRigidBody* rb;

	Bullet_RigidBody(float mass, btBoxShape* shape, const VECTOR in_localInetia) {

		btVector3 localInertia = btVector3(in_localInetia.x, in_localInetia.y, in_localInetia.z);
		rb = new btRigidBody(mass, 0, shape, localInertia);
	}

	void Addforce(btVector3 force) {
		rb->applyForce(force, btVector3(0, 0, 0));
	}
};