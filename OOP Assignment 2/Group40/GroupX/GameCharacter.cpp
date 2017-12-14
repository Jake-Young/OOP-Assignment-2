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

GameCharacter::GameCharacter(std::string name, float hp, float weight, int food) :
	characterName_{ name }, health_{ hp }, weightLimit_{ weight }, food_{ food }
{
	equippedWeapon_ = -1;
	equippedArmour_ = -1;
	state_ = CharacterState::Idle;
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

}

