#include "Asteroid.h"

Asteroid::Asteroid()
{
}

Asteroid::~Asteroid()
{}

void Asteroid::update(float dt)
{
	move(velocity*dt);


	if (getPosition().y <= 100 || getPosition().y >= 650)
	{
		velocity.y = -velocity.y;
	}

}
