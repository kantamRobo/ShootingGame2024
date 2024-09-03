#include "Enemy2.h"

void Enemy2::Update()
{
	Draw2D(this->position);
	AttackTrigger();
}

void Enemy2::Update(char* input)
{

}