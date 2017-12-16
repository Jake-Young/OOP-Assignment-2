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
	Cleric(int pietyLvl) : pietyLevel_{ pietyLvl } {}
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
