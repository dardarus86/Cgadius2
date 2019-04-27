#include "Player.h"

Player::Player()
{

	idle.addFrame(sf::IntRect(0, 139, 160, 135));
	idle.addFrame(sf::IntRect(159, 139, 160, 135));
	idle.addFrame(sf::IntRect(319, 139, 160, 135));
	idle.addFrame(sf::IntRect(479, 139, 160, 135));
	idle.addFrame(sf::IntRect(639, 139, 160, 135));
	idle.addFrame(sf::IntRect(799, 139, 160, 135));
	idle.addFrame(sf::IntRect(959, 139, 160, 135));
	idle.addFrame(sf::IntRect(1119, 139, 160, 135));
	idle.addFrame(sf::IntRect(1279, 139, 160, 135));
	idle.addFrame(sf::IntRect(1439, 139, 160, 135));
	idle.addFrame(sf::IntRect(1599, 139, 160, 135));
	idle.setFrameSpeed(0.1f);


	forward.addFrame(sf::IntRect(479, 0, 160, 139));
	forward.addFrame(sf::IntRect(639, 0, 160, 139));
	forward.setFrameSpeed(0.1f);

	back.addFrame(sf::IntRect(0, 0, 160, 139));
	back.addFrame(sf::IntRect(159, 0, 160, 139));
	back.addFrame(sf::IntRect(319, 0, 160, 139));
	back.setFrameSpeed(0.1f);

	currentAnimation = &idle;
	setTextureRect(currentAnimation->getCurrentFrame());

	setCollisionBox(0,0, 60, 60);
	setOutlineColor(sf::Color::Red);
	setOutlineThickness(3.f);

}

Player::~Player()
{
}

void Player::handleInput(float dt)
{


	if (input->isKeyDown(sf::Keyboard::Right))
	{
		currentAnimation = &forward;
		setTextureRect(currentAnimation->getCurrentFrame());
		velocity.x = 400;
		velocity.y = 0;
		move(velocity*dt);
	}

	if (input->isKeyDown(sf::Keyboard::Left))
	{
		currentAnimation = &back;
		setTextureRect(currentAnimation->getCurrentFrame());
		velocity.x = -400;
		velocity.y = 0;
		move(velocity*dt);
	}

	if (input->isKeyDown(sf::Keyboard::Up))
	{
		currentAnimation = &idle;
		setTextureRect(currentAnimation->getCurrentFrame());
		velocity.x = 0;
		velocity.y = -400;
		move(velocity*dt);
	}

	if (input->isKeyDown(sf::Keyboard::Down))
	{
		currentAnimation = &idle;
		setTextureRect(currentAnimation->getCurrentFrame());
		velocity.x = 0;
		velocity.y = 400;
		move(velocity*dt);
	}

	if (input->isKeyDown(sf::Keyboard::Right) && input->isKeyDown(sf::Keyboard::RControl))
	{
		currentAnimation = &forward;
		setTextureRect(currentAnimation->getCurrentFrame());
		velocity.x = 2000;
		velocity.y = 0;
		move(velocity*dt);
	}

	if (input->isKeyDown(sf::Keyboard::Left) && input->isKeyDown(sf::Keyboard::RControl))
	{
		currentAnimation = &back;
		setTextureRect(currentAnimation->getCurrentFrame());
		velocity.x = -2100;
		velocity.y = 0;
		move(velocity*dt);
	}

	if (input->isKeyDown(sf::Keyboard::Space))
	{
      		if (timer >= 0.15 )
		{
			bulletManager->spawn(this->getPosition().x + 30, this->getPosition().y + 30);
			timer = 0;
		}
	}
		
}

void Player::update(float dt)
{
	timer+=dt;


	bulletManager->setPlayerPosX(getPosition().x);
	bulletManager->setPosition(getPosition().x + 50, getPosition().y + 26);
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());
	// Check for collision with Left of window

	std::vector<Wall> walls1 = wallManager->getWalls1();

for (auto& wall : walls1)
	{	
		//if (getGlobalBounds().intersects(wall.getGlobalBounds()))
		if (Collision::checkBoundingBox(this, &wall))
		{
			
			playerCentre.x = getPosition().x + (getSize().x * 0.5);
			playerCentre.y = getPosition().y + (getSize().y * 0.5);
			wallCentre.x = wall.getPosition().x + (wall.getSize().x * 0.5);
			wallCentre.y = wall.getPosition().y + (wall.getSize().y * 0.5);

			//int direction;
			float tempX, tempY;
			// 1- left 2- right 3- top 4- bottom

			tempX = abs(wallCentre.x - playerCentre.x);
			tempY = abs(wallCentre.y - playerCentre.y);

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
				if (wallCentre.x > playerCentre.x)
				{
					velocity.x = 0;
					setPosition(wall.getPosition().x - getSize().x, getPosition().y);
				}
				//right
				if (wallCentre.x < playerCentre.x)
				{
					velocity.x = 0;
					setPosition(wall.getPosition().x + wall.getSize().x, getPosition().y);
				}
			}
			else
			{
				if (wallCentre.y > playerCentre.y)
				{
					velocity.y = 0;
					setPosition(getPosition().x, wall.getPosition().y - getSize().y);
				}
				else
				{
					velocity.y = 0;
					setPosition(getPosition().x, wall.getPosition().y + wall.getSize().y);
				}
			}

		}
	}

	if (getPosition().y <= 100)
	{
		setPosition(getPosition().x, 100);
	}

	if (getPosition().y >= 700)
	{
		setPosition(getPosition().x, 700);
	}


}

int Player::getScore()
{
	return score;
}

void Player::setScore(int x)
{
	score = score + x;
}




