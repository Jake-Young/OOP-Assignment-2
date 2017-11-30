/*
Orc Class Created by Niall Devlin
Version 1
Updated 28/11/2017
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
	Orc(int ferocity, int str) : ferociousness_{ ferocity }, strength_ { str } {}
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
};

