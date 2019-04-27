#include "AsteroidManager.h"

AsteroidManager::AsteroidManager()
{

	texture.loadFromFile("gfx/asteroid.png");
	audioManager.addSound("sfx/explosion.wav", "explosion");

	for (int i = 0; i < 40; i++)
	{
		asteroids.push_back(Asteroid());
		asteroids[i].setAlive(false);
		asteroids[i].setTexture(&texture);
		asteroids[i].setSize(sf::Vector2f(40, 35));
		asteroids[i].setCollisionBox(3, 3, 38, 33);

	}
}

AsteroidManager::~AsteroidManager()
{}

void AsteroidManager::update(float dt, Player &player)
{
	std::vector<Wall> walls1 = wallManager->getWalls1();
	std::vector<Bullet>* bullet1 = bulletManager->getBullets();

	for (auto& bullet : *bullet1)
	{
		for (auto& astroid : asteroids)
		{
			if (Collision::checkBoundingBox(&astroid, &bullet))
			{
				if (astroid.isAlive())
				{

					audioManager.playSoundbyName("explosion");
					bullet.setAlive(false);
						astroid.setAlive(false);
						astroid.setPosition(-100, 0);
						player.setScore(50);
			
				}
			}
		}
	}

	for (auto& wall : walls1)
	{
		for (auto& astroid : asteroids)
		{
			if (Collision::checkBoundingBox(&astroid, &wall))
			{
				asteroidICentre.x = astroid.getPosition().x + (astroid.getSize().x * 0.5);
				asteroidICentre.y = astroid.getPosition().y + (astroid.getSize().y * 0.5);
				wallCentre.x = wall.getPosition().x + (wall.getSize().x * 0.5);
				wallCentre.y = wall.getPosition().y + (wall.getSize().y * 0.5);

				//int direction;
				float tempX, tempY;
				// 1- left 2- right 3- top 4- bottom

				tempX = abs(wallCentre.x - asteroidICentre.x);
				tempY = abs(wallCentre.y - asteroidICentre.y);

				if (tempX < 0)
				{
					tempX *= -1;
				}

				if (tempY < 0)
				{
					tempY *= -1;
				}

				if (tempX > tempY)
				{
					if (wallCentre.x > asteroidICentre.x)
					{
						astroid.setVelocity(astroid.getVelocity().x * (-1), astroid.getVelocity().y);
					}
					//right
					if (wallCentre.x < asteroidICentre.x)
					{
						astroid.setVelocity(astroid.getVelocity().x * (-1), astroid.getVelocity().y);
					}
				}
				else
				{
					if (wallCentre.y > asteroidICentre.y)
					{
						astroid.setVelocity(astroid.getVelocity().x , astroid.getVelocity().y * (-1));
					}
					else
					{
						astroid.setVelocity(astroid.getVelocity().x, astroid.getVelocity().y * (-1));
					}
				}
			}
		}
	}

	//call update on all ALIVE asteroids
	for (int i = 0; i < asteroids.size(); i++)
	{

		for (int j = 0; j < asteroids.size(); j++)
		{
			if (i != j)
			{
				if (asteroids[i].isAlive())
				{
					if (Collision::checkBoundingBox(&asteroids[i], &asteroids[j]))
					{
						asteroidICentre.x = asteroids[i].getPosition().x + (asteroids[i].getSize().x * 0.5);
						asteroidICentre.y = asteroids[i].getPosition().y + (asteroids[i].getSize().y * 0.5);
						asteroidJCentre.x = asteroids[j].getPosition().x + (asteroids[j].getSize().x * 0.5);
						asteroidJCentre.y = asteroids[j].getPosition().y + (asteroids[j].getSize().y * 0.5);

						//int direction;
						float tempX, tempY;
						// 1- left 2- right 3- top 4- bottom

						tempX = abs(asteroidJCentre.x - asteroidICentre.x);
						tempY = abs(asteroidJCentre.y - asteroidICentre.y);

						if (tempX < 0)
						{
							tempX *= -1;
						}

						if (tempY < 0)
						{
							tempY *= -1;
						}

						if (tempX > tempY)
						{
							//left side
							if (asteroidJCentre.x > asteroidICentre.x)
							{
								asteroids[i].setVelocity(asteroids[i].getVelocity().x * (-1), asteroids[i].getVelocity().y);
								asteroids[j].setVelocity(asteroids[j].getVelocity().x * (-1), asteroids[j].getVelocity().y);
							}
							//right
							if (asteroidJCentre.x < asteroidICentre.x)
							{
								asteroids[i].setVelocity(asteroids[i].getVelocity().x * (-1), asteroids[i].getVelocity().y);
								asteroids[j].setVelocity(asteroids[j].getVelocity().x * (-1), asteroids[j].getVelocity().y);
							}
						}
						else
						{
							if (asteroidJCentre.y > asteroidICentre.y)
							{
								asteroids[i].setVelocity(asteroids[i].getVelocity().x, asteroids[i].getVelocity().y * (-1));
								asteroids[j].setVelocity(asteroids[j].getVelocity().x, asteroids[j].getVelocity().y * (-1));
							}
							else
							{
								asteroids[i].setVelocity(asteroids[i].getVelocity().x, asteroids[i].getVelocity().y * (-1));
								asteroids[j].setVelocity(asteroids[j].getVelocity().x, asteroids[j].getVelocity().y * (-1));
							}
						}
					}
					asteroids[i].update(dt);
				}
			}
		}
	}
}

