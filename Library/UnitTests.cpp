#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "MyString.h"
#include "UserController.h"
#include "StringUtils.h"
#include "Library.h"
#include "MyVector.hpp"
#include "Book.h"

#include <sstream>

TEST_CASE("Test default constructor", "[MyStringTest]") {
	MyString str;
	REQUIRE(str.empty());
	REQUIRE(str.size() == 0);
}


TEST_CASE("Test copy constructor", "[MyStringTest]") {
	MyString str("hello world");
	MyString copy(str);
	REQUIRE(copy == str);
}


TEST_CASE("Test copy assignment operator", "[MyStringTest]") {
	MyString str("hello world");
	MyString copy;
	copy = str;
	REQUIRE(copy == str);
}

TEST_CASE("Test C-string constructor", "[MyStringTest]") {
	const char* text = "hello world";
	MyString str(text);
	REQUIRE(str == MyString("hello world"));
}

TEST_CASE("Test size", "[MyStringTest]") {
	MyString str("hello world");
	REQUIRE(str.size() == 11);
	str.push_back('!');
	REQUIRE(str.size() == 12);
	str.pop_back();
	REQUIRE(str.size() == 11);
}

TEST_CASE("Test at", "[MyStringTest]") {
	MyString str("hello world");
	REQUIRE(str.at(0) == 'h');
	REQUIRE(str.at(6) == 'w');

	MyString errorGiven;
	MyString errorExpected("Out of range");
	try
	{
		str.at(12);
	}
	catch (const std::exception& e)
	{
		errorGiven = e.what();
	}

	REQUIRE(errorGiven == errorExpected);
}

TEST_CASE("Test square brackets", "[MyStringTest]") {
	MyString str("hello world");
	REQUIRE(str[0] == 'h');
	REQUIRE(str[6] == 'w');
	REQUIRE(str[11] == '\0');
}

TEST_CASE("Test front and back", "[MyStringTest]") {
	MyString str("hello world");
	REQUIRE(str.front() == 'h');
	REQUIRE(str.back() == 'd');
	str.pop_back();
	REQUIRE(str.back() == 'l');
}

TEST_CASE("Test empty", "[MyStringTest]") {
	MyString str;
	REQUIRE(str.empty());
	str.push_back('!');
	REQUIRE_FALSE(str.empty());
}


TEST_CASE("Test clear", "[MyStringTest]") {
	MyString str("hello world");
	str.clear();
	REQUIRE(str.empty());
	REQUIRE(str.size() == 0);
	REQUIRE(str.c_str()[0] == '\0');
}

TEST_CASE("Test push_back", "[MyStringTest]") {
	MyString str("hello world");
	str.push_back('!');
	REQUIRE(str == MyString("hello world!"));
}

TEST_CASE("Test pop_back", "[MyStringTest]") {
	MyString str("hello world!");
	str.pop_back();
	REQUIRE(str == MyString("hello world"));
}

TEST_CASE("Test concatenation", "[MyStringTest]") {
	MyString str1("hello ");
	MyString str2("world!");
	MyString result = str1 + str2;
	REQUIRE(result == MyString("hello world!"));
}

////////////////////////////////////////////////////////////
//MY VECTOR
////////////////////////////////////////////////////////////

TEST_CASE("Default constructor and getSize()")
{
	MyVector<int> v;
	REQUIRE(v.getSize() == 0);
}

TEST_CASE("Constructor with initial capacity and getSize()")
{
	MyVector<int> v(5);
	REQUIRE(v.getSize() == 0);
}

TEST_CASE("Constructor with initializer list and getSize()")
{
	MyVector<int> v = { 1, 2, 3, 4, 5 };
	REQUIRE(v.getSize() == 5);
}

TEST_CASE("Copy constructor, getSize(), and operator[]()")
{
	MyVector<int> v1 = { 1, 2, 3 };
	MyVector<int> v2(v1);
	REQUIRE(v2.getSize() == 3);
	REQUIRE(v2[0] == 1);
	REQUIRE(v2[1] == 2);
	REQUIRE(v2[2] == 3);
}

