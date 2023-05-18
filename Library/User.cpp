#include "User.h"

User::User(const MyString& username, const MyString& password, int accessLevel)
    : _username(username), _password(password), _accessLevel(accessLevel)
{
}

const MyString& User::getUsername() const
{
    return _username;
}

const MyString& User::getPassword() const
{
    return _password;
}

int User::getAccessLevel() const
{
    return _accessLevel;
}

void User::setUsername(const MyString& username)
{
    _username = username;
}

void User::setPassword(const MyString& password)
{
    _password = password;
}

void User::setAccessLevel(int accessLevel)
{
    _accessLevel = accessLevel;
}