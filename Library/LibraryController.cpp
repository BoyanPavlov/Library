#include "LibraryController.h"
#include <iostream>

using std::endl;
using std::cerr;

LibraryController& LibraryController::getInstance()
{
	static LibraryController instance;
	return instance;
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
	_library.addBook(obj);

}

void LibraryController::removeBook(const Book& obj)
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
		return;
	}


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
		return;
	}
	cout << "Books have been sorted successfully ...\n";

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


/*
	Author: Author1
	Title: Title1
	Genre: Genre1
	ShortDescription: ShortDescription1";
	KeyWords: "Hello" "my" "friend"
	Year: 1
	Rating: 11
	ISBN: 123456789;
*/

void LibraryController::loadLibrary(const MyString& input)
{
	std::stringstream ss(input.c_str());
	std::string line;

	Book book;
	while (std::getline(ss, line))
	{
		if (line.empty())
			continue;

		std::string field, value;
		std::stringstream lineStream(line);
		std::getline(lineStream, field, ':');
		std::getline(lineStream, value);

		if (field == "Author")
			book.setAuthor(value.c_str());
		else if (field == "Title")
			book.setTitle(value.c_str());
		else if (field == "Genre")
			book.setGenre(value.c_str());
		else if (field == "ShortDescription")
			book.setShortDescription(value.c_str());
		else if (field == "KeyWords")
		{
			std::string keyword;
			std::stringstream keywordsStream(value);
			while (std::getline(keywordsStream, keyword, '"'))
			{
				if (!keyword.empty())
				{
					book.addKeyWord(keyword.c_str());
				}
			}
		}
		else if (field == "Year")
			book.setYearOfPublishing(std::stoi(value));
		else if (field == "Rating")
			book.setRating(std::stoi(value));
		else if (field == "ISBN")
			book.setISBN(std::stoi(value));
	}

	_library.addBook(book);
}


std::ostream& operator<<(std::ostream& out, const LibraryController& obj)
{
	for (size_t i = 0; i < obj._library.getBooks().getSize(); i++)
	{
		out << obj._library.getBooks()[i] << endl;
	}
	return out;
}
