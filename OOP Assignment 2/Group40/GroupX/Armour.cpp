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

void Armour::SetDefence(int defence)
{
	defence_ = defence;
}

int Armour::GetDefence()
{
	return defence_;
}

void Armour::SetArmourHealth(int armourHealth)
{
	armourHealth_ = armourHealth;
}

int Armour::GetArmourHealth()
{
	return armourHealth_;
}

void Armour::SetArmourType(ArmourType armourType)
{
	armourType_ = armourType; //Wait to see functionality, may need to be adpated
}

ArmourType Armour::GetArmourType()
{
	return armourType_; //Wait to see functionality, may need to be adpated
}
