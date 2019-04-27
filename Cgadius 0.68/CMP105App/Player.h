#pragma once
#include "Framework/GameObject.h"
#include "Framework/Input.h"
#include "Framework/Animation.h"
#include "WallManager.h"
#include "BulletManager.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void handleInput(float dt);
	void update(float dt);
	void setPWallManager(WallManager* wm)
	{
		this->wallManager = wm;
	}

	void setBulletManager(BulletManager* wm)
	{
		this->bulletManager = wm;
	}
	float timer;

	int getScore();
	void setScore(int x);
	

protected:
	Animation idle;
	Animation back;
	Animation forward;
	Animation* currentAnimation;

private:

	WallManager* wallManager;
	BulletManager* bulletManager;
	sf::Vector2f playerCentre;
	sf::Vector2f wallCentre;

	int score = 0;
	






};

