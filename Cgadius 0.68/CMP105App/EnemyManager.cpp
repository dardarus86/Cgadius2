#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	timer = 0;
	Enemytexture.loadFromFile("gfx/enemy1sheet.png");
	audioManager.addSound("sfx/enemydeath.wav", "enemydeath");
	for (int i = 0; i < 94; i++)
	{
		Enemygrey.push_back(Enemy());
		Enemygrey[i].setAlive(false);
		Enemygrey[i].setTexture(&Enemytexture);
		Enemygrey[i].setSize(sf::Vector2f(60, 50));
		Enemygrey[i].setCollisionBox(0, 0, 60, 50);
	
	}
}

EnemyManager::~EnemyManager()
{}



void EnemyManager::update(float dt, Player &player)
{
	
	std::vector<Wall> walls1 = wallManager->getWalls1();

	std::vector<Bullet>* bullet1 = bulletManager->getBullets();
	/////// WALL COLLISION  /////////
	for (auto& wall : walls1)
	{
		for (auto& enemy : Enemygrey)
		{
			if (Collision::checkBoundingBox(&enemy, &wall))
			{

 				enemy.setVelocity(0, enemy.getVelocity().y * (-1));
				
			}
		}
	}



	/////// BULLET COLLISION  /////////

	for (auto& bullet : *bullet1)
	{
		for (auto& enemy : Enemygrey)
		{
			
			if (Collision::checkBoundingBox(&enemy, &bullet))
			{
				timer += dt;
				if (enemy.isAlive())
				{
					
					   
						enemy.collision(dt);
						audioManager.playSoundbyName("enemydeath");
						bullet.setAlive(false);
					
						if (timer >= 0.5)
						{
							enemy.setCollisionBox(0, 0, 0, 0);
							enemy.setAlive(false);
							enemy.setPosition(-100, 0);
							player.setScore(100);
							timer = 0;

						}
				}
			}
		}
	}

	
	//call update on all ALIVE enemies
	for (int i = 0; i < Enemygrey.size(); i++)
	{
		Enemygrey[i].update(dt);
	}
	deathCheck();
	
}

