#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(CharacterManagement)
	{
		public:
			TEST_METHOD(TestBrawlerConstructor)
			{
				//Arrange the data			
				Brawler brawler{ "Jim", 100, 120, 50, CharacterState::Idle, 60, 80 };
				std::string expectedName{ brawler.GetName() };
				float expectedHP = 100;
				float expectedWeight = 120;
				int expectedFood = 50;
				int expectedPunchDamage = 60;
				int expectedStrength = 80;

				//Act
				std::string characterName = brawler.GetName();
				float actualHP = brawler.GetHealth();
				float actualWeight = brawler.GetWeightLimit();
				int actualFood = brawler.GetFood();
				int actualPunchDamage = brawler.GetPunchDamage();
				int actualStrength = brawler.GetStrength();
				int actualState = brawler.GetState();
				int actualWeapon = brawler.GetEquippedWeapon();
				int actualArmour = brawler.GetEquippedArmour();

				//Assert
				Assert::AreEqual(expectedName, characterName);
				Assert::AreEqual(expectedHP, actualHP);
				Assert::AreEqual(expectedWeight, actualWeight);
				Assert::AreEqual(expectedFood, actualFood);
				Assert::AreEqual(expectedPunchDamage, actualPunchDamage);
				Assert::AreEqual(expectedStrength, actualStrength);
				Assert::AreEqual(actualState, actualState);
				Assert::AreEqual(actualWeapon, -1);
				Assert::AreEqual(actualArmour, -1);
			}

			TEST_METHOD(TestBlackWitchConstructor)
			{
				//Arrange
				BlackWitch witch{ "Sarah", 100, 100, 0, CharacterState::Idle, 0, 0 };
				std::string expectedName{ witch.GetName() };
				float expectedHP = 100;
				float expectedWeight = 100;
				int expectedFood = 0;
				int expectedMagicProf = 0;
				int expectedDarkPower = 0;

				//Act
				std::string characterName = witch.GetName();
				float actualHP = witch.GetHealth();
				float actualWeight = witch.GetWeightLimit();
				int actualFood = witch.GetFood();
				int actualMagicProf = witch.GetMagicProficiency();
				int actualDarkPower = witch.GetDarkPower();
				int actualState = witch.GetState();
				int actualWeapon = witch.GetEquippedWeapon();
				int actualArmour = witch.GetEquippedArmour();

				//Assert
				Assert::AreEqual(expectedName, characterName);
				Assert::AreEqual(expectedHP, actualHP);
				Assert::AreEqual(expectedWeight, actualWeight);
				Assert::AreEqual(expectedFood, actualFood);
				Assert::AreEqual(expectedMagicProf, actualMagicProf);
				Assert::AreEqual(expectedDarkPower, actualDarkPower);
				Assert::AreEqual(actualState, actualState);
				Assert::AreEqual(actualWeapon, -1);
				Assert::AreEqual(actualArmour, -1);
			}

			TEST_METHOD(TestClericConstructor)
			{
				//Arrange 
				Cleric cleric{ "Joe", 100, 70, 50, CharacterState::Idle, 80 };
				//std::string expectedName{ cleric.GetName() };
				float expectedHP = 100;
				float expectedWeight = 70;
				int expectedFood = 50;
				int expectedPietyLevel = 80;

				//Act
				//std::string actualName = cleric.GetName();
				float actualHP = cleric.GetHealth();
				float actualWeight = cleric.GetWeightLimit();
				int actualFood = cleric.GetFood();
				int actualPietyLevel = cleric.GetPietyLevel();
				int actualState = cleric.GetState();
				int actualWeapon = cleric.GetEquippedWeapon();
				int actualArmour = cleric.GetEquippedArmour();

				//Assert
				//Assert::AreEqual(expectedName, actualName);
				Assert::AreEqual(expectedHP, actualHP);
				Assert::AreEqual(expectedWeight, actualWeight);
				Assert::AreEqual(expectedFood, actualFood);
				Assert::AreEqual(expectedPietyLevel, actualPietyLevel);
				Assert::AreEqual(actualState, actualState);
				Assert::AreEqual(actualWeapon, -1);
				Assert::AreEqual(actualArmour, -1);
			}

			TEST_METHOD(TestOrcConstructor)
			{
				//Arrange 
				Orc orc{ "Bob", 100, 150, 50, CharacterState::Idle, 100, 70 };
				std::string expectedName{ orc.GetName() };
				float expectedHP = 100;
				float expectedWeight = 150;
				int expectedFood = 50;
				int expectedFerocity = 100;
				int expectedStrength = 70;

				//Act
				std::string actualName = orc.GetName();
				float actualHP = orc.GetHealth();
				float actualWeight = orc.GetWeightLimit();
				int actualFood = orc.GetFood();
				int actualFerocity = orc.GetFerocity();
				int actualStrength = orc.GetStrength();
				int actualState = orc.GetState(); 
				int actualWeapon = orc.GetEquippedWeapon();
				int actualArmour = orc.GetEquippedArmour();

				//Assert
				Assert::AreEqual(expectedName, actualName);
				Assert::AreEqual(expectedHP, actualHP);
				Assert::AreEqual(expectedWeight, actualWeight);
				Assert::AreEqual(expectedFood, actualFood);
				Assert::AreEqual(expectedFerocity, actualFerocity);
				Assert::AreEqual(expectedStrength, actualStrength);
				Assert::AreEqual(actualState, actualState);
				Assert::AreEqual(actualWeapon, -1);
				Assert::AreEqual(actualArmour, -1);

			}

			TEST_METHOD(TestWeaponConstructor)
			{
				//Arrange
				Weapon sword{ "Sword", 50, 12.5f, 25, 100 };
				std::string expectedName{ "Sword" };
				int expectedValue{ 50 };
				float expectedWeight{ 12.5f };
				int expectedHitStrength{ 25 };
				int expectedHealth{ 100 };

				//Act
				std::string actualName{ sword.GetItemName() };
				int actualValue{ sword.GetValue() };
				float actualWeight{ sword.GetWeight() };
				int actualHitStrength{ sword.GetWeaponHitStrength() };
				int actualHealth{ sword.GetWeaponHealth() };

				//Assert
				Assert::AreEqual(expectedName, actualName);
				Assert::AreEqual(expectedValue, actualValue);
				Assert::AreEqual(expectedWeight, actualWeight);
				Assert::AreEqual(expectedHitStrength, actualHitStrength);
				Assert::AreEqual(expectedHealth, actualHealth);

			}

			TEST_METHOD(TestArmourConstructor)
			{
				//Arrange
				Armour helmet{ "Helmet", 75, 30.0f, 15, 100, ArmourType::Iron };
				std::string expectedName{ "Helmet" };
				int expectedValue{ 75 };
				float expectedWeight{ 30.0f };
				int expectedDefense{ 15 };
				int expectedHealth{ 100 };
				int expectedArmourType{ ArmourType::Iron };

				//Act
				std::string actualName{ helmet.GetItemName() };
				int actualValue{ helmet.GetValue() };
				float actualWeight{ helmet.GetWeight() };
				int actualDefense{ helmet.GetDefence() };
				int actualHealth{ helmet.GetArmourHealth() };
				int actualArmourType{ helmet.GetArmourType() };

				//Assert
				Assert::AreEqual(expectedName, actualName);
				Assert::AreEqual(expectedValue, actualValue);
				Assert::AreEqual(expectedWeight, actualWeight);
				Assert::AreEqual(expectedDefense, actualDefense);
				Assert::AreEqual(expectedHealth, actualHealth);
				Assert::AreEqual(expectedArmourType, actualArmourType);
			}

			TEST_METHOD(TestEatConsumesFood)
			{
				//Tests that food gets consumed by eat function
				//Arrange the data
				int expectedFood{ 16 }, actualFood;
				Brawler brawler{ "Jim", 100, 120, 20, CharacterState::Idle, 60, 80 };

				//Act
				brawler.Eat();
				actualFood = brawler.GetFood();

				//Assert
				Assert::AreEqual(expectedFood, actualFood);
			}

			TEST_METHOD(TestEatIncreasesHealth)
			{

				//	Consumes 20% of the available food. Each unit (1) of food consumed will add 0.25 units of health to the character.
				//Tests that health increases correctly by eat function 
				//Arrange the data
				float expectedHealth{ 52.5f }, actualHealth; //(health should not exceed 100)
				Brawler brawler{ "Jim", 50, 120, 50, CharacterState::Idle, 60, 80 };

				//Act
				brawler.Eat();
				actualHealth = brawler.GetHealth();

				//Assert
				Assert::AreEqual(expectedHealth, actualHealth);
			}

			TEST_METHOD(TestHealthCapped)
			{
				//Tests that health does not exceed 100 by eat function 
				//Arrange the data
				float expectedHealth{ 100.0f }, actualHealth; //(health should not exceed 100)
				Brawler brawler{ "Jim", 100, 120, 50, CharacterState::Idle, 60, 80 };

				//Act
				brawler.Eat();
				actualHealth = brawler.GetHealth();

				//Assert
				Assert::AreEqual(expectedHealth, actualHealth);
			}

			TEST_METHOD(TestSleepHealth100)
			{
				//Test Sleep function when character health is already 100
				//Arrange
				float expectedHealth = 100;
				Brawler brawler{ "Jim", 100, 120, 50, CharacterState::Idle, 60, 80 };

				//Act
				brawler.Sleep();
				float actualHealth = brawler.GetHealth();

				//Assert
				Assert::AreEqual(expectedHealth, actualHealth);

			}

			TEST_METHOD(TestSleepHealthLessThan100)
			{
				//Test Sleep function when character health is below 100
				//Arrange 
				float expectedHealth = 78; //Might be 74, depends on how it is rounded. Actual number given is 74.75 //WRONG
				Brawler brawler{ "Jim", 65, 120, 50, CharacterState::Idle, 60, 80 };

				//Act
				brawler.Sleep();
				float actualHealth = brawler.GetHealth();

				//Assert
				Assert::AreEqual(expectedHealth, actualHealth);

			}
	};
}

