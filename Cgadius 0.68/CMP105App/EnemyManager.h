#pragma once
#include "Enemy.h"
#include <math.h>
#include <iostream>
#include "Framework/Collision.h"
#include <SFML/Audio.hpp>
#include "Framework/AudioManager.h"
#include <vector>
#include "WallManager.h"
#include "BulletManager.h"
#include "Player.h"

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();

	void spawn();
	void update(float dt, Player &player);
	void deathCheck();
	void render(sf::RenderWindow* window);
	std::vector<Enemy>& getEnemygrey() { return Enemygrey; }

	void setWallManager(WallManager* wm)
	{
		this->wallManager = wm;
	}

	void setBulletManager(BulletManager* bm)
	{
		this->bulletManager = bm;
	}


private:
	std::vector<Enemy> Enemygrey;
	sf::Texture Enemytexture;
	
	WallManager* wallManager;
	BulletManager* bulletManager;
	AudioManager audioManager;

	float timer;
	int enemyhp;
};
