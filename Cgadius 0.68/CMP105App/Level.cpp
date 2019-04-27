#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* state)
{
	window = hwnd;
	input = in;
	gameState = state;

	player.setInput(input);
	view1.reset(sf::FloatRect(0.f, 0.f, 1200.f, 800.f));
	scoreview.setViewport(sf::FloatRect(0.0f, 0.0f,1.0f, 1.0f));
	audioManager.addMusic("sfx/level.ogg", "level");
	audioManager.addMusic("sfx/boss.ogg", "boss");
	audioManager.addSound("sfx/death.wav", "death");

	audioManager.addSound("sfx/enemyfire.wav", "enemyfire");
	audioManager.addSound("sfx/enter.wav", "enter");

	audioManager.addSound("sfx/pauldeath.wav", "pauldeath");
	audioManager.addSound("sfx/paulhit.wav", "paulhit");
	audioManager.addSound("sfx/shot.wav", "shot");
	audioManager.addSound("sfx/shot2.wav", "shot2");
	audioManager.addSound("sfx/shot3.ogg", "shot3");
	audioManager.addSound("sfx/warning.wav", "warning");


	
	//boss.loadFromFile("sfx/boss.ogg");



	//sound.setBuffer(boss);
	//sound.setVolume(35);
	
	// initialise game objects
	backgroundtexture.loadFromFile("gfx/background.png");
	playertexture.loadFromFile("gfx/playersprite.png");

	background.setTexture(&backgroundtexture);
	background.setSize(sf::Vector2f(6000, 800));
	background.setPosition(0, 0);

	player.setTexture(&playertexture);
	player.setSize(sf::Vector2f(60, 60));
	player.setPosition(50, 350);




	

	//text
	if (!font.loadFromFile("font/andromeda.ttf"))
	{
		std::cout << "Error loading font\n";
	}

	score.setFont(font);
	score.setCharacterSize(50);
	score.setFillColor(sf::Color::Red);
	score.setPosition(150, 20);

	lives.setFont(font);
	lives.setString("Lives 3");
	lives.setCharacterSize(50);
	lives.setFillColor(sf::Color::Red);
	lives.setPosition(500, 20);

	time.setFont(font);
	time.setString("T");
	time.setCharacterSize(50);
	time.setFillColor(sf::Color::Red);
	time.setPosition(800, 20);

	timer.setFont(font);
	timer.setCharacterSize(50);
	timer.setFillColor(sf::Color::Red);



	for (int i = 0; i < 99; i++)
	{
		enemyManager.spawn();

	}

	for (int i = 0; i < 13; i++)
	{
		wallManager.spawn();

	}

	for (int i = 0; i < 40; i++)
	{
		asteroidManager.spawn();

	}

	//asteroid manager pointers
	asteroidManager.setWallManager(&wallManager);
	asteroidManager.setBulletManager(&bulletManager);
	//enemy manager pointers

	enemyManager.setWallManager(&wallManager);
	enemyManager.setBulletManager(&bulletManager);
	player.setPWallManager(&wallManager);
	player.setBulletManager(&bulletManager);
	


}

Level::~Level()
{
}

// handle user input
void Level::handleInput(float dt)
{
		player.handleInput(dt);

	if (input->isKeyDown(sf::Keyboard::Numpad0))
	{
		input->setKeyUp(sf::Keyboard::Numpad0);
		audioManager.playSoundbyName("shot");
	}
	if (input->isKeyDown(sf::Keyboard::Numpad1))
	{
		input->setKeyUp(sf::Keyboard::Numpad1);
		audioManager.playSoundbyName("shot2");
	}
	if (input->isKeyDown(sf::Keyboard::Numpad2))
	{
		input->setKeyUp(sf::Keyboard::Numpad2);
		audioManager.playSoundbyName("shot3");
	}
	if (input->isKeyDown(sf::Keyboard::Numpad3))
	{
		input->setKeyUp(sf::Keyboard::Numpad3);
		audioManager.playSoundbyName("death");
	}
	if (input->isKeyDown(sf::Keyboard::Numpad4))
	{
		input->setKeyUp(sf::Keyboard::Numpad4);
		audioManager.playSoundbyName("enemydeath");
	}
	if (input->isKeyDown(sf::Keyboard::Numpad5))
	{
		input->setKeyUp(sf::Keyboard::Numpad5);
		audioManager.playSoundbyName("explosion");
	}
	if (input->isKeyDown(sf::Keyboard::Numpad6))
	{
		input->setKeyUp(sf::Keyboard::Numpad6);
		audioManager.playSoundbyName("pauldeath");
	}

	if (input->isKeyDown(sf::Keyboard::Numpad8))
	{
		input->setKeyUp(sf::Keyboard::Numpad8);
		audioManager.playSoundbyName("warning");
	}
	if (input->isKeyDown(sf::Keyboard::Numpad9))
	{
		view1.move(dt + 6.0f, 0);
	}

	if (input->isKeyDown(sf::Keyboard::Numpad7))
	{
		view1.move(dt - 6.0f, 0);
	}

	if (player.getPosition().x >= 5200)
	{
		view1.reset(sf::FloatRect(4800.f, 0.f, 1200.f, 800.f));
	}

}

// Update game objects
void Level::update(float dt)
{
	view1.move(dt *30.5f, 0);
	if (clockstarted != true)
	{
		clock.restart();
		clockstarted = true;
	}

	if (audioManager.getMusic()->getStatus() == sf::SoundSource::Stopped)
	{
		audioManager.playMusicbyName("level");
	}
	if (player.getPosition().x > 4951 && player.getPosition().x < 5049)
	{
		audioManager.stopAllMusic();
	}
	
	if (player.getPosition().x > 5050)
	{
		audioManager.playMusicbyName("boss");
	}
	//class updates
	enemyManager.update(dt, player);
	asteroidManager.update(dt, player);
	player.update(dt);
 	bulletManager.update(dt);
	
	

	//view move
	//view1.move(30.f*dt, 0);
//score
	std::string score1 = std::to_string(player.getScore());
	score.setString("00000" + score1);


//timer on top of screen
	time1 = clock.getElapsedTime();
	seconds = time1.asSeconds();
	std::string timerString = std::to_string(seconds);
	timer.setString(timerString.substr(0, timerString.length()-5));
	timer.setPosition(850, 20);

}

// Render level
void Level::render()
{
	beginDraw();

	window->setView(view1);
	window->draw(background);
	wallManager.render(window);
	asteroidManager.render(window);
	enemyManager.render(window);
	bulletManager.render(window);
	window->draw(player);
	window->setView(scoreview);
	window->draw(score);
	window->draw(lives);
	window->draw(time);
	window->draw(timer);

	endDraw();

}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}