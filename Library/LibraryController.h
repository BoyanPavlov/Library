#pragma once
#include "Library.h"
#include <sstream>

#ifndef _LIBRARY_CONTROLLER
#define _LIBRARY_CONTROLLER

class LibraryController
{
private:
	Library _library;

	LibraryController() = default;
public:
	LibraryController(const LibraryController& obj) = delete;
	LibraryController& operator=(const LibraryController& obj) = delete;

	static LibraryController& getInstance();

	void loadLibrary(const MyString& input);

	void printAll();// prints all books: title, author, genre, isbn

	void bookInfo(int isbn);//prints info about book with given isbn

	void addBook(const Book& obj);

	void removeBook(const Book& obj);

	void sortBook(const MyString& option, const MyString& AscendingOrDecending);//sort books by author, title, rating and year

	void findBook(const MyString& option, const MyString& input);//finds a book by genre, title or author

	friend std::ostream& operator<<(std::ostream& out, const LibraryController& obj);
};

#endif // !_LIBRARY_CONTROLLER
