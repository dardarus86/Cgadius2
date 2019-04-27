#pragma once
#include "Wall.h"
#include <math.h>
#include <iostream>
#include "Framework/Collision.h"
#include "Framework/GameObject.h"
#include <vector>

class WallManager
{
public:
	WallManager();
	~WallManager();

	void spawn();
	void render(sf::RenderWindow* window);

	std::vector<Wall>& getWalls1() { return walls1; }

private:
	std::vector<Wall> walls1;
	sf::Texture wall1texture;

};
