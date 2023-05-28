#include"UserController.h"
#include <iostream>
using std::cerr;
using std::cout;
using std::cin;
using std::endl;


MyVector<UserControllerItem>& UserController::getUsers()
{
	return _users;
}

const MyVector<UserControllerItem>& UserController::getUsers() const
{
	return _users;
}

UserControllerItem& UserController::getUser(const MyString& user)
{
	int index = getUserIndex(user);
	if (index>=0)
	{
		return _users[index];
	}
	throw std::exception("User doesn't exist in the current list\n");
}

UserController& UserController::getInstance()
{
	static UserController obj;
	return obj;
}

int UserController::getUserIndex(const MyString& username)
{
	for (size_t i = 0; i < _users.getSize() ; i++)
	{
		if (_users[i].getUsername() == username)
		{
			return i;
		}
	}
	return -1;
}


void UserController::login(const MyString& username)
{
	int index = getUserIndex(username);
	if (index >= 0)
	{
		UserControllerItem& user = _users[index];

		cout << "Enter " << user << "'s password:  ";
		MyString enteredPassword;
		cin >> enteredPassword;

		do
		{
			if (enteredPassword != user.getPassword())
			{
				cout << "Wrong password\n" << "Enter " << user << "'s password:  ";
				cin >> enteredPassword;
			}
			else
			{
				cout << "Welcome " << user << endl;
				user.logUser();
			}

		} while (!user.getLoginStatus());
	}
	else
	{
		cerr << "User not found\n";
	}
}

void UserController::logout(const MyString& username)
{
	int index = getUserIndex(username);
	if (index >= 0)
	{
		UserControllerItem& user = _users[index];

		if (!user.getLoginStatus())
		{
			cout << user << " is already logged out\n";
		}
		else
		{
			user.logoutUser();
			cout << "Have a good day " << user << endl;
		}
	}
	else
	{
		cerr << "User not found\n";
	}
}

void UserController::addUser(const MyString& userName, const MyString& password, int accessLevel)
{
	if (checkIfUserAlreadyExist(userName))
	{
		cerr << "User with this username already exist\n";
		return;
	}

	UserControllerItem newUser(userName, password, accessLevel);
	_users.push(newUser);

	cout << "User: " << userName << " successfully added\n";
}

void UserController::removeUser(const MyString& userName)
{
	int index = getUserIndex(userName);
	_users.removeAt(index);
}

bool UserController::checkIfUserAlreadyExist(const MyString& userName)
{
	if (getUserIndex(userName) == -1)
	{
		return false;
	}
	return true;
}