TEST_CASE("vector of strings")
{
	MyVector<MyString> v1 = { "ala", "bala", "helo"};
	MyVector<MyString> v2(v1);
	REQUIRE(v2.getSize() == 3);
}




////////////////////////////////////////////////////////////
// USER CONTROLLER TESTS
////////////////////////////////////////////////////////////
//
//TEST_CASE("UserController - addUser and getUserIndex")
//{
//    UserController& controller = UserController::getInstance();
//
//    // Add users
//    controller.addUser("user1", "password1", 1);
//    controller.addUser("user2", "password2", 2);
//    controller.addUser("user3", "password3", 3);
//
//    SECTION("getUserIndex returns correct index")
//    {
//        REQUIRE(controller.getUserIndex("user1") == 0);
//        REQUIRE(controller.getUserIndex("user2") == 1);
//        REQUIRE(controller.getUserIndex("user3") == 2);
//    }
//
//    SECTION("getUserIndex returns -1 for non-existent user")
//    {
//        REQUIRE(controller.getUserIndex("user4") == -1);
//    }
//
//    SECTION("checkIfUserAlreadyExist returns true for existing user")
//    {
//        REQUIRE(controller.checkIfUserAlreadyExist("user1") == true);
//        REQUIRE(controller.checkIfUserAlreadyExist("user2") == true);
//        REQUIRE(controller.checkIfUserAlreadyExist("user3") == true);
//    }
//
//    SECTION("checkIfUserAlreadyExist returns false for non-existent user")
//    {
//        REQUIRE(controller.checkIfUserAlreadyExist("user4") == false);
//    }
//}
//
//TEST_CASE("UserController - login and logout")
//{
//    UserController& controller = UserController::getInstance();
//
//    // Add users
//    controller.addUser("user1", "password1", 1);
//    controller.addUser("user2", "password2", 2);
//
//    SECTION("login with correct password")
//    {
//        // Simulate user input
//        std::stringstream input;
//        input << "password1\n";
//        std::cin.rdbuf(input.rdbuf());
//
//        // Redirect cout for validation
//        std::stringstream output;
//        std::streambuf* coutBuffer = std::cout.rdbuf(output.rdbuf());
//
//        controller.login("user1");
//
//        // Restore cout
//        std::cout.rdbuf(coutBuffer);
//
//        REQUIRE(output.str() == "Enter user1's password:  Welcome user1\n");
//    }
//
//    SECTION("login with wrong password")
//    {
//        // Simulate user input
//        std::stringstream input;
//        input << "wrongpassword\n";
//        input << "password1\n";
//        std::cin.rdbuf(input.rdbuf());
//
//        // Redirect cout for validation
//        std::stringstream output;
//        std::streambuf* coutBuffer = std::cout.rdbuf(output.rdbuf());
//
//        controller.login("user1");
//
//        // Restore cout
//        std::cout.rdbuf(coutBuffer);
//
//        REQUIRE(output.str() == "Enter user1's password:  Wrong password\nEnter user1's password:  ");
//    }
//
//    SECTION("logout")
//    {
//        // Simulate user input
//        std::stringstream input;
//        input << "password1\n";
//        std::cin.rdbuf(input.rdbuf());
//
//        // Redirect cout for validation
//        std::stringstream output;
//        std::streambuf* coutBuffer = std::cout.rdbuf(output.rdbuf());
//
//        // Login user1
//        controller.login("user1");
//
//        // Logout user1
//        controller.logout("user1");
//
//        // Restore cout
//        std::cout.rdbuf(coutBuffer);
//
//        REQUIRE(output.str() ==  "Enter user1's password:  Welcome user1\nHave a good day user1\n");
//    }
//}

////////////////////////////////////////////////
//BOOKS TESTS
////////////////////////////////////////////////

TEST_CASE("Book - Default Constructor")
{
	Book book;
	REQUIRE(book.getAuthor() == nullptr);
	REQUIRE(book.getTitle() == nullptr);
	REQUIRE(book.getGenre() == nullptr);
	REQUIRE(book.getShortDescription() == nullptr);
	REQUIRE(book.getYearOfPublishing() == 0);
	REQUIRE(book.getKeyWords() == nullptr);
	REQUIRE(book.getRating() == 0);
	REQUIRE(book.getISBN() == 0);
}

