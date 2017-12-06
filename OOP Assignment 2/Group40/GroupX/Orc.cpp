/*
Orc Class Created by Niall Devlin
Version 1.5
Updated 06/12/2017
*/

#include "Orc.h"



Orc::Orc()
{
}


Orc::~Orc()
{
}

int Orc::GetFerocity() const
{
	return ferociousness_;
}

int Orc::GetStrength() const
{
	return strength_;
}

void Orc::SetFerocity(int ferocity)
{
	ferociousness_ = ferocity;
}

void Orc::SetStrength(int str)
{
	strength_ = str;
}

void Orc::Scream(GameCharacter & character)
{
	//20% chance of making the target character flee
	//chances of success increases by 5% for each ferocity point
	int screamSuccessChance = 20 + (ferociousness_ * 5);

	if (screamSuccessChance >= 100)
	{
		//scream will always succeed
		//need character state enum for this
	}
	else
	{
		int screamSuccessRoll = GetRandomNumber(0, 100);

		if (screamSuccessRoll <= screamSuccessChance)
		{
			//successful scream
			//need character state enum for this
		}
	}

}
