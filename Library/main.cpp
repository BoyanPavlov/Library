// Library.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "UI.h"

int main()
{
	UI& instance = UI::getInstance();
	instance.start();

	return 0;
}