TEST_CASE("Book - Parameterized Constructor")
{
	MyString author("Author");
	MyString title("Title");
	MyString genre("Genre");
	MyString shortDescription("Short Description");
	MyString keywords[3] = { "Keyword1", "Keyword2", "Keyword3" };
	int numberOfKeyWords = 3;
	int yearOfPublishing = 2021;
	int rating = 4;
	int isbn = 123456789;

	Book book(author, title, genre, shortDescription, yearOfPublishing, keywords, numberOfKeyWords, rating, isbn);

	REQUIRE(book.getAuthor() == "Author");
	REQUIRE(book.getTitle() == "Title");
	REQUIRE(book.getGenre() == "Genre");
	REQUIRE(book.getShortDescription() == "Short Description");
	REQUIRE(book.getYearOfPublishing() == 2021);
	REQUIRE(book.getKeyWords() != nullptr);
	REQUIRE(book.getKeyWords()[0] == "Keyword1");
	REQUIRE(book.getKeyWords()[1] == "Keyword2");
	REQUIRE(book.getKeyWords()[2] == "Keyword3");
	REQUIRE(book.getRating() == 4);
	REQUIRE(book.getISBN() == 123456789);
}

TEST_CASE("Book - Copy Constructor")
{
	MyString author("Author");
	MyString title("Title");
	MyString genre("Genre");
	MyString shortDescription("Short Description");
	MyString keywords[3] = { "Keyword1", "Keyword2", "Keyword3" };
	int numberOfKeyWords = 3;

	int yearOfPublishing = 2021;
	int rating = 4;
	int isbn = 123456789;

	Book original(author, title, genre, shortDescription, yearOfPublishing, keywords, numberOfKeyWords, rating, isbn);
	Book copy(original);

	REQUIRE(copy.getAuthor() == "Author");
	REQUIRE(copy.getTitle() == "Title");
	REQUIRE(copy.getGenre() == "Genre");
	REQUIRE(copy.getShortDescription() == "Short Description");
	REQUIRE(copy.getYearOfPublishing() == 2021);
	REQUIRE(copy.getKeyWords() != nullptr);
	REQUIRE(copy.getKeyWords()[0] == "Keyword1");
	REQUIRE(copy.getKeyWords()[1] == "Keyword2");
	REQUIRE(copy.getKeyWords()[2] == "Keyword3");
	REQUIRE(copy.getRating() == 4);
	REQUIRE(copy.getISBN() == 123456789);
}

TEST_CASE("Book - Assignment Operator")
{
	MyString author("Author");
	MyString title("Title");
	MyString genre("Genre");
	MyString shortDescription("Short Description");
	MyString keywords[3] = { "Keyword1", "Keyword2", "Keyword3" };
	int numberOfKeyWords = 3;
	int yearOfPublishing = 2021;
	int rating = 4;
	int isbn = 123456789;

	Book original(author, title, genre, shortDescription, yearOfPublishing, keywords, numberOfKeyWords, rating, isbn);
	Book copy;
	copy = original;

	REQUIRE(copy.getAuthor() == "Author");
	REQUIRE(copy.getTitle() == "Title");
	REQUIRE(copy.getGenre() == "Genre");
	REQUIRE(copy.getShortDescription() == "Short Description");
	REQUIRE(copy.getYearOfPublishing() == 2021);
	REQUIRE(copy.getKeyWords() != nullptr);
	REQUIRE(copy.getKeyWords()[0] == "Keyword1");
	REQUIRE(copy.getKeyWords()[1] == "Keyword2");
	REQUIRE(copy.getKeyWords()[2] == "Keyword3");
	REQUIRE(copy.getRating() == 4);
	REQUIRE(copy.getISBN() == 123456789);
}

