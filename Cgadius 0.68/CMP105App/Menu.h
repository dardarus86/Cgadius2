#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Framework/Animation.h"
#include "Framework/GameObject.h"
#include <string>
#include <iostream>
class Menu :public GameObject
{
public:
	Menu(sf::RenderWindow* hwnd, Input* in, GameState* state);
	~Menu();

	void handleInput(float dt);
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
	sf::Text text2;
	sf::Text text3;
	GameObject backgroundobj;
	
	Animation background;
	sf::Texture backgroundtexture;

	
};