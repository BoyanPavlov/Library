#include "UserControllerItem.h"

#ifndef _USER_CONTROLLER_
#define _USER_CONTROLLER_

const int INITIAL_SIZE = 10;

class UserController
{
private:

	UserControllerItem** _users;
	int _size;
	int _capacity;

	UserControllerItem** allocateUsers(int size);
	void freeUsersMem();
	void resizeUsersArr();

	UserController();

public:
	int getUserIndex(const MyString& userName);
	bool checkIfUserAlreadyExist(const MyString& userName);

	static UserController& getInstance();

	UserController(const UserController&) = delete;
	UserController& operator=(const UserController&) = delete;
	~UserController();

	void login(const MyString& user);
	void logout(const MyString& user);

	void addUser(const MyString& userName, const MyString& password, int accessLevel = e_USER);
	void removeUser(const MyString& userName);
};
#endif // !_USER_CONTROLLER_