//spawn new ball
//find a dead ball, make alive, move to spawn point, give random velocity
void EnemyManager::spawn()
{
//wave 1 top 4
	Enemygrey[0].setPosition(260, 300);
	Enemygrey[1].setPosition(310, 240);
	Enemygrey[2].setPosition(380, 215);
	Enemygrey[3].setPosition(460, 210);
//wave 1 bottom 8
	Enemygrey[4].setPosition(260, 420);
	Enemygrey[5].setPosition(310, 480);
	Enemygrey[6].setPosition(380, 520);
	Enemygrey[7].setPosition(460, 520);
//wave 2 top 12
	Enemygrey[8].setPosition(840, 240);
	Enemygrey[9].setPosition(910, 180);
	Enemygrey[10].setPosition(910, 240);
	Enemygrey[11].setPosition(910, 300);
//wave 2 bottom 16
	Enemygrey[12].setPosition(980,  480);
	Enemygrey[13].setPosition(1050, 420);
	Enemygrey[14].setPosition(1050, 480);
	Enemygrey[15].setPosition(1050, 540);
//wave 3 first grey 25
	Enemygrey[16].setPosition(2080, 300);
	Enemygrey[17].setPosition(2150, 300);
	Enemygrey[18].setPosition(2220, 300);
	Enemygrey[19].setPosition(2290, 300);
	Enemygrey[20].setPosition(2080, 360);
	Enemygrey[21].setPosition(2290, 360);
	Enemygrey[22].setPosition(2080, 420);
	Enemygrey[23].setPosition(2150, 420);
	Enemygrey[24].setPosition(2220, 420);
	Enemygrey[25].setPosition(2290, 420);
//wave 3 first green 27
	Enemygrey[26].setPosition(2150, 360);
	Enemygrey[27].setPosition(2220, 360);
//wave 3 second green 32
	Enemygrey[28].setPosition(2460, 360);
	Enemygrey[29].setPosition(2520, 300);
	Enemygrey[30].setPosition(2580, 240);
	Enemygrey[31].setPosition(2520, 420);
	Enemygrey[32].setPosition(2580, 480);
//wave 4 top 36
	Enemygrey[33].setPosition(3000, 240);
	Enemygrey[34].setPosition(3060, 180);
	Enemygrey[35].setPosition(3060, 300);
	Enemygrey[36].setPosition(3120, 240);
//wave 4 bot 40
	Enemygrey[37].setPosition(3000, 420);
	Enemygrey[38].setPosition(3060, 360);
	Enemygrey[39].setPosition(3060, 480);
	Enemygrey[40].setPosition(3150, 470);
//wave 5 49
	Enemygrey[41].setPosition(3720, 110);
	Enemygrey[42].setPosition(3720, 170);
	Enemygrey[43].setPosition(3720, 490);
	Enemygrey[44].setPosition(3720, 320);
	Enemygrey[45].setPosition(3720, 490);
	Enemygrey[46].setPosition(3720, 620);
	Enemygrey[47].setPosition(3970, 110);
	Enemygrey[48].setPosition(3970, 170);
	Enemygrey[49].setPosition(3890, 490);
//wave 6 50 - 70
	Enemygrey[50].setPosition(4560, 130);
	Enemygrey[51].setPosition(4490, 185);
	Enemygrey[52].setPosition(4560, 245);
	Enemygrey[53].setPosition(4560, 305);
	Enemygrey[54].setPosition(4490, 365);
	Enemygrey[55].setPosition(4560, 420);
	Enemygrey[56].setPosition(4560, 480);
	Enemygrey[57].setPosition(4490, 540);
	Enemygrey[58].setPosition(4560, 600);
	Enemygrey[59].setPosition(4550, 365);
	Enemygrey[60].setPosition(4620, 305);
	Enemygrey[61].setPosition(4620, 420);
	Enemygrey[62].setPosition(4680, 245);
	Enemygrey[63].setPosition(4680, 480);
	Enemygrey[64].setPosition(4760, 180);
	Enemygrey[65].setPosition(4760, 240);
	Enemygrey[66].setPosition(4760, 300);
	Enemygrey[67].setPosition(4760, 360);
	Enemygrey[68].setPosition(4760, 420);
	Enemygrey[69].setPosition(4760, 480);
	Enemygrey[70].setPosition(4760, 540);
//wave 71 92
	Enemygrey[71].setPosition(5160, 240);
	Enemygrey[72].setPosition(5220, 300);
	Enemygrey[73].setPosition(5280, 360);
	Enemygrey[74].setPosition(5280, 480);
	Enemygrey[75].setPosition(5220, 540);
	Enemygrey[76].setPosition(5160, 600);
	Enemygrey[77].setPosition(5400, 360);
	Enemygrey[78].setPosition(5460, 300);
	Enemygrey[79].setPosition(5400, 480);
	Enemygrey[80].setPosition(5460, 540);
	Enemygrey[81].setPosition(5160, 420);
	Enemygrey[82].setPosition(5220, 420);
	Enemygrey[83].setPosition(5280, 420);
	Enemygrey[84].setPosition(5400, 420);
	Enemygrey[85].setPosition(5460, 420);
	Enemygrey[86].setPosition(5340, 240);
	Enemygrey[87].setPosition(5340, 300);
	Enemygrey[88].setPosition(5340, 360);
	Enemygrey[89].setPosition(5340, 480);
	Enemygrey[90].setPosition(5340, 540);
	Enemygrey[91].setPosition(5340, 600);
	Enemygrey[92].setPosition(5340, 420);

	for (int i = 0; i < Enemygrey.size(); i++)
	{
		if (!Enemygrey[i].isAlive())
		{
			Enemygrey[i].setAlive(true);
			Enemygrey[i].setVelocity(0, 50);
			Enemygrey[i].setPosition(260, 300);
			return;
		}
	}


}


void EnemyManager::deathCheck(){}


//Render all alive Enemies
void EnemyManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < Enemygrey.size(); i++)
	{
		if (Enemygrey[i].isAlive())
		{
			window->draw(Enemygrey[i]);
		}
	}
}
