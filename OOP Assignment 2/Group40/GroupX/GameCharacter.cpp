/*
* GameCharacter.cpp
*
* Version information v0.1
* Authors: <Insert group member names and IDs> of student(s) who write each class
* Date: 24/11/2017
* Description: Implementation for GameCharacter class
* Copyright notice
*/

#include "GameCharacter.h"
#include "RandomNumberGenerator.h"


GameCharacter::GameCharacter(){
}


GameCharacter::~GameCharacter(){
}

bool GameCharacter::Attack(GameCharacter & character)
{
	//check if the character can attack
	//NOTE: Brawler can attack with no weapon
	if (weapon_ != 0 && health_ > 20 && character.GetHealth() > 0 /*OR if the state is set to dead*/)
	{
		//can attack

		//get a random number between 0 and 100 to represent the chances of a successful attack
		RandomNumberGenerator* rng{ new RandomNumberGenerator{} };
		int attackChance = rng->GetRandomNumber(0, 100);
		delete rng; //free memory
		rng = nullptr;
		int successChance = 0; //chances of the attack being successful

		/*if hit strength of the weapon used by attacker is < defence value 
		of armour of the defending character, then there is only 20% chance of a auccessful
		attack. Otherwise there is a 60% chance of a successful attack
		*/
		//^ NOTE: Need weapon class for this ^

		//If defender is not wearing any armour, there is an 80% chance of a successful attack
		if (character.GetArmour() <= 0)
		{
			//80% chance of successful attack
			successChance = 80;

		}

		//try to attack
		if (attackChance <= successChance)
		{
			//successful attack

			/*- 10% health if defending character state is defending
			-100% health is sleeping
			no effect if dead
			-20% if any other state
			Armour health reduced by 10%
			*/
			//^ need character state and armour class for these ^ 
		}
		else
		{
			//unsuccessful attack

			//reduce weapon health, < need weapon class for this <
		}

		return true;
	}
	else
	{
		//cannot attack
		return false;
	}
}
