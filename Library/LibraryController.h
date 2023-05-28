#pragma once
#include "Library.h"

#ifndef _LIBRARY_CONTROLLER
#define _LIBRARY_CONTROLLER

class LibraryController
{
private:
	Library _library;
	bool _hasAccess = false;

	LibraryController() = default;
public:
	LibraryController(const LibraryController& obj) = delete;
	LibraryController& operator=(const LibraryController& obj) = delete;

	static LibraryController& getIntance();

	void setAccessLevel(bool access);

	void printAll();// prints all books: title, author, genre, isbn

	void bookInfo(int isbn);//prints info about book with given isbn

	void addBook(const Book& obj);

	void removeBook(const Book& obj);

	void sortBook(const MyString& option, const MyString& AscendingOrDecending);//sort books by author, title, rating and year

	void findBook(const MyString& option, const MyString& input);//finds a book by genre, title or author
};

#endif // !_LIBRARY_CONTROLLER

