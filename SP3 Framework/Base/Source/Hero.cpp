#include "Hero.h"

static const float Max_mapOffset_x = 1024;

Hero::Hero()
	: theHeroPositionx(0)
	, theHeroPositiony(0)
	, jumpspeed(0)
	, hero_inMidAir_Up(false)
	, hero_inMidAir_Down(false)
	, heroAnimationCounter(0)
	, heroAnimationInvert(false)
{
}

Hero::~Hero()
{
}

void Hero::settheHeroPositionx(int theHeroPositionx_)
{
	 theHeroPositionx = theHeroPositionx_;
}

void Hero::settheHeroPositiony(int theHeroPositiony_)
{
	 theHeroPositiony = theHeroPositiony_;
}

void Hero::SetAnimationInvert(bool heroAnimationInvert_)
{
	heroAnimationInvert = heroAnimationInvert_;
}

void Hero::SetAnimationCounter(int heroAnimationCounter_)
{
	heroAnimationCounter = heroAnimationCounter_;
}

int Hero::gettheHeroPositionx()
{
	return theHeroPositionx;
}

int Hero::gettheHeroPositiony()
{
	return theHeroPositiony;
}

bool Hero::GetAnimationInvert()
{
	return heroAnimationInvert;
}

int Hero::GetAnimationCounter()
{
	return heroAnimationCounter;
}

void Hero::ConstrainHero(CMap *mapType, const int leftBorder, const int rightBorder, const int topBorder, const int bottomBorder, float timeDiff)
{
	if(theHeroPositionx < leftBorder)
	{
		theHeroPositionx = leftBorder;
		mapType->mapOffset_x = mapType->mapOffset_x - (int)(5.0f * timeDiff);
		
		if(mapType->mapOffset_x < 0)
			mapType->mapOffset_x = 0;
	}

	else if(theHeroPositionx > rightBorder)
	{
		theHeroPositionx = rightBorder;
		mapType->mapOffset_x = mapType->mapOffset_x + (int)(5.0f * timeDiff);
		
		if(mapType->mapOffset_x > Max_mapOffset_x)
			mapType->mapOffset_x = Max_mapOffset_x;
	}

	if(theHeroPositiony < topBorder)
	{
		theHeroPositiony = topBorder;
	}
	
	else if(theHeroPositiony > bottomBorder)
	{
		theHeroPositiony = bottomBorder;
	}
}

bool Hero::CheckCollision(CMap *mapType, bool checkleft, bool checkright, bool checkdown, bool checkup)
{
	int tileTopLeft_x = (int) ((mapType->mapOffset_x + theHeroPositionx) / mapType->GetTileSize());
	int tileTopLeft_y = mapType->GetNumOfTiles_Height() - (int)ceil( (float)(theHeroPositiony + mapType->GetTileSize() + jumpspeed) / mapType->GetTileSize());

	if(checkleft)
	{
		if(mapType->theScreenMap[tileTopLeft_y][tileTopLeft_x] == 1)
		{
			return true;
		}
	}

	else if(checkright)
	{
		if(mapType->theScreenMap[tileTopLeft_y][tileTopLeft_x + 1] == 1)
		{
			return true;
		}
	}

	else if(checkup)
	{
		if(mapType->theScreenMap[tileTopLeft_y][tileTopLeft_x] == 1 || mapType->theScreenMap[tileTopLeft_y][tileTopLeft_x + 1] == 1)
		{
			return true;
		}
	}

	else if(checkdown)
	{
		if(mapType->theScreenMap[tileTopLeft_y + 1][tileTopLeft_x] == 1 || mapType->theScreenMap[tileTopLeft_y + 1][tileTopLeft_x + 1] == 1)
		{
			return true;
		}
	}

	return false;
}

