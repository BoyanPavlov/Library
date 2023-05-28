#pragma once
#include "MyString.h"
#include "MyVector.hpp"

#ifndef _BOOK_
#define _BOOK_

class Book
{
private:
	MyString _author;               // Author of the book
	MyString _title;                // Title of the book
	MyString _genre;                // Genre of the book
	MyString _shortDescription;     // Short description of the book
	int _yearOfPublishing;          // Year of publishing
	MyVector<MyString> _keyWords;            // Array of keywords associated with the book
	int _rating;                    // Rating of the book
	int _isbn;                      // ISBN number of the book

public:

	// Default constructor
	Book();

	// Parameterized constructor
	Book(const MyString& author, const MyString& title, const MyString& genre, const MyString& shortDescription,
		int yearOfPublishing, const MyVector<MyString> keyWords, int rating, int isbn);

	// Getter methods for private members
	const MyString& getAuthor() const;
	const MyString& getTitle() const;
	const MyString& getGenre() const;
	const MyString& getShortDescription() const;
	int getYearOfPublishing() const;
	const MyVector<MyString>& getKeyWords() const;
	int getRating() const;
	int getISBN() const;

	// Setter methods for private members
	void setAuthor(const MyString& author);
	void setTitle(const MyString& title);
	void setGenre(const MyString& genre);
	void setShortDescription(const MyString& shortDescription);
	void setYearOfPublishing(int yearOfPublishing);
	void setKeyWords(MyVector<MyString> keywords);
	void setRating(int rating);

	bool operator==(const Book& obj);
	friend std::ostream& operator<<(std::ostream& out, const Book& obj);
};

#endif // !_BOOK_
