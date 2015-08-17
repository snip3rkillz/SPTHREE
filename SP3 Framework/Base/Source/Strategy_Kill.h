#pragma once
#include <Vector2.h>
#include "Strategy.h"

class CStrategy_Kill
	: public CStrategy
{

public:
	CStrategy_Kill();
	~CStrategy_Kill();

	void Update();
	void SetDestination(const float x, const float y);
	void SetEnemyPosition(const float x, const float y);
	void GetEnemyPosition(float& x, float& y);

	//The AI states of the enemy
	enum CURRENT_STATE
	{
		PATROL,
		REPEL,
		ATTACK,
		NUM_ENEMY_STATE,
	};

	void SetState(CStrategy_Kill::CURRENT_STATE);
	CStrategy_Kill::CURRENT_STATE GetState();
	
private:
	//Enemy AI State
	CStrategy_Kill::CURRENT_STATE CurrentState;
};

