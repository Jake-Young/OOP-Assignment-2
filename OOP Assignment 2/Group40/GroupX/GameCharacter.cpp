/*
* GameCharacter.cpp
*
* Version information v0.5
* Authors: <Insert group member names and IDs> of student(s) who write each class
* Date: 08/12/2017
* Description: Implementation for GameCharacter class
* Copyright notice
*/

#include "GameCharacter.h"
#include <random>


GameCharacter::GameCharacter(){
}

GameCharacter::GameCharacter(std::string name, float health, float weightLimit, int food, CharacterState state) : characterName_{ name }, health_{ health }, weightLimit_{ weightLimit }, food_{ food }, state_{ state }
{
	equippedWeapon_ = -1;
	equippedArmour_ = -1;
}


GameCharacter::~GameCharacter(){
}

void GameCharacter::RemoveWeapon(int weapon)
{
	weapons_.erase(weapons_.begin() + weapon);
	equippedWeapon_ = -1;
}

void GameCharacter::RemoveArmour(int armour)
{
	armour_.erase(armour_.begin() + armour);
	equippedArmour_ = -1;
}

void GameCharacter::Defend(int armour)
{
	//Try to equip Armour, armour is -1 if the armour value isnt valid
	if (armour < armour_.size() && armour > 0)
		equippedArmour_ = armour;		
	else
		equippedArmour_ = -1;

	//Set state to defending
	SetState(CharacterState::Defending);

	
}

bool GameCharacter::PickUpWeapon(Weapon &weapon) {

	float totalWeight = 0;

	for (int i = 0; i < weapons_.size(); i++) {
		totalWeight += weapons_[i].GetWeight();
	}

	for (int i = 0; i < armour_.size(); i++) {
		totalWeight += armour_[i].GetWeight();
	}

	if (totalWeight > weightLimit_) {
		return false;
	}
	else {
		weapons_.push_back(weapon);
		return true;
	}

}


bool GameCharacter::PickUpArmour(Armour &armour) {

	float totalWeight = 0;

	for (int i = 0; i < weapons_.size(); i++) {
		totalWeight += weapons_[i].GetWeight();
	}

	for (int i = 0; i < armour_.size(); i++) {
		totalWeight += armour_[i].GetWeight();
	}

	if (totalWeight > weightLimit_) {
		return false;
	}
	else {
		armour_.push_back(armour);
		return true;
	}

}

void GameCharacter::DropArmour(Armour &armour)
{
	for (size_t i = 0; i < armour_.size(); i++)
	{
		//Check if the weapon matches the weapon that is being drop
		if (armour_.at(i).GetArmourType() == armour.GetArmourType() && armour_.at(i).GetValue() == armour.GetValue() && armour_.at(i).GetWeight() == armour.GetWeight()
			&& armour_.at(i).GetItemName() == armour.GetItemName() && armour_.at(i).GetDefence() == armour.GetDefence()
			&& armour_.at(i).GetArmourHealth() == armour.GetArmourHealth())
		{
			armour_.erase(armour_.begin() + i);

			//
			if (GetEquippedArmour().GetArmourHealth() == armour.GetArmourHealth() && GetEquippedArmour().GetArmourType() == armour.GetArmourType()
				&& GetEquippedArmour().GetDefence() == armour.GetDefence() && GetEquippedArmour().GetItemName() == armour.GetItemName() &&
				GetEquippedArmour().GetValue() == armour.GetValue() && GetEquippedArmour().GetWeight() == armour.GetWeight())
			{
				equippedArmour_ = -1;
			}
		}

	}
}

void GameCharacter::DropWeapon(Weapon &weapon)
{
	for (size_t i = 0; i < weapons_.size(); i++)
	{
		if (weapons_.at(i).GetItemName() == weapon.GetItemName()
			&& weapons_.at(i).GetValue() == weapon.GetValue()
			&& weapons_.at(i).GetWeaponHealth() == weapon.GetWeaponHealth()
			&& weapons_.at(i).GetWeaponHitStrength() == weapon.GetWeaponHitStrength() && weapons_.at(i).GetWeight() == weapon.GetWeight())

			weapons_.erase(weapons_.begin() + i);
		if (GetEquippedWeapon().GetItemName() == weapon.GetItemName() && GetEquippedWeapon().GetValue() == weapon.GetValue() && GetEquippedWeapon().GetWeaponHealth() == weapon.GetWeaponHealth()
			&& GetEquippedWeapon().GetWeaponHitStrength() == weapon.GetWeight() && GetEquippedWeapon().GetWeight() == weapon.GetWeight())
		{
			equippedWeapon_ = -1;
		}
	}
}

bool GameCharacter::EquipWeapon(int weapon)
{
	if (weapon > -1 && weapon < weapons_.size())
	{
		equippedWeapon_ = weapon;
		return true;
	}
	else
	{
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
// From here may need changed (Laura)

// changing the state to walk
void GameCharacter::Walk()
{
	// Changes the character state to Walking
	SetState(CharacterState::Walking);

}

// changing the state to run 
void GameCharacter::Run()
{
	// Changes the character state to Running
	SetState(CharacterState::Running);

}

void GameCharacter::AddFood(int amount)
{
	//Adds the amount of food to the food_ value
	food_ += amount;
}

// eat food 
void GameCharacter::Eat()
{
	//Consumes 20% of the available food. Each unit (1) of food consumed will add 0.25 units of health to the character.
	float foodConsume = food_ *0.20f;

	food_ -= foodConsume;

	health_ += foodConsume * 0.25f;

	//ensure hp does not exceed 100
	if (health_ > 100)
		health_ = 100;

}

