#pragma once

#include "Book.h"

#ifndef _LIBRARY_
#define _LIBRARY_

const int INITIAL_CAPACITY = 10;

class Library
{
private:
	Book* _books;
	int _size;
	int _capacity;

	Book* allocateBooks(int size);
	void freeBooksMem();
	void resizeLibrary();

public:

	Library();
	Library(const Library& obj);
	Library& operator=(const Library& obj);
	~Library();

	Book* getBooks() const;

	void printAll();// prints all books: title, author, genre, isbn

	void bookInfo(int isbn);//prints info about book with given isbn

	int findBookIndexByAuthor(const MyString& input);
	int findBookIndexByGenre(const MyString& input);
	int findBookIndexByTitle(const MyString& input);

	void sortBooksByAuthor(bool acs = true);//sort by acsending
	void sortBooksByGenre(bool acs = true);//sort by acsending
	void sortBooksByTitle(bool acs = true);//sort by acsending

	void addBook(const Book* obj);
	void removeBook(const Book* obj);
};

#endif // !_LIBRARY_
