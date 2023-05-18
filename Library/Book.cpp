#include "Book.h"


int Book::getNumKeywords(const MyString* keyWords) const
{
	int count = 0;
	if (keyWords != nullptr)
	{
		while (keyWords[count] != "")
		{
			count++;
		}
	}
	return count;
}

MyString* Book::allocateKeyWords(int numberOfKeyWords)
{
	MyString* strArr = nullptr;
	try
	{
		strArr = new MyString[numberOfKeyWords];
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		delete[] strArr;
	}
	return strArr;
}

void Book::freeKeyWordsMem()
{
	delete[] _keyWords;
	_keyWords = nullptr;
}

void Book::copyKeyWords(const MyString* keyWords)
{
	if (keyWords != nullptr)
	{
		int numKeywords = getNumKeywords(keyWords);
		_keyWords = allocateKeyWords(numKeywords);
		for (int i = 0; i < numKeywords; ++i)
		{
			_keyWords[i] = keyWords[i];
		}
	}
	else
	{
		_keyWords = nullptr;
	}
}

Book::Book()
	:_keyWords(nullptr), _rating(0), _isbn(0)
{

}

Book::Book(const MyString& author, const MyString& title,
	const MyString& genre, const MyString& shortDescription,
	int yearOfPublishing, const MyString* keyWords,
	int rating, int isbn)
	:
	_author(author),
	_title(title),
	_genre(genre),
	_shortDescription(shortDescription),
	_yearOfPublishing(yearOfPublishing),
	_rating(rating),
	_isbn(isbn)
{
	copyKeyWords(keyWords);
}

Book::Book(const Book& other)
	:
	_author(other._author),
	_title(other._title),
	_genre(other._genre),
	_shortDescription(other._shortDescription),
	_yearOfPublishing(other._yearOfPublishing),
	_rating(other._rating),
	_isbn(other._isbn)
{
	copyKeyWords(other._keyWords);
}

Book::~Book()
{
	freeKeyWordsMem();
}

Book& Book::operator=(const Book& other)
{
	if (this == &other)
	{
		return *this;
	}

	freeKeyWordsMem();

	_author = other._author;
	_title = other._title;
	_genre = other._genre;
	_shortDescription = other._shortDescription;
	_yearOfPublishing = other._yearOfPublishing;

	copyKeyWords(other._keyWords);

	_rating = other._rating;
	_isbn = other._isbn;

	return *this;
}

const MyString& Book::getAuthor() const
{
	return _author;
}

void Book::setAuthor(const MyString& author)
{
	_author = author;
}

const MyString& Book::getTitle() const
{
	return _title;
}

void Book::setTitle(const MyString& title)
{
	_title = title;
}

const MyString& Book::getGenre() const
{
	return _genre;
}

void Book::setGenre(const MyString& genre)
{
	_genre = genre;
}

const MyString& Book::getShortDescription() const
{
	return _shortDescription;
}

void Book::setShortDescription(const MyString& shortDescription)
{
	_shortDescription = shortDescription;
}

int Book::getYearOfPublishing() const
{
	return _yearOfPublishing;
}

void Book::setYearOfPublishing(int yearOfPublishing)
{
	_yearOfPublishing = yearOfPublishing;
}

const MyString* Book::getKeyWords() const
{
	return _keyWords;
}

void Book::setKeyWords(const MyString* keyWords)
{
	freeKeyWordsMem();

	copyKeyWords(keyWords);
}

int Book::getRating() const
{
	return _rating;
}

void Book::setRating(int rating)
{
	_rating = rating;
}

int Book::getISBN() const
{
	return _isbn;
}
