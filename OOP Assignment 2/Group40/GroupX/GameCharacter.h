/*
* GameCharacter.h
*
* Version information v0.1
* Authors: <Insert group member names and IDs> of student(s) who write each class
* Date: 24/11/2017
* Description: header file for GameCharacter class
* Copyright notice
*/


#pragma once
#include <string>
#include <vector>
class GameCharacter
{
private:
	std::string characterName_;
	float health_;
	float weightLimit_;
	int weapon_;
	int armour_;
	//Weapon vector goes here
	//Armour vector goes here
	int food_;
	//Character state enum goes here

public:
	GameCharacter();
	GameCharacter(std::string name, float hp, float weight, int weapon, int armour, int food) :
		characterName_{ name }, health_{ hp }, weightLimit_{ weight }, weapon_{ weapon }, armour_{ armour } {} //Edit this custom constructor if needed
	~GameCharacter();

	//Getters
	std::string GetName() const { return characterName_; }
	float GetHealth() const { return health_; }
	float GetWeightLimit() const { return weightLimit_; }
	int GetWeapon() const { return weapon_; }
	int GetArmour() const { return armour_; }
	//Getters for vectors goes here?
	int GetFood() const { return food_; }
	//Get character state

	//Setters
	void SetName(std::string name) { characterName_ = name; }
	void SetHealth(float hp) { health_ = hp; }
	void SetWeightLimit(float weight) { weightLimit_ = weight; }
	void SetWeapon(int weapon) { weapon_ = weapon; }
	void SetArmour(int armour) { armour_ = armour; }
	//Setters for vectors?
	void SetFood(int food) { food_ = food; }
	//Set character state

	//Functions
	virtual bool Attack(GameCharacter &character);
};

