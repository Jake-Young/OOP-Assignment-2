/*
Item Class Created by Niall Devlin
Version 1
Updated 27/11/2017
*/

#include "Item.h"

Item::Item()
{

}

Item::Item(std::string itemName, int value, float weight) : itemName_{ itemName }, itemValue_{ value }, weight_{weight}
{

}

Item::~Item()
{

}

std::string Item::GetItemName() const
{
	return itemName_;
}

int Item::GetValue() const
{
	return itemValue_;
}

float Item::GetWeight() const
{
	return weight_;
}

void Item::SetItemName(std::string itemName)
{
	itemName_ = itemName;
}

void Item::SetValue(int value)
{
	itemValue_ = value;
}

void Item::SetWeight(float weight)
{
	weight_ = weight;
}
