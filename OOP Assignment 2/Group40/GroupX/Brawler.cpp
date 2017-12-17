/*
Brawler Class by Adam Murray
*/


#include "Brawler.h"

Brawler::Brawler()
{

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
	return true; //temporary return
}


void Brawler::Sleep()
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