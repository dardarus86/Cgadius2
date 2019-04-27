#pragma once
#include "Asteroid.h"
#include <math.h>
#include <iostream>
#include "Framework/Collision.h"
#include "Framework/GameObject.h"
#include <SFML/Audio.hpp>
#include "Framework/AudioManager.h"
#include <vector>
#include "WallManager.h"
#include "EnemyManager.h"
#include "WallManager.h"

class AsteroidManager
{
public:
	AsteroidManager();
	~AsteroidManager();

	void spawn();
	void update(float dt, Player &player);
	void deathCheck();
	void render(sf::RenderWindow* window);
	void setWallManager(WallManager* wm)
	{
		wallManager = wm;
	}

	void setBulletManager(BulletManager* bm)
	{
		this->bulletManager = bm;
	}


private:
	std::vector<Asteroid> asteroids;
	sf::Texture texture;
	WallManager* wallManager;
	BulletManager* bulletManager;
	AudioManager audioManager;
	sf::Vector2f asteroidICentre;
	sf::Vector2f asteroidJCentre;
	sf::Vector2f wallCentre;
};
