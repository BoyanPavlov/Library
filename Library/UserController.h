#include "UserControllerItem.h"
#include "MyVector.hpp"

#ifndef _USER_CONTROLLER_
#define _USER_CONTROLLER_

const int INITIAL_SIZE = 10;

class UserController
{
private:
	MyVector<UserControllerItem> _users;

	UserController() = default;
public:
	bool checkIfUserAlreadyExist(const MyString& userName);
	int getUserIndex(const MyString& username);

	MyVector<UserControllerItem>& getUsers();
	const MyVector<UserControllerItem>& getUsers() const;

	UserControllerItem& getUser(const MyString& user);

	static UserController& getInstance();

	UserController(const UserController&) = delete;
	UserController& operator=(const UserController&) = delete;

	void login(const MyString& user);
	void logout(const MyString& user);

	void addUser(const MyString& userName, const MyString& password, int accessLevel = e_USER);
	void removeUser(const MyString& userName);
};
#endif // !_USER_CONTROLLER_
