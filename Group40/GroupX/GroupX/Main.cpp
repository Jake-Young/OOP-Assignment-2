/*
* Main.cpp
*
* Version information v0.1
* Authors: <Insert group member names and IDs>
* Date: 24/11/2017
* Description: Main source file for assignment two
* Copyright notice
*/

#include <iostream>
#include <random>
#include "GameCharacter.h"
#include "Brawler.h"
#include "Cleric.h"
#include "Orc.h"
#include "BlackWitch.h"

using namespace std;

int main() {

	//Test of attack functions

	//Initialise - characters
	Brawler brawler{ "Jim", 100, 100, 50, CharacterState::Idle, 15, 30 };
	Cleric cleric{ "Bob", 100, 75, 50, CharacterState::Idle, 45 };
	Orc orc{ "Simon", 100, 125, 50, CharacterState::Idle, 40, 50 };
	BlackWitch witch{ "Sheela", 100, 75, 50, CharacterState::Idle, 40, 55 };

	//Initialise - items
	Armour lightHelmet{ "Helmet of Feathers", 15, 5.0f, 20, 8, ArmourType::Leather };
	Armour heavyHelmet{ "Helmet of Stone", 25, 62.5f, 40, 10, ArmourType::Steel };
	Armour damagedChestPiece{ "Cardboard Chest", 5, 2.5f, 5, 4, ArmourType::CardBoard };
	Armour SturdyLegs{ "Wood Leg Armour", 10, 12.5f, 10, 6, ArmourType::Wood };
	Armour legendaryArms{ "Arms of the Guilded Wing", 120, 35.0f, 40, 12, ArmourType::Steel };

	Weapon spear{ "spear", 15, 25, 100, 6 };
	Weapon bow{ "bow", 15, 25, 100, 3 };
	Weapon sword{ "sword", 15, 25, 100, 5 };
	Weapon legendaryStaff{ "Merlin's Staff", 20, 15, 110, 8 };

	//Assign Items
	//Brawler
	brawler.PickUpArmour(heavyHelmet);
	brawler.PickUpArmour(legendaryArms);
	brawler.PickUpWeapon(sword);

	//Cleric
	cleric.PickUpArmour(lightHelmet);
	cleric.PickUpWeapon(legendaryStaff);

	//Orc
	orc.PickUpArmour(SturdyLegs);
	orc.PickUpWeapon(spear);

	//Witch
	witch.PickUpArmour(damagedChestPiece);
	witch.PickUpWeapon(bow);

	//Combat
	//Cleric attacks the Brawler
	brawler.Defend(0);
	cleric.EquipWeapon(0);
	cout << "Brawler's health before: " << brawler.GetHealth() << endl;
	cout << "Brawler's armour health before attack: " << brawler.GetArmour(0).GetArmourHealth() << endl;
	cleric.Attack(brawler);
	cout << "Brawler's health after cleric attack with \"legendaryStaff\": " << brawler.GetHealth() << endl;
	cout << "Brawler's armour health after attack: " << brawler.GetArmour(0).GetArmourHealth() << endl;
	cout << "Brawler's character state: " << brawler.GetState() << endl; //Should be defending

	//Witch attacks the Cleric
	cleric.Defend(0);
	witch.EquipWeapon(0);
	cout << "Cleric's health before: " << cleric.GetHealth() << endl;
	cout << "Cleric's armour health before attack: " << cleric.GetArmour(0).GetArmourHealth() << endl;
	witch.Attack(cleric);
	cout << "Cleric's health after cleric attack with \"legendaryStaff\": " << cleric.GetHealth() << endl;
	cout << "Cleric's armour after attack: " << cleric.GetArmour(0).GetArmourHealth() << endl;
	cout << "Cleric's character state: " << cleric.GetState() << endl; //Should be defending

	return 0;
}
