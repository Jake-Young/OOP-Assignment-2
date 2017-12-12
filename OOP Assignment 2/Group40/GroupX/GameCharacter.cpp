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

GameCharacter::GameCharacter(std::string name, float hp, float weight) :
	characterName_{ name }, health_{ hp }, weightLimit_{ weight }
{
	weapon_ = -1;
	armour_ = -1;
	food_ = -1;
	state_ = CharacterState::Idle;
}


GameCharacter::~GameCharacter(){
}

void GameCharacter::Defend(int armour)
{
	//Try to equip Armour, armour is -1 if the armour value isnt valid
	if (armour < armourList_.size() && armour > 0)
		armour_ = armour;		
	else
		armour_ = -1;

	//Set state to defending
	SetState(CharacterState::Defending);

	
}

bool GameCharacter::PickUpWeapon(Weapon &weapon) {

	float totalWeight = 0;

	for (int i = 0; i < weaponList_.size(); i++) {
		totalWeight += weaponList_[i].GetWeight();
	}

	for (int i = 0; i < armourList_.size(); i++) {
		totalWeight += armourList_[i].GetWeight();
	}

	if (totalWeight > weightLimit_) {
		return false;
	}
	else {
		weaponList_.push_back(weapon);
		return true;
	}

}


bool GameCharacter::PickUpArmour(Armour &armour) {

	float totalWeight = 0;

	for (int i = 0; i < weaponList_.size(); i++) {
		totalWeight += weaponList_[i].GetWeight();
	}

	for (int i = 0; i < armourList_.size(); i++) {
		totalWeight += armourList_[i].GetWeight();
	}

	if (totalWeight > weightLimit_) {
		return false;
	}
	else {
		armourList_.push_back(armour);
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
