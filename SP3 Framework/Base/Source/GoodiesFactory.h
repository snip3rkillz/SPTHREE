#pragma once
#include "TreasureChest.h"
#include "HealthPack.h"

typedef int GoodiesID;
#define TREASURECHEST 0
#define HEALTHPACK 1

class CGoodiesFactory
{

public:
	CGoodiesFactory();
	~CGoodiesFactory();

	CGoodies* Create(GoodiesID);
};

