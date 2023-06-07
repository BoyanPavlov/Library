#pragma once
#include "FileManager.h"
using std::cin;

// unnecessary variable for better view;
const MyString line = "=============================\n";

class UI
{
private:
	FileManager _instanceFileManager;

	/// function - prints menu and so on (command help)
	int enterChoise();

	int entrance();

	void openChosen();

	MyString getOpitionForFINDfunction();

	MyString getOpitionForSortfunction();

	MyString choseACSorDECS();

	MyString readUsername();

	UI() = default;

public:

	static UI& getInstance()
	{
		static UI ref;
		return ref;
	}

	UI& operator=(const UI& e) = delete;
	UI(const UI& e) = delete;

	/// the main function in this class used for the all comunication and so on..
	void start();
};
