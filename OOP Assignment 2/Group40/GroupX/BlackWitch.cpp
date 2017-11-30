/*
Black Witch Class Created by Niall Devlin
Version 1.1
Updated 29/11/2017
*/

#include "BlackWitch.h"
#include "RandomNumberGenerator.h"


BlackWitch::BlackWitch()
{
}


BlackWitch::~BlackWitch()
{
}

int BlackWitch::GetMagicProficiency() const
{
	return magicProficiency_;
}

int BlackWitch::GetDarkPower() const
{
	return darkPower_;
}

void BlackWitch::SetMagicProficiency(int magicProf)
{
	magicProficiency_ = magicProf;
}

void BlackWitch::SetDarkPower(int darkPow)
{
	darkPower_ = darkPow;
}

void BlackWitch::Bewitch(GameCharacter & character)
{
	//Attempt to sleep character NOTE: need character state enum

	//10 + (5 * proficency) = success precentage
	//Success precentage
	int successChance = 10 + (5 * magicProficiency_);

	if (successChance >= 100)
	{
		//Bewitch will always succeed

		//set target character to sleep
	}
	else
	{
		//random chance of bewitch succeeding
		RandomNumberGenerator* rng{ new RandomNumberGenerator{} };
		int randomChance = rng->GetRandomNumber(0, 100);
		delete rng; //free memory
		rng = nullptr;

		if (randomChance <= successChance)
		{
			//bewitch succeeds, set target character to sleep
		}
		else
		{
			//failure to sleep
		}
	}
		

	
}
