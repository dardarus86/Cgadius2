#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Framework/Animation.h"
#include "Framework/GameObject.h"
#include <string>
#include <iostream>
class Credits :public GameObject
{
public:
	Credits(sf::RenderWindow* hwnd, Input* in, GameState* state);
	~Credits();

	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;
	AudioManager audioManager;

	sf::Font font;
	sf::Text text;
	GameObject backgroundobj;
	Animation background;
	sf::Texture backgroundtexture;


};