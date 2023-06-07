#include "UserControllerItem.h"

UserControllerItem::UserControllerItem(const MyString& username, const MyString& password, int accessLevel)
	: User(username, password, accessLevel), _isLogged(false)
{
}

void UserControllerItem::logUser()
{
	_isLogged = true;
}
void UserControllerItem::logoutUser()
{
	_isLogged = false;
}

std::ostream& operator<<(std::ostream& out, const UserControllerItem& obj)
{
	out << obj.getUsername();
	return out;
}

bool UserControllerItem::getLoginStatus() const
{
	return _isLogged;
}