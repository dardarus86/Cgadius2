#pragma once
#include "Framework/GameObject.h"
#include "Framework/Input.h"

class Bullet : public GameObject
{
public:
	Bullet();
	~Bullet();

	void update(float dt);

	

private:

	
	sf::Texture bullettexture;
	sf::Texture bullettexture2;


};

