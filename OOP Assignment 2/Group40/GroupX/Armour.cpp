/*
Armour.cpp created by Jake Young
Version 1
Updated 05/11/2017
*/

#include "Armour.h"

Armour::Armour()
{

}

Armour::Armour(std::string armourName, int value, float weight, int defence, int armourHealth, ArmourType armourType) 
	: Item{ armourName, value, weight }, defence_{ defence }, armourHealth_{ armourHealth }, armourType_{armourType}
{

}

Armour::~Armour()
{

}
