#include <iostream>
#include "Library.h"
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

const MyVector<Book>& Library::getBooks() const {
	return _books;
}

void Library::printAll() {
	if (_books.getSize()==0)
	{
		cout << "No books in the library\n";
		return;
	}

	for (int i = 0; i < _books.getSize(); i++) {
		cout << "Title: " << _books[i].getTitle() << "\n"
			<< "Author: " << _books[i].getAuthor() << "\n"
			<< "Genre: " << _books[i].getGenre() << "\n"
			<< "ISBN: " << _books[i].getISBN() << "\n";
	}
}
void Library::bookInfo(int isbn)
{
	for (int i = 0; i < _books.getSize(); i++)
	{
		if (_books[i].getISBN() == isbn)
		{
			cout << _books[i];
			return;
		}
	}
	throw std::exception("Couldn't find book with this ISBN in the collection\n");
}

int Library::findBookIndexByAuthor(const MyString& input)
{
	for (int i = 0; i < _books.getSize(); i++)
	{
		if (_books[i].getAuthor() == input)
		{
			return i;
		}
	}
	return -1;
}

int Library::findBookIndexByGenre(const MyString& input) {
	for (int i = 0; i < _books.getSize(); i++)
	{
		if (_books[i].getGenre() == input)
		{
			return i;
		}
	}

	return -1;
}

int Library::findBookIndexByTitle(const MyString& input)
{
	for (int i = 0; i < _books.getSize(); i++)
	{
		if (_books[i].getTitle() == input)
		{
			return i;
		}
	}
	return -1;
}

void Library::sortBooksByAuthorHelper(MyVector<Book>& books, Book currentBook, int size, bool acs)
{
	int index = size;

	while (index > 0 && compareStrings(_books[index - 1].getAuthor(), currentBook.getAuthor(), !acs))
	{
		_books[index] = _books[index - 1];
		--index;
	}
	_books[index] = currentBook;
}

void Library::sortBooksByTitleHelper(MyVector<Book>& books, Book currentBook, int size, bool acs)
{
	int index = size;

	while (index > 0 && compareStrings(_books[index - 1].getTitle(), currentBook.getTitle(), !acs))
	{
		_books[index] = _books[index - 1];
		--index;
	}
	_books[index] = currentBook;
}

void Library::sortBooksByRatingHelper(MyVector<Book>& books, Book currentBook, int size, bool acs)
{
	int index = size;

	if (acs)
	{
		while (index > 0 && _books[index - 1].getRating() > currentBook.getRating())
		{
			_books[index] = _books[index - 1];
			--index;
		}
	}
	else
	{
		while (index > 0 && _books[index - 1].getRating() < currentBook.getRating())
		{
			_books[index] = _books[index - 1];
			--index;
		}
	}

	_books[index] = currentBook;
}

void Library::sortBooksByYearHelper(MyVector<Book>& books, Book currentBook, int size, bool acs)
{
	int index = size;

	if (acs)
	{
		while (index > 0 && _books[index - 1].getYearOfPublishing() > currentBook.getYearOfPublishing())
		{
			_books[index] = _books[index - 1];
			--index;
		}
	}
	else
	{
		while (index > 0 && _books[index - 1].getYearOfPublishing() < currentBook.getYearOfPublishing())
		{
			_books[index] = _books[index - 1];
			--index;
		}
	}

	_books[index] = currentBook;
}



void Library::sortBooksByAuthor(bool acs)
{
	for (size_t i = 1; i < _books.getSize(); ++i)
	{
		sortBooksByAuthorHelper(_books, _books[i], i, acs);
	}
}

void Library::sortBooksByRating(bool acs)
{
	for (size_t i = 1; i < _books.getSize(); ++i)
	{
		sortBooksByRatingHelper(_books, _books[i], i, acs);
	}
}
void Library::sortBooksByTitle(bool acs)
{
	for (size_t i = 1; i < _books.getSize(); ++i)
	{
		sortBooksByTitleHelper(_books, _books[i], i, acs);
	}
}

void Library::sortBooksByYear(bool acs)
{
	for (size_t i = 1; i < _books.getSize(); ++i)
	{
		sortBooksByYearHelper(_books, _books[i], i, acs);
	}
}

void Library::addBook(const Book& obj)
{
	_books.push(obj);
}

void Library::removeBook(const Book& obj)
{
	for (size_t i = 0; i < _books.getSize(); i++)
	{
		if (_books[i] == obj)
		{
			_books.removeAt(i);
			return;
		}
	}
	throw std::exception("Book isn't in the collection\n");
}