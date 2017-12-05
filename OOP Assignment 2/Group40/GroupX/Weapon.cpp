/*
Weapon.cpp created by Jake Young
Version 1
Updated 05/11/2017
*/

#include "Weapon.h"

Weapon::Weapon()
{

}

Weapon::Weapon(std::string weaponName, int value, float weight, int weaponHitStrength, int weaponHealth) :
	Item{ weaponName, value, weight }, weaponHitStrength_{ weaponHitStrength }, weaponHealth_{weaponHealth}
{

}

Weapon::~Weapon()
{

}
