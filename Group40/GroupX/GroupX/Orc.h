/*
Orc Class Created by Niall Devlin
Version 1.75
Updated 08/12/2017
*/

#pragma once

#include "GameCharacter.h"
class Orc :
	public GameCharacter
{
private:
	int ferociousness_;
	int strength_;
public:
	Orc();
	Orc(std::string name, float health, float weightLimit, int food, CharacterState state, int ferocity, int str) : GameCharacter{ name, health, weightLimit, food, state }, ferociousness_{ ferocity }, strength_{ str } {}
	~Orc();

	//Getters
	int GetFerocity() const;
	int GetStrength() const;

	//Setters
	void SetFerocity(int ferocity);
	void SetStrength(int str);

	//Functions
	virtual bool Attack(GameCharacter &character);
	void Scream(GameCharacter &character);
	void Sleep();
};