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
	if (GetHealth() > 20 && GetState() != CharacterState::Dead)
	{
		//can attack		

		//get defender's armour
		Armour* defenderArmour{ &character.GetArmour(GetEquippedArmour()) };

		//get a random number between 0 and 100 to represent the chances of a successful attack
		int attackChance = GetRandomNumber(0, 100);
		int successChance = 0; //chances of the attack being successful

							   //determine the precentage of successful attack
		if (defenderArmour == nullptr)
		{
			//80% chance of successful attack if defending character has no armour
			successChance = 80;
		}
		else if (punchDamage_ < defenderArmour->GetDefence())
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
				atkPower = 20 / 2;
				break;
			}

			//Apply damage & Increases attack power by 5% for every 10 strength
			int attackIncrease = GetStrength() / 2;
			atkPower += attackIncrease;


			//Reduce armour hp by 10%
			if (defenderArmour != nullptr)
			{
				int enemyArmourHP = defenderArmour->GetArmourHealth();
				int armourDmg = enemyArmourHP / 100 * 10;
				defenderArmour->SetArmourHealth(enemyArmourHP - armourDmg);
			}
		}




		return true;
	}



	//Armour* defenderArmour{ &character.GetEquippedArmour() };
	//return true;
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