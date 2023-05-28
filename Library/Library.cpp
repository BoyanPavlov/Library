#include <iostream>
#include "Library.h"
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

Book* Library::allocateBooks(int size)
{
	Book* tmp = nullptr;
	try
	{
		tmp = new Book[size];
	}
	catch (const std::exception& e)
	{
		cerr << e.what();
		delete[] tmp;
	}
	return tmp;
}

void Library::freeBooksMem()
{
	delete[] _books;
	_books = nullptr;
}

void Library::resizeLibrary()
{
	_capacity *= 2;
	Book* tmp = allocateBooks(_capacity);
	for (size_t i = 0; i < _size; i++)
	{
		tmp[i] = _books[i];
	}
	freeBooksMem();
	_books = tmp;
}

Library::Library()
	: _books(nullptr), _size(0), _capacity(INITIAL_CAPACITY)
{
	_books = allocateBooks(_capacity);
}


Library::Library(const Library& obj)
	: _books(nullptr), _size(obj._size), _capacity(obj._capacity)
{
	if (_size > 0) {
		_books = allocateBooks(_capacity);
		for (int i = 0; i < _size; i++)
		{
			_books[i] = obj._books[i];
		}
	}
}

Library& Library::operator=(const Library& obj)
{
	if (this != &obj)
	{
		freeBooksMem();

		_size = obj._size;
		_capacity = obj._capacity;

		if (_size > 0)
		{
			_books = allocateBooks(_capacity);
			for (int i = 0; i < _size; i++) {
				_books[i] = obj._books[i];
			}
		}
	}
	return *this;
}

Library::~Library() {
	freeBooksMem();
}

Book* Library::getBooks() const {
	return _books;
}

void Library::printAll() {
	for (int i = 0; i < _size; i++) {
		cout << _books[i];
	}
}

void Library::bookInfo(int isbn)
{
	for (int i = 0; i < _size; i++)
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
	for (int i = 0; i < _size; i++)
	{
		if (_books[i].getAuthor() == input)
		{
			return i;
		}
	}
	return -1;
}

int Library::findBookIndexByGenre(const MyString& input) {
	for (int i = 0; i < _size; i++)
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
	for (int i = 0; i < _size; i++)
	{
		if (_books[i].getTitle() == input)
		{
			return i;
		}
	}
	return -1;
}

void Library::sortBooksByAuthor(bool acs)
{
	for (size_t i = 1; i < _size; ++i)
	{
		Book& currentBook = _books[i];
		int j = i;
		while (j > 0 && compareStrings(_books[j - 1].getAuthor(), currentBook.getAuthor(), acs))
		{
			_books[j] = _books[j - 1];
			--j;
		}
		_books[j] = currentBook;
	}
}

void Library::sortBooksByGenre(bool acs)
{
	for (size_t i = 1; i < _size; ++i)
	{
		Book& currentBook = _books[i];
		int j = i;
		while (j > 0 && compareStrings(_books[j - 1].getGenre(), currentBook.getGenre(), acs))
		{
			_books[j] = _books[j - 1];
			--j;
		}
		_books[j] = currentBook;
	}
}
void Library::sortBooksByTitle(bool acs)
{
	for (size_t i = 1; i < _size; ++i)
	{
		Book& currentBook = _books[i];
		int j = i;
		while (j > 0 && compareStrings(_books[j - 1].getTitle(), currentBook.getTitle(), acs))
		{
			_books[j] = _books[j - 1];
			--j;
		}
		_books[j] = currentBook;
	}
}

void Library::addBook(const Book* obj)
{

}

void Library::removeBook(const Book* obj)
{

}