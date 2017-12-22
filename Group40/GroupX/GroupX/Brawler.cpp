/*
Brawler Class by Adam Murray
*/


#include "Brawler.h"
#include <random>

Brawler::Brawler()
{

}

Brawler::Brawler(std::string name, float health, float weightLimit, int food, CharacterState state, int punchDamage, int strength) :
	GameCharacter{ name, health, weightLimit, food, state }, punchDamage_{ punchDamage }, strength_{ strength } {

}

Brawler::~Brawler()
{

}

void Brawler::SetPunchDamage(int punchDam)
{
	punchDamage_ = punchDam;
}

void Brawler::SetStrength(int strength)
{
	strength_ = strength;
}

int Brawler::GetPunchDamage() const
{
	return punchDamage_;
}

int Brawler::GetStrength() const
{
	return strength_;
}

bool Brawler::Attack(GameCharacter &character)
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
		int armourDefence = defArmourIndex >= 0 ? defenderArmour->GetDefence() : 0;

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

		if (successfulHitChance >= rng)
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

			//Apply damage & (BRAWLER) Increases attack power by 5% for every 10 strength
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
				character.GetArmour(defArmourIndex).SetArmourHealth(defArmourDamage);
				//defenderArmour->SetArmourHealth(defArmourDamage);

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
				this->GetWeapon(weaponIndex).SetWeaponHealth(newWeaponHealth);
				//attackerWeapon->SetWeaponHealth(newWeaponHealth);

				//remove weapon if health is below 0
				if (attackerWeapon->GetWeaponHealth() <= 0)
				{
					this->RemoveWeapon(weaponIndex);
					attackerWeapon->~Weapon();
				}
			}

			//return false
			attackerWeapon = nullptr;
			defenderArmour = nullptr;
			return false;
		}
	}
	else if (weaponIndex < 0)
	{
		//no wepaon, brawl insteaad
		return Brawl(character);
	}
	else
	{
		//cannot attack
		return false;
	}
}

bool Brawler::Brawl(GameCharacter &character)
{
	//Get defender armour
	int defArmourIndex = character.GetEquippedArmour();
	Armour* defenderArmour{ &character.GetArmour(defArmourIndex) };

	//chances of successful hit
	int successfulHitChance = 0;
	int armourDefence = defArmourIndex >= 0 ? defenderArmour->GetDefence() : 0;

	if (defArmourIndex < 0)
	{
		successfulHitChance = 80;
	}
	else if (this->GetPunchDamage() < armourDefence)
	{
		successfulHitChance = 20;
	}
	else
	{
		successfulHitChance = 60;
	}

	//is the attack a success?
	int rng = this->GetRandomNumber(1, 100);

	if (successfulHitChance >= rng)
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

		//Apply damage & (BRAWLER) Increases attack power by 5% for every 10 strength
		float attackIncrease = this->GetStrength() / 2;
		attackPower += attackIncrease;

		//do not overextend attack power
		if (attackPower > 100.0f)
			attackPower = 100.0f;

		float defenderHealth = character.GetHealth();
		float damageToApply = defenderHealth - (((defenderHealth / 100) * attackPower) / 2); //Brawling, so half damage
		character.SetHealth(damageToApply);

		//reduce defender armour by 10% and remove it if it falls to or below 0
		if (defArmourIndex >= 0)
		{
			int defArmourHealth = defenderArmour->GetArmourHealth();
			int defArmourDamage = defArmourHealth - ((defArmourHealth / 100) * 10);
			character.GetArmour(defArmourIndex).SetArmourHealth(defArmourDamage);
			//defenderArmour->SetArmourHealth(defArmourDamage);

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
		//unsuccessful attack, return false
		return false;
	}
}

void Brawler::Sleep()
{
	//set character to sleep
	SetState(CharacterState::Sleeping);
	//Increase HP by 20%
	float baseHP = GetHealth();
	float HPIncrease = baseHP / 100 * 20;

	if (baseHP + HPIncrease < 100) {
		SetHealth(baseHP + HPIncrease);
	}
	else {
		SetHealth(100);
	}
}