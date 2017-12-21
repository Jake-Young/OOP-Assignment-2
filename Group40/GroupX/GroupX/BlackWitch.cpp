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

bool BlackWitch::Attack(GameCharacter &character)
{
	//check if the character can attack
	int weaponIndex = this->GetEquippedWeapon();
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

			//Apply damage & (BLACK WITCH) Increases attack power by 20% if dark power is at 100%
			if (this->GetDarkPower() >= 100)
				attackPower += 20.0f;

			//do not overextend attack power
			if (attackPower > 100.0f)
				attackPower = 100.0f;

			float defenderHealth = character.GetHealth();
			float damageToApply = defenderHealth - ((defenderHealth / 100) * attackPower);
			character.SetHealth(damageToApply);

			//reduce defender armour by 10% and remove it if it falls to or below 0
			int defArmourHealth = defenderArmour->GetArmourHealth();
			int defArmourDamage = defArmourHealth - ((defArmourHealth / 100) * 10);
			defenderArmour->SetArmourHealth(defArmourDamage);

			if (defenderArmour->GetArmourHealth() <= 0)
			{
				character.RemoveArmour(defArmourIndex);
				defenderArmour->~Armour();
			}

			//free memory and return true
			//delete attackerWeapon;
			//delete defenderArmour;
			attackerWeapon = nullptr;
			defenderArmour = nullptr;
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

			//free memory and return false
			//delete attackerWeapon;
			//delete defenderArmour;
			attackerWeapon = nullptr;
			defenderArmour = nullptr;
			return false;
		}
	}
	else
	{
		//cannot attack
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
