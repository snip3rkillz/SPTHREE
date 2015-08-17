#include "GoodiesFactory.h"
#include <stdlib.h>

CGoodiesFactory::CGoodiesFactory()
{
}

CGoodiesFactory::~CGoodiesFactory()
{
}

CGoodies* CGoodiesFactory::Create(GoodiesID id)
{
	CGoodies* theNewGoodies = NULL;

	switch(id)
	{
		case TREASURECHEST:
			theNewGoodies = new CTreasureChest;
			break;
		
		case HEALTHPACK:
			theNewGoodies = new CHealthPack;
			break;

		default:
			break;
	}

	return theNewGoodies;
}