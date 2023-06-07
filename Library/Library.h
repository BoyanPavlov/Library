#pragma once

#include "Book.h"
#include "MyVector.hpp"

#ifndef _LIBRARY_
#define _LIBRARY_

const int INITIAL_CAPACITY = 10;

class Library
{
private:
	MyVector<Book> _books;

	void sortBooksByAuthorHelper(MyVector<Book>& books, Book currentBook, int size, bool acs);
	void sortBooksByTitleHelper(MyVector<Book>& books, Book currentBook, int size, bool acs);
	void sortBooksByRatingHelper(MyVector<Book>& books, Book currentBook, int size, bool acs);
	void sortBooksByYearHelper(MyVector<Book>& books, Book currentBook, int size, bool acs);
public:
	Library() : _books(10) {}

	const MyVector<Book>& getBooks() const;

	void printAll();// prints all books: title, author, genre, isbn

	void bookInfo(int isbn);//prints info about book with given isbn

	int findBookIndexByAuthor(const MyString& input);
	int findBookIndexByGenre(const MyString& input);
	int findBookIndexByTitle(const MyString& input);

	void sortBooksByAuthor(bool acs = true);//sort by acsending
	void sortBooksByRating(bool acs = true);//sort by acsending
	void sortBooksByTitle(bool acs = true);//sort by acsending
	void sortBooksByYear(bool acs = true);//sort by acsending

	void addBook(const Book& obj);
	void removeBook(const Book& obj);
};

#endif // !_LIBRARY_
