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

	//get equipped weapon
	Weapon* equippedWeapon{ &GetEquippedWeapon() };

	if (equippedWeapon != nullptr && GetHealth() > 20 && GetState() != CharacterState::Dead)
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
		else if (equippedWeapon->GetWeaponHitStrength() < defenderArmour->GetDefence())
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

			//Apply damage & Increases attack power by 5% for every 10 strength
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
				int currentWeaponHealth = equippedWeapon->GetWeaponHealth();
				int weaponDamage = currentWeaponHealth - ((currentWeaponHealth / 100) * damagePrecentage);
				equippedWeapon->SetWeaponHealth(weaponDamage);
			}
		}

		//free memory and return true
		delete equippedWeapon;
		delete defenderArmour;
		equippedWeapon = nullptr;
		defenderArmour = nullptr;
		return true;
	}
	else
	{
		//no weapon
		//Brawl instead
		Brawl(character);
	}
}

bool Brawler::Brawl(GameCharacter &character)
{
	if (GetHealth() > 20 && GetState() != CharacterState::Dead)
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