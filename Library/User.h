#pragma once
#ifndef _USER_
#define _USER_

#include "MyString.h"

enum e_UserAccessLevel
{
    e_ADMIN,
    e_USER,
    e_UNDEFINED,
};

class User
{
protected:
    MyString _username;      // User's username
    MyString _password;      // User's password
    int _accessLevel;        // User's access level (e_ADMIN or e_USER)

public:
    User() :_accessLevel(e_UNDEFINED) {}
    User(const MyString& username, const MyString& password, int accessLevel); // Constructor

    const MyString& getUsername() const;    // Getter for retrieving the username
    const MyString& getPassword() const;    // Getter for retrieving the password
    int getAccessLevel() const;              // Getter for retrieving the access level

    void setUsername(const MyString& username);    // Setter for updating the username
    void setPassword(const MyString& password);    // Setter for updating the password
    void setAccessLevel(int accessLevel);          // Setter for updating the access level
};

#endif // !_USER_
