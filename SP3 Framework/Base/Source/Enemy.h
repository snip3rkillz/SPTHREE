#pragma once
#include <Vector2.h>
#include "Map.h"
#include "Strategy_Kill.h"

class CEnemy
{

private:
	//Enemy's information
	Vector2 theENEMYPosition;
	int  enemyAnimationCounter;
	bool enemyAnimationInvert;

	//The Destination is the position of the Hero
	Vector2 theDestination;
	CStrategy *theStrategy;

public:
	CEnemy();
	~CEnemy();

	//Initialise this class instance
	void Init();

	//Set position x of the enemy
	void SetPos_x(int pos_x);
	//Get position x of the enemy
	int GetPos_x();

	//Set position y of the enemy
	void SetPos_y(int pos_y);
	//Get position y of the enemy
	int GetPos_y();

	//Set the destination of this enemy
	void SetDestination(const int pos_x, const int pos_y);
	//Get destination of this enemy
	int GetDestination_x();
	//Get destination of this enemy
	int GetDestination_y();

	//Enemy Update
	void Update(CMap* m_cMap);

	//Strategy
	void ChangeStrategy(CStrategy* theNewStrategy, bool bDelete = true);

	//Set Animation Invert status of the enemy
	void SetAnimationInvert(bool ENEMYAnimationInvert);
	//Get Animation Invert status of the enemy
	bool GetAnimationInvert();

	//Set Animation Counter of the enemy
	void SetAnimationCounter(int ENEMYAnimationCounter);
	//Get Animation Counter of the player
	int GetAnimationCounter();
};

