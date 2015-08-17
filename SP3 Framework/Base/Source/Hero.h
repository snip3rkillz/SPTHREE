#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <Vector2.h>
#include "Map.h"
#include "Enemy.h"

class Hero
{

private:
	//Hero's information
	int  theHeroPositionx;
	int  theHeroPositiony;
	int  jumpspeed;
	bool hero_inMidAir_Up;
	bool hero_inMidAir_Down;
	int  heroAnimationCounter;
	bool heroAnimationInvert;

public:
	Hero();
	~Hero();

	//Set the position x of the player
	void settheHeroPositionx(int theHeroPositionx_);
	//Get the position x of the player
	int gettheHeroPositionx();

	//Set the position of y of the player
	void settheHeroPositiony(int settheHeroPositiony_);
	//Get position y of the player
	int gettheHeroPositiony();

	//Set Animation Invert status of the player
	void SetAnimationInvert(bool heroAnimationInvert_);
	//Get Animation Invert status of the palyer
	bool GetAnimationInvert();

	//Set Animation Counter of the player
	void SetAnimationCounter(int heroAnimationCounter_);
	//Get Animation counter of the player
	int GetAnimationCounter();

	//Constrain the position of the Hero to within the border
	void ConstrainHero(CMap *mapType, const int leftBorder, const int rightBorder, const int topBorder, const int bottomBorder, float timeDiff);

	//Check for collision of hero with obstacles in a certain direction
	bool CheckCollision(CMap *mapType, bool checkleft, bool checkright, bool checkdown, bool checkup);

	//Methods for Hero
	void HeroUpdate(CMap *mapType, const char key, const bool jump, int level);
	void HeroJump();
	void UpdateJumpUP();
	void UpdateFallDOWN();
	void HeroMoveUpDown(const bool mode, const float timeDiff);
	void HeroMoveLeftRight(const bool mode, const float timeDiff);
};

#endif