namespace Conflict_UnitTests
{
	TEST_CLASS(Conflict)
	{
		public:
			TEST_METHOD(Defend1)
			{
				//Test that the character enters defending state
				//Arrange the data
				int expectedState{ 4 };
				Brawler brawler{ "Jim", 100, 120, 50, CharacterState::Idle, 60, 80 };

				//Act
				brawler.Defend(1); //invalid index! no armour in vector
				int actualState = brawler.GetState();

				//Assert
				Assert::AreEqual(expectedState, actualState);
			}

			TEST_METHOD(Defend2)
			{
				//Test that the character selected armour remains -1 
				//Arrange the data
				int expectedIndex{ -1 }, actualIndex;
				Brawler brawler{ "Jim", 100, 120, 50, CharacterState::Idle, 60, 80 };

				//Act
				brawler.Defend(0); //invalid index! no armour in vector
				actualIndex = brawler.GetEquippedArmour();

				//Assert
				Assert::AreEqual(expectedIndex, actualIndex);
			}

			TEST_METHOD(Defend3)
			{
				//Test that the character can defend using sleected armour
				//Arrange
				int expectedState{ 4 }, actualState;
				BlackWitch witch{ "Sarah", 100, 100, 0, CharacterState::Idle, 0, 0 };

				//Act
				witch.Defend(0);
				actualState = witch.GetState();

				//Assert
				Assert::AreEqual(expectedState, actualState);
			}

			TEST_METHOD(Defend4)
			{
				//Test that the character selected armour remains -1 
				//Arrange the data
				int expectedIndex{ -1 }, actualIndex;
				BlackWitch witch{ "Sarah", 100, 100, 0, CharacterState::Idle, 0, 0 };

				//Act
				witch.Defend(0); //invalid index! no armour in vector
				actualIndex = witch.GetEquippedArmour();

				//Assert
				Assert::AreEqual(expectedIndex, actualIndex);
			}

			TEST_METHOD(TestBewitch)
			{
				//Test the bewitch function for Black Witch
				//Arrange
				BlackWitch witch{ "Sarah", 100, 100, 0, CharacterState::Idle, 100, 100 }; //100 Magic Prof. for 100% success chance of bewitch succeeding
				Orc enemy{ "Baak", 100, 100, 0, CharacterState::Idle, 0, 10 };
				int expectedState = CharacterState::Sleeping;

				//Act
				witch.Bewitch(enemy);
				int actualState = enemy.GetState();

				//Assert
				Assert::AreEqual(expectedState, actualState);
			}

			//Test Orc scream
			TEST_METHOD(TestScream)
			{
				//Act 
				Orc orc{ "Bob", 100, 150, 50, CharacterState::Idle, 100, 70 }; //100 ferociousness, similar to bewitch test. 100% success rate.
				BlackWitch enemy{ "Sarah", 100, 100, 0, CharacterState::Idle, 10, 10 };
				int expectedState = CharacterState::Running;

				//Arrange
				orc.Scream(enemy);
				int actualState = enemy.GetState();

				//Assert
				Assert::AreEqual(expectedState, actualState);

			}

	};
}

