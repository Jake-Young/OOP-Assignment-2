/*
Cleric Class by Adam Murray
*/

#include "Cleric.h"
#include <random>

Cleric::Cleric()
{

}

Cleric::~Cleric()
{

}

void Cleric::SetPietyLevel(int pietyLvl)
{
	pietyLevel_ = pietyLvl;
}

int Cleric::GetPietyLevel() const
{
	return pietyLevel_;
}

bool Cleric::Attack(GameCharacter &character)
{
	bool hitChance = true;
	bool hitCharacter = true;
	Weapon a = this->GetEquippedWeapon();

	if (this->GetEquippedWeapon() == -1 || this->GetHealth() <= 20 || character.GetState() == CharacterState::Dead) {
		hitChance = false;
		return false;
	}

	if (hitChance = true) {
		std::random_device randomnum;
		std::mt19937 gen(randomnum());
		std::uniform_real_distribution<> dis(1, 100);
		int result = dis(gen);
		int chancetohit;
		Armour b;
		bool wearingArmour = true;
		int index = character.GetEquippedArmour();
		if (character.GetEquippedArmour() > -1) {
			Armour b = character.GetArmour(index);
		}

		if (character.GetEquippedArmour() == -1) {
			chancetohit = 80;
		}
		else if (a.GetWeaponHitStrength() < b.GetDefence()) {
			chancetohit = 20;
		}
		else if (a.GetWeaponHitStrength() > b.GetDefence()) {
			chancetohit = 60;
		}

		if (result <= chancetohit) {
			float newCharacterHealth;
			int newArmourHealth;

			switch (character.GetState()) {
			case CharacterState::Defending:
				newCharacterHealth = character.GetHealth() - (10);
				character.SetHealth(newCharacterHealth); break;
			case CharacterState::Sleeping:
				newCharacterHealth = character.GetHealth() - (100);
				character.SetHealth(newCharacterHealth); break;
			case CharacterState::Dead: break;
			default:
				newCharacterHealth = character.GetHealth() - (20);
				character.SetHealth(newCharacterHealth); break;
			}
			if (character.GetEquippedArmour() > -1) {
				newArmourHealth = b.GetArmourHealth() - 10;
				b.SetArmourHealth(newArmourHealth);
			}
			if (b.GetArmourHealth() <= 0 && character.GetEquippedArmour() > -1) {
				b.~Armour();
			}
		}
		else {
			hitCharacter = false;
			if (wearingArmour = true) {
				std::random_device randomnum2;
				std::mt19937 gen(randomnum());
				std::uniform_real_distribution<> dis(10, 20);
				int result = dis(gen);
				int newweaponhealth = a.GetWeaponHealth() - result;
				a.SetWeaponHealth(newweaponhealth);
				if (a.GetWeaponHealth() <= 0) {
					a.~Weapon();
				}
			}
		}
	}

	return hitCharacter;
}


void Cleric::PrayFor(GameCharacter &character)
{
	int chance = (rand() % 100);

	if (chance >= 50)
	{
		SetHealth(GetHealth() + 5 * pietyLevel_);
	}
}


void Cleric::Sleep()
{
	//set character to sleep
	SetState(CharacterState::Sleeping);
	//Increase HP by 20%
	float baseHP = GetHealth();
	float HPIncrease = baseHP / 100 * 20;

	if (baseHP + HPIncrease < 100)
	{
		SetHealth(baseHP + HPIncrease);
	}
	else {
		SetHealth(100);
	}
}