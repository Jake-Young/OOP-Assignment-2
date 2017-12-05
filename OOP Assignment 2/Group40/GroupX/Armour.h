/*
Armour.h created by Jake Young
Version 1
Updated 05/11/2017
*/

#pragma once

#include "Item.h"

enum class ArmourType {CardBoard, Leather, Wood, Iron, Steel};

class Armour : public Item {

private:
	int defence_;
	int armourHealth_;
	ArmourType armourType_;

public:
	Armour();

	Armour(std::string armourName, int value, float weight, int defence, int armourHealth, ArmourType armourType);

	~Armour();

};
