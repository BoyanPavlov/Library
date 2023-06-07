#include "FileManager.h"

FileManager::FileManager()
	: _isFileSaved(true)
{
	_instanceUserController.addUser("admin", "i<3c++", e_ADMIN);
	_currentUser = &_instanceUserController.getUser("admin");
	_currentUser->logUser();
}


void FileManager::setCurrentUser(UserControllerItem& currentUser)
{
	_currentUser = &currentUser;
}

UserControllerItem& FileManager::getCurrentUser() const
{
	return *_currentUser;
}

UserControllerItem& FileManager::getUser(const MyString& username)
{
	return _instanceUserController.getUser(username);
}

//basic functions for files
void FileManager::open(const MyString& path)
{
	if (checkIfFileExist(path))
	{
		std::ifstream in(path.c_str(), std::ios::in);
		if (!in.is_open())
		{
			cerr<<"Couldn't open file\n";
			return;
		}
		MyString buffer = convertStreamToString(in);
		cout << "File has opened successfully!\n";
		cout << "...\n";
		cout << "Loading elements\n";

		try
		{
			_instanceLibraryController.loadLibrary(buffer);
		}
		catch (const std::exception& e)
		{
			cerr << e.what();
			in.close();
			return;
		}

		cout << "...\n";
		cout << "Loaded succesfully\n";
		_isFileSaved = false;

		in.close();
	}
}

void FileManager::close()
{
	cout << "Program's closing! Have a good day ...\n";
}

void FileManager::exit()
{
	close();
}

void FileManager::save()
{
	ofstream out(_path.c_str(), std::ios::out | std::ios::trunc);
	out << _instanceLibraryController;
	if (!out.is_open())
	{
		cout << "Problem with saving the library\n";
		return;
	}
	cout << "Changes saved successfully\n";
	out.close();
}

void FileManager::saveAs(const MyString& givenPath)
{
	ofstream out(givenPath.c_str(), std::ios::out | std::ios::trunc);
	out << _instanceLibraryController;
	if (!out.is_open())
	{
		cout << "Problem with saving the library\n";
		return;
	}
	cout << "File saved successfully\n";
	out.close();
}

void FileManager::help()
{
	cout << "Hello, " << _currentUser->getUsername() << endl;
	cout << "Your current options are\n";

	cout<<"See all the books with the command: all\n"
		<< "Get info for a book with entered ISBN command: info <ISBN>\n"
		<< "Find a book by genre, title or author command: <OPTION> <INPUT>\n"
		<< "Sort all the books command: <OPTION> <ACS/DECS>"
		<< "Login another user, but before that you have to logout\n"
		<< "You can logout, command: logout\n";

	if (_currentUser->getAccessLevel() == e_ADMIN)
	{
		cout << "Add new user, command: users add <username, passowrd, accesslvl>\n"
			<< "Remove user: users remove <username>\n"
			<< "Add new book, command: book add <username, passowrd, accesslvl>\n"
			<< "Remove book: book remove <author, title, genre, shortDescription, yearOfPublishing, keywords, rating, ISBN>\n";
	}
}

//functions with library

void FileManager::all()
{
	_instanceLibraryController.printAll();
}

void FileManager::info(int isbn)
{
	_instanceLibraryController.bookInfo(isbn);
}

void FileManager::find(const MyString& option, const MyString& input)
{
	_instanceLibraryController.findBook(option, input);
}

void FileManager::sort(const MyString& option, const MyString& input)
{
	_instanceLibraryController.sortBook(option, input);
}

void FileManager::addBook(
	const MyString& author,
	const MyString& title,
	const MyString& genre,
	const MyString& shortDescription,
	int yearOfPublishing,
	const MyVector<MyString> keyWords,
	int rating,
	int isbn)
{
	Book book(author, title, genre, shortDescription, yearOfPublishing, keyWords, rating, isbn);
	_instanceLibraryController.addBook(book);
}

void FileManager::removeBook(const MyString& author,
	const MyString& title,
	const MyString& genre,
	const MyString& shortDescription,
	int yearOfPublishing,
	const MyVector<MyString> keyWords,
	int rating,
	int isbn)
{
	Book book(author, title, genre, shortDescription, yearOfPublishing, keyWords, rating, isbn);
	_instanceLibraryController.removeBook(book);
}

//functions with users
void FileManager::login(const MyString& username)
{
	_instanceUserController.login(username);
}

void FileManager::logout(const MyString& username)
{
	_instanceUserController.logout(username);
}

void FileManager::addUser(const MyString& userName, const MyString& password, int accessLevel)
{
	_instanceUserController.addUser(userName, password, accessLevel);
}

void FileManager::removeUser(const MyString& userName)
{
	if (_currentUser->getAccessLevel() == e_ADMIN)
	{
		_instanceUserController.removeUser(userName);
		
	}
	else
	{
		cout << "Sorry users don't have such permissions\n";
	}
}


bool FileManager::checkIfFileExist(const MyString& path)
{
	std::ifstream in(path.c_str(), std::ios::in);
	if (!in)
	{
		in.close();
		return false;
	}
	in.close();
	return true;
}

MyString FileManager::convertStreamToString(ifstream& in)
{
	char c;
	MyString buffer;
	while (!in.eof())
	{
		in.get(c);
		buffer += c;
	}
	return buffer;
}
