#include "LibraryController.h"
#include <iostream>

using std::endl;
using std::cerr;

LibraryController& LibraryController::getIntance()
{
	LibraryController instance;
	return instance;
}


void LibraryController::setAccessLevel(bool access)
{
	_hasAccess = access;
}

void LibraryController::printAll()
{
	_library.printAll();
}

void LibraryController::bookInfo(int isbn)
{
	try
	{
		_library.bookInfo(isbn);
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
}

void LibraryController::addBook(const Book& obj)
{
	if (_hasAccess)
	{
		_library.addBook(obj);
	}
	else
	{
		cerr << "Sorry users doesn't have permission to add books\n";
	}
}

void LibraryController::removeBook(const Book& obj)
{
	if (_hasAccess)
	{
		try
		{
			_library.removeBook(obj);
		}
		catch (const std::exception& e)
		{
			cerr << e.what() << endl;
		}
	}
	else
	{
		cerr << "Sorry users doesn't have permission to remove books\n";
	}
}

void LibraryController::sortBook(const MyString& option, const MyString& AscendingOrDecending)
{
	bool acs = false;
	if (AscendingOrDecending == "acs")
	{
		acs = true;
	}
	else if (AscendingOrDecending == "decs")
	{
		acs = false;
	}
	else
	{
		cerr << "Unknown order\n";
	}


	if (_hasAccess)
	{
		if (option == "title")
		{
			_library.sortBooksByTitle(acs);
		}
		else if (option == "author")
		{
			_library.sortBooksByAuthor(acs);

		}
		else if (option == "year")
		{
			_library.sortBooksByYear(acs);

		}
		else if ("rating")
		{
			_library.sortBooksByRating(acs);
		}
		else
		{
			cerr << "Unknown option\n";
		}
	}
	else
	{
		cerr << "Sorry users doesn't have permission to remove books\n";
	}
}

void LibraryController::findBook(const MyString& option, const MyString& input)
{
	if (option == "title")
	{
		_library.findBookIndexByTitle(input);
	}
	else if (option == "author")
	{
		_library.findBookIndexByAuthor(input);

	}
	else if (option == "genre")
	{
		_library.findBookIndexByGenre(input);

	}
	else
	{
		cerr << "Unknown option\n";
	}
}