#include "BulletManager.h"


BulletManager::BulletManager()
{
	texture.loadFromFile("gfx/playerbullet.png");
	audioManager.addSound("sfx/shot2.wav", "wallhit");
	for (int i = 0; i < 30; i++)
	{
		bullet.push_back(Bullet());
		bullet[i].setAlive(false);
		bullet[i].setTexture(&texture);
		bullet[i].setSize(sf::Vector2f(6, 24));
	
		/*bullet[i].setOutlineColor(sf::Color::Green);
		bullet[i].setOutlineThickness(3.f);*/
	}


}
BulletManager::~BulletManager(){}



void BulletManager::setPlayerPosX(float x)
{
	PlayerX = x;
}

float BulletManager::getPlayerPosX()
{
	return PlayerX;
}

void BulletManager::spawn(float x, float y)
{
	
	
	for (int i = 0; i < bullet.size(); i++)
	{
		if (!bullet[i].isAlive())
		{
			bullet[i].setPosition(x, y);
			bullet[i].setAlive(true);
			bullet[i].setVelocity(1500,0);
			return;
				
		}
	}
}
void BulletManager::update(const float& dt)
{
	std::vector<Wall> walls1 = wallManager->getWalls1();

	for (auto& bullet : bullet)
	{
		for (auto& wall : walls1)
		{
			if (Collision::checkBoundingBox(&bullet, &wall))
			{
				audioManager.playSoundbyName("wallhit");
				bullet.setAlive(false);
				bullet.setPosition(-100, -100);
			}
		}
	}
	for (int i = 0; i < bullet.size(); i++)
	{
		if (bullet[i].isAlive())
		{
			bullet[i].update(dt);
		}
	}
	deathCheck();
}
void BulletManager::deathCheck()
{
	for (int i = 0; i < bullet.size(); i++)
	{
		if (bullet[i].isAlive())
		{
			if (bullet[i].getPosition().x > PlayerX + 700)
			{
				bullet[i].setAlive(false);
			}
		}
	}
}

void BulletManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < bullet.size(); i++)
	{
		if (bullet[i].isAlive())
		{
			window->draw(bullet[i]);
		}
	}
}
