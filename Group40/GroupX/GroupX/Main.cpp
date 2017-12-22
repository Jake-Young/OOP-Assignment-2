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
	Brawler brawler{ "Jim", 100, 500, 50, CharacterState::Idle, 15, 30 };
	Cleric cleric{ "Bob", 100, 500, 50, CharacterState::Idle, 45 };
	Orc orc{ "Simon", 100, 500, 50, CharacterState::Idle, 40, 50 };
	BlackWitch witch{ "Sheela", 100, 500, 50, CharacterState::Idle, 40, 55 };

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
	//Test 1 - Cleric attacks the Brawler
	cout << "Test 1: " << endl << endl;
	brawler.Defend(0);
	cleric.EquipWeapon(0);
	cout << "Brawler's health before: " << brawler.GetHealth() << endl; //Should be 100
	cout << "Brawler's armour health before attack: " << brawler.GetArmour(0).GetArmourHealth() << endl;
	cout << "Cleric's weapon health before attack: " << cleric.GetWeapon(0).GetWeaponHealth() << endl;
	cleric.Attack(brawler);
	cout << "Brawler's health after cleric attack with \"legendaryStaff\": " << brawler.GetHealth() << endl; //Should be less than initial health
	cout << "Brawler's armour health after attack: " << brawler.GetArmour(0).GetArmourHealth() << endl; //Should be less than initial armour health
	cout << "Cleric's weapon health after attackL " << cleric.GetWeapon(0).GetWeaponHealth() << endl;
	cout << "Brawler's character state: " << brawler.GetState() << endl << endl; //Should be defending

	//Test 2 - Witch attacks the Cleric
	cout << "Test 2: " << endl << endl;
	cleric.Defend(0);
	witch.EquipWeapon(0);
	cout << "Cleric's health before: " << cleric.GetHealth() << endl; //Should be 100
	cout << "Cleric's armour health before attack: " << cleric.GetArmour(0).GetArmourHealth() << endl;
	cout << "Witch's weapon health before attack: " << witch.GetWeapon(0).GetWeaponHealth() << endl;
	witch.Attack(cleric);
	cout << "Cleric's health after witch attack with \"bow\": " << cleric.GetHealth() << endl; //Should be less than initial health
	cout << "Cleric's armour after attack: " << cleric.GetArmour(0).GetArmourHealth() << endl; //Should be less than initial armour health
	cout << "Witch's weapon health after attackL " << witch.GetWeapon(0).GetWeaponHealth() << endl;
	cout << "Cleric's character state: " << cleric.GetState() << endl << endl; //Should be defending

	//Test 3 - Orc attacks Witch
	cout << "Test 3: " << endl << endl;
	witch.Defend(0);
	orc.EquipWeapon(0);
	cout << "Witch's health before: " << witch.GetHealth() << endl; //Should be 100
	cout << "Witch's armour health before attack: " << witch.GetArmour(0).GetArmourHealth() << endl;
	cout << "Orc's weapon health before attack: " << orc.GetWeapon(0).GetWeaponHealth() << endl;
	orc.Attack(witch);
	cout << "Witch's health after orc attack with \"spear\": " << witch.GetHealth() << endl; //Should be less than initial health
	cout << "Witch's armour after attack: " << witch.GetArmour(0).GetArmourHealth() << endl; //Should be less than initial armour health
	cout << "Orc's weapon health after attackL " << orc.GetWeapon(0).GetWeaponHealth() << endl;
	cout << "Witch's character state: " << witch.GetState() << endl << endl; //Should be defending

	//Test 4 - Brawler attacks Orc with no weapon initiating brawl
	cout << "Test 4: " << endl << endl;
	orc.Defend(0);
	cout << "Orc's health before: " << orc.GetHealth() << endl; //Should be 100
	cout << "Orc's armour health before attack: " << orc.GetArmour(0).GetArmourHealth() << endl;
	brawler.Attack(orc);
	cout << "Orc's health after brawler attack with \"brawl\": " << orc.GetHealth() << endl; //Should be less than initial health
	cout << "Orc's armour after attack: " << orc.GetArmour(0).GetArmourHealth() << endl; //Should be less than initial armour health
	cout << "Orc's character state: " << orc.GetState() << endl << endl; //Should be defending

	//Test 5 - Brawler attacks Orc with weapon equipped
	cout << "Test 5: " << endl << endl;
	orc.Defend(0);
	brawler.EquipWeapon(0);
	cout << "Orc's health before: " << orc.GetHealth() << endl; //Should be 100
	cout << "Orc's armour health before attack: " << orc.GetArmour(0).GetArmourHealth() << endl;
	cout << "Brawler's weapon health before attack: " << brawler.GetWeapon(0).GetWeaponHealth() << endl;
	brawler.Attack(orc);
	cout << "Orc's health after brawler attack with \"sword\": " << orc.GetHealth() << endl; //Should be less than initial health
	cout << "Orc's armour after attack: " << orc.GetArmour(0).GetArmourHealth() << endl; //Should be less than initial armour health
	cout << "Brawler's weapon health after attack: " << brawler.GetWeapon(0).GetWeaponHealth() << endl;
	cout << "Orc's character state: " << orc.GetState() << endl << endl; //Should be defending

	//Test 6 - Cleric heals orc
	cout << "Test 6: " << endl << endl;
	cleric.PrayFor(orc);
	cout << "Orc's health after cleric heal: " << orc.GetHealth() << endl << endl; //Should be 

	//Test 7 - Witch bewitchs everyone but herself (Puts characters to sleep, character state 2) 
	cout << "Test 7: " << endl << endl;
	witch.Bewitch(cleric);
	witch.Bewitch(brawler);
	witch.Bewitch(orc);

	cout << "Cleric's character state: " << cleric.GetState() << endl << endl; //Should be defending or sleeping, 2 or 4
	cout << "Witch's character state: " << witch.GetState() << endl << endl; //Should be defending or sleeping, 2 or 4
	cout << "Orc's character state: " << orc.GetState() << endl << endl; //Should be defending or sleeping 2 or 4

	//Test 8 - Witch sleeps, healing herself
	cout << "Test 8: " << endl << endl;
	witch.Sleep();

	cout << "Witch's health after sleep: " << witch.GetHealth() << endl; 

	return 0;
}