namespace Inventory_UnitTests 
{
	TEST_CLASS(InventoryMangement)
	{
		public:
			TEST_METHOD(TestAddItemWeight)
			{
				//Test that adding items above weight limit fails
				//Arrange the data
				bool addItemResult;
				//No point initialising vectors as character should start off with no items.
				Brawler brawler{ "Jim", 100, 10, 0, CharacterState::Idle, 60, 80 };
				Weapon spear{ "spear", 15, 25, 100, 6 };
				Armour glove{ "Leather glove", 3, 0.25f, 1, 100, ArmourType::Leather };
				Armour chainMail{ "Chain Mail", 45, 85, 200, 100, ArmourType::Steel };


				//Act
				addItemResult = brawler.PickUpWeapon(spear);
				addItemResult = brawler.PickUpArmour(glove);
				addItemResult = brawler.PickUpArmour(chainMail);

				//Assert - add weapon should be false as the weight exceeds the limit
				Assert::IsFalse(addItemResult);
			}

			TEST_METHOD(TestAddWeaponWeight)
			{
				//Test that adding items above weight limit fails
				//Arrange the data
				bool addWeaponResult;
				//No point initialising vectors as character should start off with no items.
				Brawler brawler{ "Jim", 100, 10, 0, CharacterState::Idle, 60, 80 };
				Weapon spear{ "spear", 15, 25, 100, 6 };
				Weapon bow{ "bow", 15, 25, 100, 6 };


				//Act
				addWeaponResult = brawler.PickUpWeapon(spear);
				addWeaponResult = brawler.PickUpWeapon(bow);

				//Assert - add weapon should be false as the weight exceeds
				Assert::IsFalse(addWeaponResult);
			}

			TEST_METHOD(TestAddArmourWeight)
			{
				//Test that adding items above weight limit fails
				//Arrange the data
				bool addArmourResult;
				//No point initialising vectors as character should start off with no items.
				Brawler brawler{ "Jim", 100, 40, 0, CharacterState::Idle, 60, 80 };
				Armour shield{ "Shield", 40, 40, 50, 100, ArmourType::Leather };
				Armour hat{ "Tinfoil Hat", 2, 0.5, 1, 100, ArmourType::CardBoard };

				//Act
				addArmourResult = brawler.PickUpArmour(shield);
				addArmourResult = brawler.PickUpArmour(hat);

				//Assert - add weapon should be false as the weight exceeds
				Assert::IsFalse(addArmourResult);
			}

			TEST_METHOD(TestAddWeapons)
			{
				//Arrange the data
				Brawler brawler{ "Jim", 100, 120, 0, CharacterState::Idle, 60, 80 };
				Weapon spear{ "spear", 15, 25, 100, 6 };
				Weapon bow{ "bow", 15, 25, 100, 3 };
				Weapon spear2{ "Lance of Longinus", 10, 2, 70, 2 };
				Weapon arrow{ "arrow", 15, 25, 100, 6 };

				brawler.PickUpWeapon(spear);
				brawler.PickUpWeapon(bow);
				brawler.PickUpWeapon(spear2);
				brawler.PickUpWeapon(arrow);
				brawler.PickUpWeapon(arrow);
				brawler.PickUpWeapon(arrow);
				brawler.PickUpWeapon(arrow);

				std::string expectedWeaponName{ "Lance of Longinus" };

				//Act
				Weapon tempWeapon = brawler.GetWeapon(2);
				std::string weaponName = tempWeapon.GetItemName();

				//Assert
				Assert::AreEqual(expectedWeaponName, weaponName);
			}

			TEST_METHOD(TestAddArmour)
			{
				//Arrange
				Brawler brawler{ "Mike", 100, 120, 0, CharacterState::Idle, 60, 80 };
				Armour plate{ "Iron Plate", 10, 5, 50, 50, ArmourType::Iron };
				Armour box{ "Cardboard Box", 2, 2, 5, 10, ArmourType::CardBoard };

				brawler.PickUpArmour(plate);
				brawler.PickUpArmour(box);

				//Act
				std::string expectedArmourName = "Iron Plate";
				Armour tempArmour = brawler.GetArmour(0);
				std::string actualArmourName = tempArmour.GetItemName();

				//Assert
				Assert::AreEqual(expectedArmourName, actualArmourName);
			}

			TEST_METHOD(TestDropWeapon)
			{
				//Test Drop weapon
				//Arrange the data
				std::string expectedWeaponName{ "spear" };
				Brawler brawler{ "Jim", 100, 120, 0, CharacterState::Idle, 60, 80 };
				Weapon spear1{ "spear", 15, 25, 100, 6 };
				Weapon bow{ "bow", 15, 25, 100, 3 };
				Weapon spear2{ "spear", 10, 2, 70, 2 };

				brawler.PickUpWeapon(spear1);
				brawler.PickUpWeapon(bow);
				brawler.PickUpWeapon(spear2);

				//Act

				brawler.DropWeapon(spear2); //Weapon spear2 should be removed not spear2 - same name different attributes!

				Weapon tempWeapon = brawler.GetWeapon(0);
				std::string actualWeaponName = tempWeapon.GetItemName();

				//Assert
				Assert::AreEqual(expectedWeaponName, actualWeaponName);
			}

			TEST_METHOD(TestDropArmour)
			{
				//Test Drop weapon
				//Arrange the data
				std::string expectedArmourName{ "Cardboard suit of armour" };
				Brawler brawler{ "Jim", 100, 120, 0, CharacterState::Idle, 60, 80 };
				Armour shield{ "Shield", 40, 40, 50, 100, ArmourType::Leather };
				Armour hat{ "Tinfoil Hat", 2, 0.5f, 1, 100, ArmourType::CardBoard };
				Armour glove1{ "Leather glove", 1, 0.23f, 1, 100, ArmourType::Leather };
				Armour suit{ "Cardboard suit of armour", 10, 2.0f, 15, 100, ArmourType::CardBoard };
				Armour glove2{ "Leather glove", 1, 0.2f, 1, 75, ArmourType::Leather };

				brawler.PickUpArmour(shield);
				brawler.PickUpArmour(hat);
				brawler.PickUpArmour(glove1);
				brawler.PickUpArmour(suit);
				brawler.PickUpArmour(glove2);

				//Act
				brawler.DropArmour(glove1); //Weapon spear2 should be removed not spear2 - same name different attributes!

				Armour tempArmour = brawler.GetArmour(2);
				std::string actualArmourName = tempArmour.GetItemName();

				//Assert
				Assert::AreEqual(expectedArmourName, actualArmourName);

			}

			TEST_METHOD(TestRemoveWeapon)
			{
				//Arrange the data
				Brawler brawler{ "Jim", 100, 120, 0, CharacterState::Idle, 60, 80 };
				Weapon spear{ "spear", 15, 25, 100, 6 };
				Weapon bow{ "bow", 15, 25, 100, 3 };
				Weapon spear2{ "Lance of Longinus", 10, 2, 70, 2 };
				Weapon arrow{ "arrow", 15, 25, 100, 6 };

				brawler.PickUpWeapon(spear);
				brawler.PickUpWeapon(bow);
				brawler.PickUpWeapon(spear2);
				brawler.PickUpWeapon(arrow);
				brawler.PickUpWeapon(arrow);
				brawler.PickUpWeapon(arrow);
				brawler.PickUpWeapon(arrow);

				std::string unexpectedWeaponName{ "Lance of Longinus" };

				//Act
				brawler.RemoveWeapon(2);
				Weapon tempWeapon = brawler.GetWeapon(2);
				std::string weaponName = tempWeapon.GetItemName();

				//Assert
				Assert::AreNotEqual(unexpectedWeaponName, weaponName);
			}

			TEST_METHOD(TestRemoveArmour)
			{
				//Arrange
				Brawler brawler{ "Mike", 100, 120, 0, CharacterState::Idle, 60, 80 };
				Armour plate{ "Iron Plate", 10, 5, 50, 50, ArmourType::Iron };
				Armour box{ "Cardboard Box", 2, 2, 5, 10, ArmourType::CardBoard };

				brawler.PickUpArmour(plate);
				brawler.PickUpArmour(box);

				//Act
				brawler.RemoveArmour(0);
				std::string unexpectedArmourName = "Iron Plate";
				Armour tempArmour = brawler.GetArmour(0);
				std::string actualArmourName = tempArmour.GetItemName();

				//Assert
				Assert::AreNotEqual(unexpectedArmourName, actualArmourName);
			}

			TEST_METHOD(TestEquipWeapon)
			{
				//Act 
				Brawler brawler{ "Brian", 50, 75, 55, CharacterState::Idle, 75, 90 };
				Weapon sword{ "sword", 100, 25.0f, 50, 100 };
				Weapon spear{ "spear", 100, 20.0f, 25, 100 };
				Weapon bow{ "bow", 100, 10.0f, 12, 100 };
				int expectedWeapon = 2;

				//Arrange
				brawler.PickUpWeapon(sword);
				brawler.PickUpWeapon(spear);
				brawler.PickUpWeapon(bow);
				
				brawler.EquipWeapon(1);
				int actualWeapon = brawler.GetEquippedWeapon();
				brawler.EquipWeapon(0);
				actualWeapon = brawler.GetEquippedWeapon();
				brawler.EquipWeapon(2);
				actualWeapon = brawler.GetEquippedWeapon();

				//Assert
				Assert::AreEqual(expectedWeapon, actualWeapon);
			}

			TEST_METHOD(TestAddFood) 
			{
				//Arrange
				Brawler brawler{ "Mike", 100, 120, 5, CharacterState::Idle, 60, 80 };
				brawler.AddFood(1);

				//Act
				int expectedFoodAmount = 6;
				int actualFood = brawler.GetFood();

				//Assert
				Assert::AreEqual(expectedFoodAmount, actualFood);
			}

			TEST_METHOD(TestRun)
			{
				//Arrange
				Brawler brawler{ "BigJim", 100, 120, 50, CharacterState::Idle, 60, 80 };
				int expectedState{ 1 };

				//Act
				brawler.Run();
				int actualState = brawler.GetState();

				//Assert
				Assert::AreEqual(expectedState, actualState);
			}

			TEST_METHOD(TestWalk)
			{
				//Arrange
				Brawler brawler{ "BigJim", 100, 120, 50, CharacterState::Idle, 60, 80 };
				int expectedState{ 3 };

				//Act
				brawler.Walk();
				int actualState = brawler.GetState();

				//Assert
				Assert::AreEqual(expectedState, actualState);
			}
	};
}