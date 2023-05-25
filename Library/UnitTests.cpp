#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "MyString.h"
#include "UserController.h"
#include "StringUtils.h"
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
// USER CONTROLLER TESTS
////////////////////////////////////////////////////////////

TEST_CASE("UserController - addUser and getUserIndex")
{
    UserController& controller = UserController::getInstance();

    // Add users
    controller.addUser("user1", "password1", 1);
    controller.addUser("user2", "password2", 2);
    controller.addUser("user3", "password3", 3);

    SECTION("getUserIndex returns correct index")
    {
        REQUIRE(controller.getUserIndex("user1") == 0);
        REQUIRE(controller.getUserIndex("user2") == 1);
        REQUIRE(controller.getUserIndex("user3") == 2);
    }

    SECTION("getUserIndex returns -1 for non-existent user")
    {
        REQUIRE(controller.getUserIndex("user4") == -1);
    }

    SECTION("checkIfUserAlreadyExist returns true for existing user")
    {
        REQUIRE(controller.checkIfUserAlreadyExist("user1") == true);
        REQUIRE(controller.checkIfUserAlreadyExist("user2") == true);
        REQUIRE(controller.checkIfUserAlreadyExist("user3") == true);
    }

    SECTION("checkIfUserAlreadyExist returns false for non-existent user")
    {
        REQUIRE(controller.checkIfUserAlreadyExist("user4") == false);
    }
}

TEST_CASE("UserController - login and logout")
{
    UserController& controller = UserController::getInstance();

    // Add users
    controller.addUser("user1", "password1", 1);
    controller.addUser("user2", "password2", 2);

    SECTION("login with correct password")
    {
        // Simulate user input
        std::stringstream input;
        input << "password1\n";
        std::cin.rdbuf(input.rdbuf());

        // Redirect cout for validation
        std::stringstream output;
        std::streambuf* coutBuffer = std::cout.rdbuf(output.rdbuf());

        controller.login("user1");

        // Restore cout
        std::cout.rdbuf(coutBuffer);

        REQUIRE(output.str() == "Enter user1's password:  Welcome user1\n");
    }

    SECTION("login with wrong password")
    {
        // Simulate user input
        std::stringstream input;
        input << "wrongpassword\n";
        input << "password1\n";
        std::cin.rdbuf(input.rdbuf());

        // Redirect cout for validation
        std::stringstream output;
        std::streambuf* coutBuffer = std::cout.rdbuf(output.rdbuf());

        controller.login("user1");

        // Restore cout
        std::cout.rdbuf(coutBuffer);

        REQUIRE(output.str() == "Enter user1's password:  Wrong password\nEnter user1's password:  ");
    }

    SECTION("logout")
    {
        // Simulate user input
        std::stringstream input;
        input << "password1\n";
        std::cin.rdbuf(input.rdbuf());

        // Redirect cout for validation
        std::stringstream output;
        std::streambuf* coutBuffer = std::cout.rdbuf(output.rdbuf());

        // Login user1
        controller.login("user1");

        // Logout user1
        controller.logout("user1");

        // Restore cout
        std::cout.rdbuf(coutBuffer);

        REQUIRE(output.str() ==  "Enter user1's password:  Welcome user1\nHave a good day user1\n");
    }
}
