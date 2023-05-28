#include "Book.h"
#include "MyVector.hpp"

Book::Book(const MyString& author, const MyString& title,
	const MyString& genre, const MyString& shortDescription,
	int yearOfPublishing, const MyVector<MyString> keyWords, int rating, int isbn)
	:
	_author(author),
	_title(title),
	_genre(genre),
	_shortDescription(shortDescription),
	_yearOfPublishing(yearOfPublishing),
	_rating(rating),
	_isbn(isbn),
	_keyWords(keyWords)
{
}

Book::Book()
	: _yearOfPublishing(0), _rating(0), _isbn(0)
{

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

const MyVector<MyString>& Book::getKeyWords() const
{
	return _keyWords;
}

void Book::setKeyWords(const MyVector<MyString> keyWords)
{
	_keyWords = keyWords;
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

bool Book::operator==(const Book& obj)
{
	if (this->getAuthor() != obj.getAuthor() &&
		this->getGenre() != obj.getGenre() &&
		this->getISBN() != obj.getISBN() &&
		this->getRating() != obj.getRating())
	{
		return false;
	}
	return true;
}


std::ostream& operator<<(std::ostream& out, const Book& obj)
{
	out << "Title: " << obj.getTitle() << "\n"
		<< "Author: " << obj.getAuthor() << "\n"
		<< "Genre: " << obj.getGenre() << "\n"
		<< "ISBN: " << obj.getISBN() << "\n";
	return out;
}
