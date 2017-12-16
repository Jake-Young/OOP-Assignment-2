/*
Cleric Class by Adam Murray
*/
#include "Cleric.h"

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

bool Cleric::Attack(GameCharacter &character) {
	return true; //temp value
}

void Cleric::PrayFor(GameCharacter & character)
{
}

void Cleric::Sleep()
{
	//set character to sleep

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