#include "Enemy.h"

Enemy::Enemy()
{
	idle.addFrame(sf::IntRect(0, 0, 432, 367));
	idle.addFrame(sf::IntRect(432, 0, 432, 367));
	idle.addFrame(sf::IntRect(864, 0, 432, 367));
	idle.addFrame(sf::IntRect(1296, 0, 432, 367));
	idle.setFrameSpeed(0.1f);
	idle.setFlipped(false);



	explosion.addFrame(sf::IntRect(0,   384, 79, 79));
	explosion.addFrame(sf::IntRect(80,  384, 79, 79));
	explosion.addFrame(sf::IntRect(160, 384, 79, 79));
	explosion.addFrame(sf::IntRect(240, 384, 79, 79));
	explosion.addFrame(sf::IntRect(320, 384, 79, 79));
	explosion.addFrame(sf::IntRect(400, 384, 79, 79));
	explosion.addFrame(sf::IntRect(480, 384, 79, 79));
	explosion.addFrame(sf::IntRect(540, 384, 79, 79));
	explosion.setFrameSpeed(0.07f);

	currentAnimation = &idle;
	setTextureRect(idle.getCurrentFrame());

}

Enemy::~Enemy()
{}

void Enemy::update(float dt)
{
	
	currentAnimation->animate(dt);
	move(velocity*dt);


	if (getPosition().y <= 105 || getPosition().y >= 646)
	{
		velocity = -velocity;
	}

}

void Enemy::collision(float dt)
{
	currentAnimation = &explosion;
	setTextureRect(explosion.getCurrentFrame());
	velocity.y = 0;
}


