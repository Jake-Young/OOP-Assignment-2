/*
Black Witch Class Created by Niall Devlin
Version 1.8
Updated 12/12/2017
*/

#include "BlackWitch.h"


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

bool BlackWitch::Attack(GameCharacter & character)
{
	//check if the character can attack

	//get equipped weapon
	Weapon* attackerWeapon{ &GetEquippedWeapon() };

	if (attackerWeapon != nullptr && GetHealth() > 20 && GetState() != CharacterState::Dead)
	{
		//can attack		

		//get defender's armour
		Armour* defenderArmour{ &character.GetEquippedArmour() };

		//get a random number between 0 and 100 to represent the chances of a successful attack
		int attackChance = GetRandomNumber(0, 100);
		int successChance = 0; //chances of the attack being successful

							   //determine the precentage of successful attack
		if (defenderArmour == nullptr)
		{
			//80% chance of successful attack if defending character has no armour
			successChance = 80;
		}
		else if (attackerWeapon->GetWeaponHitStrength() < defenderArmour->GetDefence())
		{
			//20% chance of success
			successChance = 20;
		}
		else
		{
			//60% chance of success
			successChance = 60;
		}

		//try to attack
		if (attackChance <= successChance)
		{
			//successful attack
			int atkPower = 0;

			switch (character.GetState())
			{
			case CharacterState::Defending:
				atkPower = 10;
				break;
			case CharacterState::Sleeping:
				atkPower = 100;
				break;
			case CharacterState::Dead:
				atkPower = 0;
				break;
			default:
				atkPower = 20;
				break;
			}

			//Apply damage & (BLACK WITCH) Increases attack power by 20% if dark power is at 100%
			if (darkPower_ >= 100)
				atkPower += 20;

			//do not overextend attack power
			if (atkPower > 100)
				atkPower = 100;

			float enemyHP = character.GetHealth();
			float enemyDamage = enemyHP / 100 * atkPower;
			character.SetHealth(enemyHP - enemyDamage);

			//Reduce armour hp by 10%
			if (defenderArmour != nullptr)
			{
				int enemyArmourHP = defenderArmour->GetArmourHealth();
				int armourDmg = enemyArmourHP / 100 * 10;
				defenderArmour->SetArmourHealth(enemyArmourHP - armourDmg);
			}
		}
		else
		{
			//unsuccessful attack

			//reduce weapon health by 10 or 20% if the defender has armour
			if (defenderArmour == nullptr)
			{
				int damagePrecentage = GetRandomNumber(10, 20);
				int currentWeaponHealth = attackerWeapon->GetWeaponHealth();
				int weaponDamage = currentWeaponHealth - ((currentWeaponHealth / 100) * damagePrecentage);
				attackerWeapon->SetWeaponHealth(weaponDamage);
			}
		}

		//remove weapon/armour that are at 0 hp or below
		if (attackerWeapon->GetWeaponHealth() <= 0)
		{
			//remove weapon from equipment and set character to unarmed
			RemoveWeapon(GetEquippedWeapon());
		}

		if (defenderArmour->GetArmourHealth() <= 0)
		{
			//remove armour if it's health falls to 0 or below
			RemoveArmour(character.GetEquippedArmour());
		}

		//free memory and return true
		delete attackerWeapon;
		delete defenderArmour;
		attackerWeapon = nullptr;
		defenderArmour = nullptr;
		return true;
	}
	else
	{
		//cannot attack
		//free memory and return false
		delete attackerWeapon;
		attackerWeapon = nullptr;
		return false;
	}
}

void BlackWitch::Bewitch(GameCharacter & character)
{
	//Attempt to sleep character

	//10 + (5 * proficency) = success precentage
	//Success precentage
	int successChance = 10 + (5 * magicProficiency_);

	if (successChance >= 100)
		character.Sleep(); //Bewitch will always succeed, set target character to sleep
	else
	{
		//random chance of bewitch succeeding
		int randomChance = GetRandomNumber(0, 100);

		if (randomChance <= successChance)
			character.Sleep(); //bewitch succeeds, set target character to sleep
	}



}

void BlackWitch::Sleep()
{
	//set character to sleep
	SetState(CharacterState::Sleeping);

	//Increase HP by 15%
	float baseHP = GetHealth();
	float HPIncrease = baseHP / 100 * 15;

	if (baseHP + HPIncrease < 100)
		SetHealth(baseHP + HPIncrease);
	else
		SetHealth(100);
}
