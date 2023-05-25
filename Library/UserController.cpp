#include"UserController.h"
#include <iostream>
using std::cerr;
using std::cout;
using std::cin;
using std::endl;

//to test this one
UserControllerItem** UserController::allocateUsers(int size)
{
	UserControllerItem** tmp = nullptr;
	try
	{
		tmp = new UserControllerItem * [size]();
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
		delete[] tmp;
	}
	return tmp;
}

UserController::UserController()
	:_size(0), _capacity(INITIAL_SIZE), _users(nullptr)
{
	_users = allocateUsers(INITIAL_SIZE);
}

void UserController::freeUsersMem()
{
	for (size_t i = 0; i < _capacity; i++)
	{
		delete _users[i];
	}
	delete[] _users;
	_users = nullptr;
}

void UserController::resizeUsersArr()
{
	_capacity *= 2;
	UserControllerItem** tmp = allocateUsers(_capacity);
	for (size_t i = 0; i < _size; i++)
	{
		//shallow copy
		tmp[i] = _users[i];
	}
	//deleting the arr pointer
	delete[] _users;
	_users = tmp;
}


int UserController::getUserIndex(const MyString& userName)
{
	for (size_t i = 0; i < _size; i++)
	{
		if (_users[i]->getUsername() == userName)
		{
			return i;
		}
	}
	return -1;
}


UserController& UserController::getInstance()
{
	static UserController obj;
	return obj;
}

UserController::~UserController()
{
	freeUsersMem();
}

void UserController::login(const MyString& username)
{
	int index = getUserIndex(username);
	if (index >= 0)
	{
		UserControllerItem& user = *_users[index];

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
		UserControllerItem& user = *_users[index];

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

	try
	{
		UserControllerItem* newUser = new UserControllerItem(userName, password, accessLevel);
		if (_size == _capacity)
		{
			resizeUsersArr();
		}
		_users[_size++] = newUser;
	}
	catch (const std::exception& e)
	{
		//TODO
		cerr << e.what() << endl;
		freeUsersMem();
	}

	cout << "User: " << userName << " successfully added\n";
}

void UserController::removeUser(const MyString& userName)
{
	int index = getUserIndex(userName);
	if (index >= 0)
	{
		std::swap(_users[index], _users[_size]);
		delete _users[_size--];
	}
}

bool UserController::checkIfUserAlreadyExist(const MyString& userName)
{
	if (getUserIndex(userName) == -1)
	{
		return false;
	}
	return true;
}