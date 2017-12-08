/*
* GameCharacter.cpp
*
* Version information v0.5
* Authors: <Insert group member names and IDs> of student(s) who write each class
* Date: 06/12/2017
* Description: Implementation for GameCharacter class
* Copyright notice
*/

#include "GameCharacter.h"
#include <random>


GameCharacter::GameCharacter(){
}


GameCharacter::~GameCharacter(){
}

void GameCharacter::AddWeapon(Weapon newWeapon)
{
	//add new weapon to character's weapons
	weaponList_.push_back(newWeapon);
}

void GameCharacter::RemoveWeapon(std::string weaponName)
{
	//remove weapon from vector
	for (int index = 0; index < weaponList_.max_size(); index++)
	{
		if (weaponList_[index].GetItemName() == weaponName)
			weaponList_.erase(weaponList_.begin() + index);
	}
}

void GameCharacter::AddArmour(Armour newArmour)
{
	//add new armour to character's armour list
	armourList_.push_back(newArmour);
}

void GameCharacter::RemoveArmour(std::string armourName)
{
	//remove weapon from vector
	for (int index = 0; index < armourList_.max_size(); index++)
	{
		if (armourList_[index].GetItemName() == armourName)
			armourList_.erase(armourList_.begin() + index);
	}
}

bool GameCharacter::Attack(GameCharacter & character)
{
	//check if the character can attack

	//get equipped weapon
	Weapon* equippedWeapon{ &GetEquippedWeapon() };

	//NOTE: Brawler can attack with no weapon
	if (equippedWeapon != nullptr && health_ > 20 && character.GetHealth() > 0 /*OR if the def character state is set to dead*/)
	{
		//can attack		

		//get defender's armour
		Armour* defenderArmour{ &character.GetEquippedArmour() };

		//get a random number between 0 and 100 to represent the chances of a successful attack
		int attackChance = GetRandomNumber(0, 100);
		int successChance = 0; //chances of the attack being successful

		//determine the precentage of successful attack
		if (defenderArmour == nullptr)
		{
			//80% chance of successful attack if defending character has no armour
			successChance = 80;
		}
		else if (equippedWeapon->GetWeaponHitStrength() < defenderArmour->GetDefence())
		{
			//20% chance of success
			successChance = 20;
		}
		else
		{
			//60% chance of success
			successChance = 60;
		}

		//try to attack
		if (attackChance <= successChance)
		{
			//successful attack

			/*- 10% health if defending character state is defending
			-100% health is sleeping
			no effect if dead
			-20% if any other state
			Armour health reduced by 10%
			*/
			//^ need character state and armour class for these ^ 
		}
		else
		{
			//unsuccessful attack

			//reduce weapon health by 10 or 20% if the defender has armour
			if (defenderArmour == nullptr)
			{
				int damagePrecentage = GetRandomNumber(10, 20);
				int currentWeaponHealth = equippedWeapon->GetWeaponHealthI();
				int weaponDamage = currentWeaponHealth - ((currentWeaponHealth / 100) * damagePrecentage);
				equippedWeapon->SetWeaponHealth(weaponDamage);
			}
		}

		//free memory and return true
		delete equippedWeapon;
		delete defenderArmour;
		equippedWeapon = nullptr;
		defenderArmour = nullptr;
		return true;
	}
	else
	{
		//cannot attack
		//free memory and return false
		delete equippedWeapon;
		equippedWeapon = nullptr;
		return false;
	}
}

int GameCharacter::GetRandomNumber(int min, int max)
{
	//random number generator
	std::random_device rDev{};
	std::default_random_engine e{ rDev() };
	std::uniform_int_distribution<int> d{ min, max };
	return d(e);
}
