#pragma once
#include "MyString.h"

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
	MyString* _keyWords;            // Array of keywords associated with the book
	int _rating;                    // Rating of the book
	int _isbn;                      // ISBN number of the book

	// Helper methods for managing the dynamic memory of _keyWords
	int _numberOfKeyWords;
	MyString* allocateKeyWords(int numberOfKeyWords);    // Allocates memory for _keyWords array
	void freeKeyWordsMem();                              // Frees the memory of _keyWords array
	void copyKeyWords(const MyString* keyWords);         // Copies the keywords from the provided array

public:
	int getNumKeywords() const;  // Calculates the number of keywords in the array

	// Default constructor
	Book();

	// Parameterized constructor
	Book(const MyString& author, const MyString& title, const MyString& genre, const MyString& shortDescription,
		int yearOfPublishing, const MyString* keyWords, int numberOfKeyWords, int rating, int isbn);

	// Copy constructor
	Book(const Book& other);

	// Destructor
	~Book();

	// Assignment operator
	Book& operator=(const Book& other);

	// Getter methods for private members
	const MyString& getAuthor() const;
	const MyString& getTitle() const;
	const MyString& getGenre() const;
	const MyString& getShortDescription() const;
	int getYearOfPublishing() const;
	const MyString* getKeyWords() const;
	int getRating() const;
	int getISBN() const;

	// Setter methods for private members
	void setAuthor(const MyString& author);
	void setTitle(const MyString& title);
	void setGenre(const MyString& genre);
	void setShortDescription(const MyString& shortDescription);
	void setYearOfPublishing(int yearOfPublishing);
	void setKeyWords(const MyString* keyWords,int numberOfKeyWords);
	void setRating(int rating);

	friend std::ostream& operator<<(std::ostream& out, const Book& obj);
};

#endif // !_BOOK_
