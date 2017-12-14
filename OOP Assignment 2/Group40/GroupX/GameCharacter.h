/*
* GameCharacter.h
*
* Version information v0.5
* Authors: <Insert group member names and IDs> of student(s) who write each class
* Date: 08/12/2017
* Description: header file for GameCharacter class
* Copyright notice
*/


#pragma once
#include "Weapon.h"
#include "Armour.h"
#include <string>
#include <vector>

enum class CharacterState {Idle, Running, Sleeping, Walking, Defending, Dead };

class GameCharacter
{
private:
	std::string characterName_;
	float health_;
	float weightLimit_;
	int weapon_;
	int armour_;
	std::vector<Weapon> weaponList_;
	std::vector<Armour> armourList_;
	int food_;
	CharacterState state_;

public:

	GameCharacter();
	GameCharacter(std::string name, float hp, float weight);
	~GameCharacter();

	//Getters
	std::string GetName() const { return characterName_; }
	float GetHealth() const { return health_; }
	float GetWeightLimit() const { return weightLimit_; }
	int GetWeapon() const { return weapon_; }
	int GetArmour() const { return armour_; }
	int GetFood() const { return food_; }
	Weapon GetWeapon(int index) { return weaponList_[index]; }
	Armour GetArmour(int index) { return armourList_[index]; }
	CharacterState GetState() { return state_; }
	Weapon GetEquippedWeapon() { return weaponList_[weapon_]; }
	Armour GetEquippedArmour() { return armourList_[armour_]; }
	void GetWalk() { state_ = CharacterState::Walking; }
	void GetRun() { state_ = CharacterState::Running; }
	void GetAddFood(int amount) { food_ += amount; }
	void GetEat() { food_--; }

	//Setters
	void SetName(std::string name) { characterName_ = name; }
	void SetHealth(float hp) { health_ = hp; }
	void SetWeightLimit(float weight) { weightLimit_ = weight; }
	void SetWeapon(int weapon) { weapon_ = weapon; }
	void SetArmour(int armour) { armour_ = armour; }
	void SetFood(int food) { food_ = food; }
	void SetState(CharacterState newState) { state_ = newState; }

	//Functions
	virtual bool Attack(GameCharacter &character)=0; //make abstract class
	void Defend(int armour);
	virtual void Sleep() {};
	bool PickUpWeapon(Weapon &weapon);
	bool PickUpArmour(Armour &armour);

	//Laura's work
	void Walk();
	void Run();
	void AddFood(int amount);
	void Eat();


	//Random number generator
	int GetRandomNumber(int min, int max);
};

