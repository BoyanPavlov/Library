#pragma once

#include <iostream>
#include <fstream>
#include "UserController.h"
#include "LibraryController.h"

using std::ifstream;
using std::ofstream;


#ifndef _FILE_MANAGER_
#define _FILE_MANAGER_

enum e_Commands
{
	// basic commands
	e_OPEN,
	e_CLOSE,
	e_SAVE,
	e_SAVE_AS,
	e_HELP,
	e_EXIT,
	//library commands
	e_BOOKS_ALL,
	e_BOOKS_INFO,
	e_BOOKS_FIND,
	e_BOOKS_SORT,
	e_BOOKS_ADD,
	e_BOOKS_REMOVE,
	//user commands
	e_USER_LOGIN,
	e_USER_LOGOUT,
	e_USER_ADD,
	e_USER_REMOVE,

	e_UNKNOWN
};


class FileManager
{
protected:
	MyString _path;
	bool _isFileSaved;
	UserControllerItem* _currentUser;

	UserController& _instanceUserController = UserController::getInstance();
	LibraryController& _instanceLibraryController = LibraryController::getInstance();

public:
	FileManager();
	//the lack of operator = and copy constr is wanted and expected beh, and I know - i have a pointer up there

	void setCurrentUser(UserControllerItem& currentUser);
	UserControllerItem& getCurrentUser()const;
	UserControllerItem& getUser(const MyString& username);


	//basic functions for files
	void open(const MyString& path);
	void close();
	void exit();
	void save();
	void saveAs(const MyString& givenPath);
	void help();

	//functions with library
	void all();
	void info(int isbn); //function equals to "view" function
	void find(const MyString& option, const MyString& input);
	void sort(const MyString& option, const MyString& input);
	void addBook(
		const MyString& author,
		const MyString& title,
		const MyString& genre,
		const MyString& shortDescription,
		int yearOfPublishing,
		const MyVector<MyString> keyWords,
		int rating,
		int isbn);

	void removeBook(const MyString& author,
		const MyString& title,
		const MyString& genre,
		const MyString& shortDescription,
		int yearOfPublishing,
		const MyVector<MyString> keyWords,
		int rating,
		int isbn);

	//functions with users
	void login(const MyString& username);
	void logout(const MyString& username);
	void addUser(const MyString& userName, const MyString& password, int accessLevel = e_USER);
	void removeUser(const MyString& userName);
private:
	//helper functions
	bool checkIfFileExist(const MyString& path);
	MyString convertStreamToString(ifstream& in);

};

#endif // !_FILE_MANAGER_
