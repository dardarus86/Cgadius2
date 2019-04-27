#pragma once
#include "Framework/GameObject.h"
#include "Framework/Input.h"
#include "Bullet.h"
#include <math.h>
#include <iostream>
#include "Framework/Collision.h"
#include "WallManager.h"
#include <vector>
#include <SFML/Audio.hpp>
#include "Framework/AudioManager.h"


class BulletManager : public GameObject
{
public:
	BulletManager();
	~BulletManager();


	void spawn(float x, float y);
	float getPlayerPosX();
	void setPlayerPosX(float x);
	void update(const float& dt);
	void deathCheck();
	void render(sf::RenderWindow* window);
	std::vector<Bullet>* getBullets() { return  &bullet; }
	std::vector<Bullet>& getEnemyBullets() { return eBullet; }
	float PlayerX;

	void setWallManager(WallManager* wm)
	{
		this->wallManager = wm;
	}


private:

	std::vector<Bullet> bullet;
	std::vector<Bullet> eBullet;
	sf::Texture texture;
	sf::Texture enemyTexture;
	AudioManager audioManager;
	sf::RenderWindow* window;
	WallManager* wallManager;
	
};
