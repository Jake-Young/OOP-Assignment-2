/*
Weaponry Class Created by Niall Devlin
Version 1
Updated 27/11/2017
*/

#include "Weaponry.h"

Weaponry::Weaponry()
{
}


Weaponry::~Weaponry()
{
}

std::string Weaponry::GetItemName() const
{
	return itemName_;
}

int Weaponry::GetValue() const
{
	return itemValue_;
}

float Weaponry::GetWeight() const
{
	return weight_;
}

void Weaponry::SetItemName(std::string itemName)
{
	itemName_ = itemName;
}

void Weaponry::SetValue(int value)
{
	itemValue_ = value;
}

void Weaponry::SetWeight(float weight)
{
	weight_ = weight;
}
