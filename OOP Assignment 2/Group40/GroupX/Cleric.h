#pragma once

/*
Cleric Class by Adam Murray
*/

#pragma once
#include "GameCharacter.h"

class Cleric : public GameCharacter
{
private:
	int pietyLevel_;

public:
	Cleric();
	Cleric(std::string name, float health, float weightLimit, int food, CharacterState state, int pietyLvl) : GameCharacter{ name, health, weightLimit, food, state }, pietyLevel_ { pietyLvl } {}
	~Cleric();

	//Setter
	void SetPietyLevel(int pietyLvl);

	//Getter
	int GetPietyLevel() const;

	//Funtions
	//void Sleep();
	bool Attack(GameCharacter & character);
	void PrayFor(GameCharacter & character);
	void Sleep();
};
