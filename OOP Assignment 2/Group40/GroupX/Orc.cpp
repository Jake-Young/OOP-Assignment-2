/*
Orc Class Created by Niall Devlin
Version 1
Updated 28/11/2017
*/

#include "Orc.h"



Orc::Orc()
{
}


Orc::~Orc()
{
}

int Orc::GetFerocity() const
{
	return ferociousness_;
}

int Orc::GetStrength() const
{
	return strength_;
}

void Orc::SetFerocity(int ferocity)
{
	ferociousness_ = ferocity;
}

void Orc::SetStrength(int str)
{
	strength_ = str;
}
