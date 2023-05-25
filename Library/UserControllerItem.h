#include "User.h"
#include "MyString.h"
#include <iostream>

#ifndef _USER_CONTROLLER_ITEM_
#define _USER_CONTROLLER_ITEM_

class UserControllerItem : public User
{
private:
	bool _isLogged;
public:
	UserControllerItem(const MyString& username, const MyString& password, int accessLevel);

	void logUser();
	void logoutUser();
	bool getLoginStatus() const;

	friend std::ostream& operator<<(std::ostream& out, const UserControllerItem& obj);
};

#endif // !_USER_CONTROLLER_ITEM_