TEST_CASE("Book - Setters and Getters")
{
	Book book;

	book.setAuthor("Author");
	REQUIRE(book.getAuthor() == "Author");

	book.setTitle("Title");
	REQUIRE(book.getTitle() == "Title");

	book.setGenre("Genre");
	REQUIRE(book.getGenre() == "Genre");

	book.setShortDescription("Short Description");
	REQUIRE(book.getShortDescription() == "Short Description");

	book.setYearOfPublishing(2021);
	REQUIRE(book.getYearOfPublishing() == 2021);

	MyString keywords[3] = { "Keyword1", "Keyword2", "Keyword3" };
	int numOfKeywords = 3;
	book.setKeyWords(keywords,numOfKeywords);
	REQUIRE(book.getKeyWords() != nullptr);
	REQUIRE(book.getKeyWords()[0] == "Keyword1");
	REQUIRE(book.getKeyWords()[1] == "Keyword2");
	REQUIRE(book.getKeyWords()[2] == "Keyword3");

	book.setRating(4);
	REQUIRE(book.getRating() == 4);

}

////////////////////////////////////////////////
//LIBRARY TESTS
////////////////////////////////////////////////

//
//TEST_CASE("Library - Default Constructor")
//{
//	Library library;
//	REQUIRE(library.getBooks() != nullptr);
//	REQUIRE(library.getBooks()[0].getAuthor() == nullptr);
//	REQUIRE(library.getBooks()[0].getTitle() == nullptr);
//	REQUIRE(library.getBooks()[0].getGenre() == nullptr);
//	REQUIRE(library.getBooks()[0].getISBN() == 0);
//}
//
//TEST_CASE("Library - Copy Constructor")
//{
//	Library library1;
//
//	MyString author1 = "Author1";
//	MyString title1 = "Title1";
//	MyString genre1 = "Genre1";
//	MyString desc1 = "ShortDescription1";
//	int year1 = 1;
//	int rating1 = 11;
//	int isbn1 = 123456789;
//	Book book(author1, title1, genre1, desc1, year1, nullptr, 0,rating1, isbn1);
//	library1.addBook(book);
//
//	Library library2(library1);
//	REQUIRE(library2.getBooks() != nullptr);
//	REQUIRE(library2.getBooks()[0].getAuthor() == "Author");
//	REQUIRE(library2.getBooks()[0].getTitle() == "Title");
//	REQUIRE(library2.getBooks()[0].getGenre() == "Genre");
//	REQUIRE(library2.getBooks()[0].getISBN() == 123456789);
//}
//
//TEST_CASE("Library - Assignment Operator")
//{
//	Library library1;
//	MyString author1 = "Author1";
//	MyString title1 = "Title1";
//	MyString genre1 = "Genre1";
//	MyString desc1 = "ShortDescription1";
//	int year1 = 1;
//	int rating1 = 11;
//	int isbn1 = 123456789;
//	Book book(author1, title1, genre1, desc1, year1, nullptr, 0, rating1, isbn1);
//	library1.addBook(book);
//
//	Library library2;
//	library2 = library1;
//	REQUIRE(library2.getBooks() != nullptr);
//	REQUIRE(library2.getBooks()[0].getAuthor() == "Author");
//	REQUIRE(library2.getBooks()[0].getTitle() == "Title");
//	REQUIRE(library2.getBooks()[0].getGenre() == "Genre");
//	REQUIRE(library2.getBooks()[0].getISBN() == 123456789);
//}
//
//TEST_CASE("Library - Book Info")
//{
//	Library library;
//	MyString author1 = "Author1";
//	MyString title1 = "Title1";
//	MyString genre1 = "Genre1";
//	MyString desc1 = "ShortDescription1";
//	int year1 = 1;
//	int rating1 = 11;
//	int isbn1 = 123456789;
//	Book book(author1, title1, genre1, desc1, year1, nullptr, 0,rating1, isbn1);
//
//	library.getBooks()[0] = book;
//
//	SECTION("Existing Book")
//	{
//		std::stringstream output;
//		std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());
//
//		library.bookInfo(123456789);
//
//		std::cout.rdbuf(oldCoutBuffer);
//		REQUIRE(output.str() == "Author: Author\nTitle: Title\nGenre: Genre\nISBN: 123456789\n");
//	}
//
//	SECTION("Non-Existing Book")
//	{
//		REQUIRE_THROWS_WITH(library.bookInfo(987654321), "Couldn't find book with this ISBN in the collection\n");
//	}
//}
//
//TEST_CASE("Library - Find Book Index By Author")
//{
//	Library library;
//
//	MyString author1 = "Author1";
//	MyString author2 = "Author2";
//	MyString title1 = "Title1";
//	MyString title2 = "Title2";
//	MyString genre1 = "Genre1";
//	MyString genre2 = "Genre2";
//	MyString desc1 = "ShortDescription1";
//	MyString desc2 = "ShortDescription2";
//	int year1 = 1;
//	int year2 = 2;
//	int rating1 = 11;
//	int rating2 = 12;
//	int isbn1 = 123456789;
//	int isbn2 = 987654321;
//
//	Book book1(author1, title1, genre1, desc1, year1, nullptr,0,rating1, isbn1);
//	Book book2(author2, title2, genre2, desc2, year2, nullptr,0,rating2, isbn2);
//
//	library.getBooks()[0] = book1;
//	library.getBooks()[1] = book2;
//
//	SECTION("Existing Author")
//	{
//		int index = library.findBookIndexByAuthor("Author2");
//		REQUIRE(index == 1);
//	}
//
//	SECTION("Non-Existing Author")
//	{
//		int index = library.findBookIndexByAuthor("Author3");
//		REQUIRE(index == -1);
//	}
//}
//
//TEST_CASE("Library - Find Book Index By Genre")
//{
//	Library library;
//
//	MyString author1 = "Author1";
//	MyString author2 = "Author2";
//	MyString title1 = "Title1";
//	MyString title2 = "Title2";
//	MyString genre1 = "Genre1";
//	MyString genre2 = "Genre2";
//	MyString desc1 = "ShortDescription1";
//	MyString desc2 = "ShortDescription2";
//	int year1 = 1;
//	int year2 = 2;
//	int rating1 = 11;
//	int rating2 = 12;
//	int isbn1 = 123456789;
//	int isbn2 = 987654321;
//
//	Book book1(author1, title1, genre1, desc1, year1, nullptr, 0,rating1, isbn1);
//	Book book2(author2, title2, genre2, desc2, year2, nullptr, 0,rating2, isbn2);
//	library.getBooks()[0] = book1;
//	library.getBooks()[1] = book2;
//
//	SECTION("Existing Genre")
//	{
//		int index = library.findBookIndexByGenre("Genre2");
//		REQUIRE(index == 1);
//	}
//
//	SECTION("Non-Existing Genre")
//	{
//		int index = library.findBookIndexByGenre("Genre3");
//		REQUIRE(index == -1);
//	}
//}
//
//TEST_CASE("Library - Find Book Index By Title")
//{
//	Library library;
//
//	MyString author1 = "Author1";
//	MyString author2 = "Author2";
//	MyString title1 = "Title1";
//	MyString title2 = "Title2";
//	MyString genre1 = "Genre1";
//	MyString genre2 = "Genre2";
//	MyString desc1 = "ShortDescription1";
//	MyString desc2 = "ShortDescription2";
//	int year1 = 1;
//	int year2 = 2;
//	int rating1 = 11;
//	int rating2 = 12;
//	int isbn1 = 123456789;
//	int isbn2 = 987654321;
//
//	Book book1(author1, title1, genre1, desc1, year1, nullptr, 0,rating1, isbn1);
//	Book book2(author2, title2, genre2, desc2, year2, nullptr, 0,rating2, isbn2);
//	library.getBooks()[0] = book1;
//	library.getBooks()[1] = book2;
//
//	SECTION("Existing Title")
//	{
//		int index = library.findBookIndexByTitle("Title2");
//		REQUIRE(index == 1);
//	}
//
//	SECTION("Non-Existing Title")
//	{
//		int index = library.findBookIndexByTitle("Title3");
//		REQUIRE(index == -1);
//	}
//}
//
//TEST_CASE("Library - Sort Books By Author")
//{
//	Library library;
//
//	MyString author1 = "Author1";
//	MyString author2 = "Author2";
//	MyString title1 = "Title1";
//	MyString title2 = "Title2";
//	MyString genre1 = "Genre1";
//	MyString genre2 = "Genre2";
//	MyString desc1 = "ShortDescription1";
//	MyString desc2 = "ShortDescription2";
//	int year1 = 1;
//	int year2 = 2;
//	int rating1 = 11;
//	int rating2 = 12;
//	int isbn1 = 123456789;
//	int isbn2 = 987654321;
//
//	Book book1(author1, title1, genre1, desc1, year1, nullptr, 0,rating1, isbn1);
//	Book book2(author2, title2, genre2, desc2, year2, nullptr, 0,rating2, isbn2);
//	library.getBooks()[0] = book1;
//	library.getBooks()[1] = book2;
//
//	SECTION("Ascending Order")
//	{
//		library.sortBooksByAuthor(true);
//		REQUIRE(library.getBooks()[0].getAuthor() == "Author1");
//		REQUIRE(library.getBooks()[1].getAuthor() == "Author2");
//	}
//
//	SECTION("Descending Order")
//	{
//		library.sortBooksByAuthor(false);
//		REQUIRE(library.getBooks()[0].getAuthor() == "Author2");
//		REQUIRE(library.getBooks()[1].getAuthor() == "Author1");
//	}
//}
//
//TEST_CASE("Library - Sort Books By Genre")
//{
//	Library library;
//
//	MyString author1 = "Author1";
//	MyString author2 = "Author2";
//	MyString title1 = "Title1";
//	MyString title2 = "Title2";
//	MyString genre1 = "Genre1";
//	MyString genre2 = "Genre2";
//	MyString desc1 = "ShortDescription1";
//	MyString desc2 = "ShortDescription2";
//	int year1 = 1;
//	int year2 = 2;
//	int rating1 = 11;
//	int rating2 = 12;
//	int isbn1 = 123456789;
//	int isbn2 = 987654321;
//
//	Book book1(author1, title1, genre1, desc1, year1, nullptr,0, rating1, isbn1);
//	Book book2(author2, title2, genre2, desc2, year2, nullptr,0, rating2, isbn2);
//	library.getBooks()[0] = book1;
//	library.getBooks()[1] = book2;
//
//	SECTION("Ascending Order")
//	{
//		library.sortBooksByGenre(true);
//		REQUIRE(library.getBooks()[0].getGenre() == "Genre1");
//		REQUIRE(library.getBooks()[1].getGenre() == "Genre2");
//	}
//
//	SECTION("Descending Order")
//	{
//		library.sortBooksByGenre(false);
//		REQUIRE(library.getBooks()[0].getGenre() == "Genre2");
//		REQUIRE(library.getBooks()[1].getGenre() == "Genre1");
//	}
//}
//
//TEST_CASE("Library - Sort Books By Title")
//{
//	Library library;
//
//	MyString author1 = "Author1";
//	MyString author2 = "Author2";
//	MyString title1 = "Title1";
//	MyString title2 = "Title2";
//	MyString genre1 = "Genre1";
//	MyString genre2 = "Genre2";
//	MyString desc1 = "ShortDescription1";
//	MyString desc2 = "ShortDescription2";
//	int year1 = 1;
//	int year2 = 2;
//	int rating1 = 11;
//	int rating2 = 12;
//	int isbn1 = 123456789;
//	int isbn2 = 987654321;
//
//	Book book1(author1, title1, genre1, desc1, year1, nullptr, 0,rating1, isbn1);
//	Book book2(author2, title2, genre2, desc2, year2, nullptr, 0,rating2, isbn2);
//	library.getBooks()[0] = book1;
//	library.getBooks()[1] = book2;
//
//	SECTION("Ascending Order")
//	{
//		library.sortBooksByTitle(true);
//		REQUIRE(library.getBooks()[0].getTitle() == "Title1");
//		REQUIRE(library.getBooks()[1].getTitle() == "Title2");
//	}
//
//	SECTION("Descending Order")
//	{
//		library.sortBooksByTitle(false);
//		REQUIRE(library.getBooks()[0].getTitle() == "Title2");
//		REQUIRE(library.getBooks()[1].getTitle() == "Title1");
//	}
//}
