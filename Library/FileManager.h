#pragma once

#include"MyString.h"

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
    e_BOOOKS_FIND,
    e_BOOKS_SORT,
    //user commands
    e_USER_LOGIN,
    e_USER_LOGOUT,
    e_USER_ADD,
    e_USER_REMOVE
};


#ifndef _FILE_MANAGER_
#define _FILE_MANAGER_

class IFileManager
{
protected:
	MyString path;
public:
	virtual IFileManager* open() = 0;
	virtual void save() = 0;
	virtual void saveAs(const MyString &givenPath) = 0;
};

#endif // !_FILE_MANAGER_


