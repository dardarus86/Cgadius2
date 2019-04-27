#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Framework/Input.h"
#include "Framework/Collision.h"
#include "Framework/AudioManager.h"
#include "AsteroidManager.h"
#include "WallManager.h"
#include "EnemyManager.h"
#include "BulletManager.h"
#include "Framework/GameState.h"
#include "Asteroid.h"
#include "Enemy.h"
#include "Wall.h"
#include "Player.h"
#include <string.h>
#include <string>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in, GameState *state);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();
	bool clockstarted =false;

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();
	GameState* gameState;
	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	//bullet	
	//View
	sf::View view1;
	sf::View scoreview;
	//Sound+Music
	AudioManager audioManager;
	//background
	GameObject background;
	sf::Texture backgroundtexture;
	//player
	Player player;
	sf::Texture playertexture;
	//enemy
	sf::Texture enemytexture;
	//wall(white collidable wall objects in level)
	AsteroidManager asteroidManager;
	WallManager wallManager;
	EnemyManager enemyManager;
	BulletManager bulletManager;
	
	//text
	sf::Font font;
	sf::Text score;
	sf::Text time;
	sf::Text timer;
	sf::Text lives;
	sf::Clock clock;
	sf::Time time1;
	float seconds;
	
};