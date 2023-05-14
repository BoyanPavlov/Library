#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "MyString.h"
#include "StringUtils.h"


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
