/*
Weapon.h created by Jake Young
Version 1
Updated 05/11/2017
*/

#pragma once

#include "Item.h"

class Weapon : public Item {

private:
	int weaponHitStrength_;
	int weaponHealth_;

public:
	Weapon();

	Weapon(std::string weaponName, int value, float weight, int weaponHitStrength, int weaponHealth);

	~Weapon();

	void SetWeaponHitStrength(int weaponHitStrength);
	int GetWeaponHitStrength();

	void SetWeaponHealth(int weaponHealth);
	int GetWeaponHealthI();

};
