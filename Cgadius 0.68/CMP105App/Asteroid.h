#pragma once
#include "Framework/GameObject.h"
#include "Framework/Collision.h"
class Asteroid : public GameObject
{
public:
	Asteroid();
	~Asteroid();

	void update(float dt);

private:

	std::vector<Asteroid> asteroid;

};