//spawn new ball
//find a dead ball, make alive, move to spawn point, give random velocity
void AsteroidManager::spawn()
{
	asteroids[0].setPosition(1860, 220);
	asteroids[1].setPosition(1860, 280);
	asteroids[2].setPosition(1860, 350);
	asteroids[3].setPosition(1860, 410);
	asteroids[4].setPosition(1860, 550);
	asteroids[5].setPosition(1940, 250);
	asteroids[6].setPosition(1940, 310);
	asteroids[7].setPosition(1940, 380);
	asteroids[8].setPosition(1940, 410);
	asteroids[9].setPosition(1940, 590);
	asteroids[10].setPosition(2020, 220);
	asteroids[11].setPosition(2020, 280);
	asteroids[12].setPosition(2020, 350);
	asteroids[13].setPosition(2020, 410);
	asteroids[14].setPosition(2020, 550);
	asteroids[15].setPosition(2100, 250);
	asteroids[16].setPosition(2100, 310);
	asteroids[17].setPosition(2100, 380);
	asteroids[18].setPosition(2100, 410);
	asteroids[19].setPosition(2100, 590);
	asteroids[20].setPosition(2180, 220);
	asteroids[21].setPosition(2180, 280);
	asteroids[22].setPosition(2180, 350);
	asteroids[23].setPosition(2180, 410);
	asteroids[24].setPosition(2180, 550);
	asteroids[25].setPosition(2260, 250);
	asteroids[26].setPosition(2260, 310);
	asteroids[27].setPosition(2260, 380);
	asteroids[28].setPosition(2260, 410);
	asteroids[29].setPosition(2260, 590);
	asteroids[30].setPosition(2340, 220);
	asteroids[31].setPosition(2340, 280);
	asteroids[32].setPosition(2340, 350);
	asteroids[33].setPosition(2340, 410);
	asteroids[34].setPosition(2340, 550);
	asteroids[35].setPosition(2420, 250);
	asteroids[36].setPosition(2420, 310);
	asteroids[37].setPosition(2420, 380);
	asteroids[38].setPosition(2420, 410);
	asteroids[39].setPosition(2420, 590);

	for (int i = 0; i < asteroids.size(); i++)
	{
		if (!asteroids[i].isAlive())
		{
			asteroids[i].setAlive(true);
			asteroids[i].setVelocity(1, 1);
			
			return;
		}
	}

}

void AsteroidManager::deathCheck()
{

}


//Render all alive asteroids
void AsteroidManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < asteroids.size(); i++)
	{
		if (asteroids[i].isAlive())
		{
			window->draw(asteroids[i]);
		}
	}
}