void Hero::HeroUpdate(CMap *mapType, const char key, const bool jump, int level) 
{	
	//Update walking
	if(key == 'a' && !CheckCollision(mapType, true, false, false, false))
	{
		HeroMoveLeftRight(true, 1.0f);
	}
	
	else if(key == 'd' && !CheckCollision(mapType, false, true, false, false))
	{
		HeroMoveLeftRight(false, 1.0f);
	}
	
	if(key == 'w' && !CheckCollision(mapType, false, false, false, true))
	{
		HeroMoveUpDown(true, 1.0f);
	}

	else if(key == 's' && !CheckCollision(mapType, false, false, true, false))
	{
		HeroMoveUpDown(false, 1.0f);
	}

	/*if(level == 2)
	{
		//Update jumping
		if(jump)
		{
			HeroJump();
		}

		//Update Hero's info
		if(hero_inMidAir_Up == false && hero_inMidAir_Down == false)
		{
			//Don't jump, standing on ground - Make player fall if not standing on tile
			hero_inMidAir_Down = true;
		}

		else if(hero_inMidAir_Up == true && hero_inMidAir_Down == false)
		{
			if(CheckCollision(false, false, false, true))
			{
				//Since the new position does not allow the hero to move into, then go back to the old position
				theHeroPositiony = ((int) (theHeroPositiony / m_cMap->GetTileSize())) * m_cMap->GetTileSize();
				hero_inMidAir_Up = false;
				hero_inMidAir_Down = true;
				jumpspeed = 0;
			}

			else
			{
				UpdateJumpUP();
			}
		}

		else if(hero_inMidAir_Up == false && hero_inMidAir_Down == true)
		{
			if(CheckCollision(false, false, true, false))
			{
				//Since the new position does not allow the hero to move into, then go back to the old position
				theHeroPositiony = ((int) (theHeroPositiony / m_cMap->GetTileSize())) * m_cMap->GetTileSize();
				hero_inMidAir_Down = false;
				jumpspeed = 0;
			}

			else
			{
				UpdateFallDOWN();
			}
		}
	}*/

	mapType->tileOffset_x = (int)(mapType->mapOffset_x / mapType->GetTileSize());
	if(mapType->tileOffset_x + mapType->GetNumOfTiles_Width() > mapType->getNumOfTiles_MapWidth())
	{
		mapType->tileOffset_x = mapType->getNumOfTiles_MapWidth() -mapType->GetNumOfTiles_Width();
	}

	if(level == 1)
	{
		ConstrainHero(mapType, 0, 960, 25, 740, 1.0f);
	}

	else
	{
		ConstrainHero(mapType, 25, 750, 25, 740, 1.0f);
	}
} 

void Hero::HeroJump() 
{ 
	if(hero_inMidAir_Up == false && hero_inMidAir_Down == false) 
	{ 
		hero_inMidAir_Up = true;
		jumpspeed = 15;
	} 
} 

void Hero::UpdateJumpUP()
{
	theHeroPositiony += jumpspeed;
	jumpspeed -= 1;
	
	if(jumpspeed == 0)
	{
		hero_inMidAir_Up = false;
		hero_inMidAir_Down = true;
	}
}

void Hero::UpdateFallDOWN()
{
	theHeroPositiony += jumpspeed;
	jumpspeed -= 1;
}

void Hero::HeroMoveUpDown(const bool mode, const float timeDiff) 
{ 
	if(mode) 
	{ 
		theHeroPositiony = theHeroPositiony + (int) (5.0f * timeDiff); 
	}  

	else 
	{ 
		theHeroPositiony = theHeroPositiony - (int) (5.0f * timeDiff); 
	}

	/*heroAnimationCounter++;
	if(heroAnimationCounter > 4)
	{
		heroAnimationCounter = 0;
	}*/
} 

void Hero::HeroMoveLeftRight(const bool mode, const float timeDiff) 
{ 
	if(mode) 
	{ 
		theHeroPositionx = theHeroPositionx - (int) (5.0f * timeDiff);
		heroAnimationInvert = true;
	}

	else 
	{ 
		theHeroPositionx = theHeroPositionx + (int) (5.0f * timeDiff);
		heroAnimationInvert = false;
	}

	/*heroAnimationCounter++;
	if(heroAnimationCounter > 4)
	{
		heroAnimationCounter = 0;
	}*/
}