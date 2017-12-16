/*
Black Witch Class Created by Niall Devlin
Version 1.8
Updated 12/12/2017
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
	BlackWitch(std::string name, float health, float weightLimit, int food, CharacterState state, int magicProf, int darkPow) : GameCharacter{ name, health, weightLimit, food, state }, magicProficiency_ { magicProf }, darkPower_{ darkPow } {}
	~BlackWitch();

	//getters
	int GetMagicProficiency() const;
	int GetDarkPower() const;

	//setters
	void SetMagicProficiency(int magicProf);
	void SetDarkPower(int darkPow);

	//functions
	bool Attack(GameCharacter &character);
	void Bewitch(GameCharacter &character);
	void Sleep();
};

