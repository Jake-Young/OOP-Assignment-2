/*
Weaponry Class Created by Niall Devlin
Version 1
Updated 27/11/2017
*/


#pragma once
#include <string>
class Weaponry
{
private:
	std::string itemName_;
	int itemValue_;
	float weight_;
public:
	Weaponry();
	Weaponry(std::string itemName, int value) : itemName_{ itemName }, itemValue_{ value } {}
	~Weaponry();

	//getters
	std::string GetItemName() const;
	int GetValue() const;
	float GetWeight() const;

	//setters
	void SetItemName(std::string itemName);
	void SetValue(int value);
	void SetWeight(float weight);
};

