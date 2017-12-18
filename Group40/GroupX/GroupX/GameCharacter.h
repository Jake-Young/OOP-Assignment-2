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
#include "Weapon.h"
#include "Armour.h"
#include <string>
#include <vector>

enum CharacterState { Idle, Running, Sleeping, Walking, Defending, Dead };

class GameCharacter
{
private:
	std::string characterName_;
	float health_;
	float weightLimit_;
	int equippedWeapon_;
	int equippedArmour_;
	std::vector<Weapon> weapons_;
	std::vector<Armour> armour_;
	int food_;
	CharacterState state_;

public:
	GameCharacter();
	GameCharacter(std::string name, float health, float weightLimit, int food, CharacterState state);
	~GameCharacter();

	//Getters
	std::string GetName();
	float GetHealth();
	float GetWeightLimit();
	int GetEquippedWeapon(); //these have changed
	int GetEquippedArmour();
	int GetFood();
	Weapon GetWeapon(int index);
	Armour GetArmour(int index);
	CharacterState GetState();
	/*Weapon GetEquippedWeapon();
	Armour GetEquippedArmour();*/
	void GetWalk();
	void GetRun();
	void GetAddFood(int amount);
	void GetEat();

	//Setters
	void SetName(std::string name);
	void SetHealth(float hp);
	void SetWeightLimit(float weight);
	void SetWeapon(int weapon);
	void SetArmour(int armour);
	void SetFood(int food);
	void SetState(CharacterState newState);

	//Functions
	virtual bool Attack(GameCharacter &character) = 0; //make abstract class
	void Defend(int armour);
	virtual void Sleep() {};
	bool PickUpWeapon(Weapon &weapon);
	bool PickUpArmour(Armour &armour);
	void DropArmour(Armour & armour);
	void DropWeapon(Weapon & weapon);
	bool EquipWeapon(int weapon);
	void RemoveWeapon(int weapon);
	void RemoveArmour(int armour);

	//Laura's work
	void Walk();
	void Run();
	void AddFood(int amount);
	void Eat();


	//Random number generator
	int GetRandomNumber(int min, int max);
};

