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