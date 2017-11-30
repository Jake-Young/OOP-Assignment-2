/*
Black Witch Class Created by Niall Devlin
Version 1.1
Updated 29/11/2017
*/

#pragma once
#include "GameCharacter.h"
class BlackWitch :
	public GameCharacter
{
private:
	int magicProficiency_;
	int darkPower_;
public:
	BlackWitch();
	BlackWitch(int magicProf, int darkPow) : magicProficiency_{ magicProf }, darkPower_{ darkPow } {}
	~BlackWitch();

	//getters
	int GetMagicProficiency() const;
	int GetDarkPower() const;

	//setters
	void SetMagicProficiency(int magicProf);
	void SetDarkPower(int darkPow);

	//functions
	virtual bool Attack(GameCharacter &character);
	void Bewitch(GameCharacter &character);
};

