#pragma once

/*
Brawler Class by Adam Murray
*/

#pragma once
#include "GameCharacter.h"

class Brawler :
	public GameCharacter
{
private:
	int punchDamage_;
	int strength_;

public:
	Brawler();
	Brawler(std::string name, float health, float weightLimit, int food, CharacterState state, int punchDamage, int strength);
	~Brawler();

	//Setters 
	void SetPunchDamage(int punchdam);
	void SetStrength(int strength);

	//Getter
	int GetPunchDamage() const;
	int GetStrength() const;

	//Fuctions
	void Sleep();
	bool Attack(GameCharacter &character);
	bool Brawl(GameCharacter &character);

};