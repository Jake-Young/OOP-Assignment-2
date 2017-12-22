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
	int weaponIndex = this->GetEquippedWeapon();

	//set calling character state to idle
	this->SetState(CharacterState::Idle);

	if (weaponIndex >= 0 && this->GetHealth() > 20 && character.GetState() != CharacterState::Dead)
	{
		//can attack

		//Get attacker weapon and defender armour
		Weapon* attackerWeapon{ &this->GetWeapon(weaponIndex) };
		int defArmourIndex = character.GetEquippedArmour();
		Armour* defenderArmour{ &character.GetArmour(defArmourIndex) };

		//chances of successful hit
		int successfulHitChance = 0;
		int weaponHitStr = attackerWeapon->GetWeaponHitStrength();
		int armourDefence = defenderArmour->GetDefence();

		if (defArmourIndex < 0)
		{
			successfulHitChance = 80;
		}
		else if (weaponHitStr < armourDefence)
		{
			successfulHitChance = 20;
		}
		else
		{
			successfulHitChance = 60;
		}

		//is the attack a success?
		int rng = this->GetRandomNumber(1, 100);

		if (successfulHitChance <= rng)
		{
			//successful attack
			float attackPower = 0.0f;

			//get defending character state
			CharacterState defenderState = character.GetState();
			switch (defenderState)
			{
			case CharacterState::Defending:
				attackPower += 10.0f;
				break;
			case CharacterState::Sleeping:
				attackPower += 100.0f;
				break;
			case CharacterState::Dead:
				attackPower = 0.0f;
				break;
			default:
				attackPower += 20.0f;
				break;
			}

			//Apply damage & (ORC) Increases attack power by 5% for every 10 strength
			float attackIncrease = this->GetStrength() / 2;
			attackPower += attackIncrease;

			//do not overextend attack power
			if (attackPower > 100.0f)
				attackPower = 100.0f;

			float defenderHealth = character.GetHealth();
			float damageToApply = defenderHealth - ((defenderHealth / 100) * attackPower);
			character.SetHealth(damageToApply);

			//reduce defender armour by 10% and remove it if it falls to or below 0
			if (defArmourIndex >= 0)
			{
				int defArmourHealth = defenderArmour->GetArmourHealth();
				int defArmourDamage = defArmourHealth - ((defArmourHealth / 100) * 10);
				defenderArmour->SetArmourHealth(defArmourDamage);

				if (defenderArmour->GetArmourHealth() <= 0)
				{
					character.RemoveArmour(defArmourIndex);
					defenderArmour->~Armour();
				}
			}

			//return true
			return true;
		}
		else
		{
			//unsuccessful attack

			//reduce weapon health by 10 to 20% if the defender has armour
			if (defArmourIndex >= 0)
			{
				int weaponHealthReduce = this->GetRandomNumber(10, 20);
				int weaponHealth = attackerWeapon->GetWeaponHealth();
				int newWeaponHealth = weaponHealth - ((weaponHealth / 100) * weaponHealthReduce);
				attackerWeapon->SetWeaponHealth(newWeaponHealth);

				//remove weapon if health is below 0
				if (attackerWeapon->GetWeaponHealth() <= 0)
				{
					this->RemoveWeapon(weaponIndex);
					attackerWeapon->~Weapon();
				}
			}

			//return false
			return false;
		}
	}
	else
	{
		//cannot attack
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
