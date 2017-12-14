/*
Orc Class Created by Niall Devlin
Version 1.75
Updated 08/12/2017
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

bool Orc::Attack(GameCharacter & character)
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

			//Apply damage & (ORC) Increases attack power by 5% for every 10 strength
			int attackIncrease = GetStrength() / 2;
			atkPower += attackIncrease;

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
			RemoveWeapon(GetWeapon());
		}

		if (defenderArmour->GetArmourHealth() <= 0)
		{
			//remove armour if it's health falls to 0 or below
			RemoveArmour(character.GetArmour());
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

void Orc::Scream(GameCharacter & character)
{
	//20% chance of making the target character flee
	//chances of success increases by 5% for each ferocity point
	int screamSuccessChance = 20 + (ferociousness_ * 5);

	if (screamSuccessChance >= 100)
	{
		//scream will always succeed
		character.SetState(CharacterState::Running);
	}
	else
	{
		int screamSuccessRoll = GetRandomNumber(0, 100);

		if (screamSuccessRoll <= screamSuccessChance)
		{
			//successful scream
			character.SetState(CharacterState::Running);
		}
	}

}

void Orc::Sleep()
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
