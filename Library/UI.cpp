#include "UI.h"



int UI::entrance()
{
	MyString line = "=============================\n";
	cout << line;

	size_t choice = 0;

	cout << "OPEN:   to open a file where you have a library enter: "
		<< e_OPEN << endl

		<< "EXIT:   to exit the program enter: "
		<< e_EXIT << endl

		<< "HELP: to Print the current options enter: "
		<< e_HELP << endl;
	//=======================================================
	cout << "ALL: to print all books from the current collection, enter: "
		<< e_BOOKS_ALL << endl

		<< "ADD BOOK: to add new book, enter: "
		<< e_BOOKS_ADD << endl;

	//=======================================================

	cout << "LOGIN: to login user/admin, but first you need to logout or the system will do it automaticly"
		"... enter: "
		<< e_USER_LOGIN << endl

		<< "LOGOUT: you know what this means, enter: "
		<< e_USER_LOGOUT << endl

		<< "ADD USER: this is available only for admins, enter: "
		<< e_USER_ADD << endl

		<< "REMOVE USER: this is available only for admins, enter: " << e_USER_REMOVE << endl;
	//=======================================================
	cout << "Enter your choice: ";
	cin >> choice;
	cout << line;

	while (
		choice != e_OPEN &&
		choice != e_CLOSE &&
		choice != e_HELP &&
		choice != e_EXIT &&
		choice != e_BOOKS_ALL &&
		choice != e_BOOKS_ADD &&
		choice != e_USER_LOGIN &&
		choice != e_USER_LOGOUT &&
		choice != e_USER_ADD &&
		choice != e_USER_REMOVE)
	{
		cout << "Invalid input, try again\n";
		cin >> choice;
	}
	return choice;
}

void UI::openChosen()
{
	cout << "You have chosen: OPEN \nPlease enter path: ";
	MyString path;
	cin >> path;
	_instanceFileManager.open(path);
}

int UI::enterChoise()
{
	MyString line = "=============================\n";
	cout << line;

	size_t choice = 0;

	cout << "EXIT:   to exit the program enter: "
		<< e_EXIT << endl

		<< "SAVE:   to save current changes in file enter: "
		<< e_SAVE << endl

		<< "SAVE AS:  to save the Library in a new file with chosen name by you, enter: "
		<< e_SAVE_AS << endl

		<< "HELP: to Print the current options again: "
		<< e_HELP << endl;
	//=======================================================
	cout << "ALL: to print all books from the current collection, enter: "
		<< e_BOOKS_ALL << endl

		<< "INFO: to get all of the info for a book with specified ISBN, enter"
		<< e_BOOKS_INFO << endl

		<< "FIND: to find a book in a collection, enter: "
		<< e_BOOKS_FIND << endl

		<< "SORT: to sort the collection, enter: "
		<< e_BOOKS_SORT << endl

		<< "ADD BOOK: to add new book, enter: "
		<< e_BOOKS_ADD << endl

		<< "REMOVE BOOK: to remove book, enter:"
		<< e_BOOKS_REMOVE << endl;
	//=======================================================

	cout << "LOGIN: to login user/admin, but first you need to logout or the system will do it automaticly"
		"... enter: "
		<< e_USER_LOGIN << endl

		<< "LOGOUT: you know what this means, enter: "
		<< e_USER_LOGOUT << endl

		<< "ADD USER: this is available only for admins, enter: "
		<< e_USER_ADD << endl

		<< "REMOVE USER: this is available only for admins, enter: " << e_USER_REMOVE << endl;
	//=======================================================

	cin >> choice;

	while (
		choice != e_CLOSE &&
		choice != e_SAVE &&
		choice != e_SAVE_AS &&
		choice != e_HELP &&
		choice != e_EXIT &&
		choice != e_BOOKS_ALL &&
		choice != e_BOOKS_INFO &&
		choice != e_BOOKS_FIND &&
		choice != e_BOOKS_SORT &&
		choice != e_BOOKS_ADD &&
		choice != e_BOOKS_REMOVE &&
		choice != e_USER_LOGIN &&
		choice != e_USER_LOGOUT &&
		choice != e_USER_ADD &&
		choice != e_USER_REMOVE)
	{
		cout << "Invalid input, try again\n";
		cin >> choice;
	}
	return choice;
}

MyString UI::getOpitionForFINDfunction()
{
	MyString author = "author";
	MyString title = "title";
	MyString genre = "genre";

	cout << "You have chosen: BOOK FIND, please enter option\n"
		<< "For AUTHOR, enter 1"
		<< "For TITLE, enter 2"
		<< "For GENRE, enter 3\n";
	int choice = 0;
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3)
	{
		cout << "Invalid input, try again\n";
		cin >> choice;
	}

	if (choice == 1)
	{
		return author;
	}
	else if (choice == 2)
	{
		return title;
	}
	return genre;
}

MyString UI::getOpitionForSortfunction()
{
	MyString author = "author";
	MyString title = "title";
	MyString year = "year";
	MyString rating = "rating";

	cout << "You have chosen: BOOK SORT, please enter option\n"
		<< "For AUTHOR, enter 1\n"
		<< "For TITLE, enter 2\n"
		<< "For YEAR of publishing, enter 3\n"
		<< "For RATING, enter 4\n";
	int choice = 0;
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
	{
		cout << "Invalid input, try again\n";
		cin >> choice;
	}

	if (choice == 1)
	{
		return author;
	}
	else if (choice == 2)
	{
		return title;
	}
	return rating;
}

MyString UI::choseACSorDECS()
{
	cout << "Hello, you have to chose - ACSENDING or DECSENDING\n"
		<< "Please enter 1 for ACSENDING\n"
		<< "Please enter 2 for DECSENDING\n";
	int choice = 0;
	MyString acs = "acs";
	MyString decs = "decs";
	while (choice != 1 && choice != 2)
	{
		cout << "Invalid input, try again\n";
		cin >> choice;
	}

	if (choice == 1)
	{
		return acs;
	}
	return decs;
}

MyString UI::readUsername()
{
	cout << "You have chosen LOGIN, please enter username: ";
	MyString username;
	cin >> username;
	return username;
}

void UI::start()
{
	bool isFileSaved = false;
	bool opened = false;
	bool alreadyEntered = false;

	int currentchoice = 0;
	int choice = e_UNKNOWN;
	MyString path;

	do
	{
		if (!alreadyEntered)
		{
			choice = entrance();
			alreadyEntered = true;

			if (choice == e_EXIT || choice == e_CLOSE)
			{
				_instanceFileManager.exit();
				return;
			}
		}

		if (choice == e_OPEN)
		{
			openChosen();
			opened = true;
		}

		if (choice == e_SAVE)
		{
			_instanceFileManager.save();
			isFileSaved = true;
		}

		if (choice == e_SAVE_AS)
		{

			cout << "You have chosen: SAVE AS\nPlease enter path or name of the new file:\n";
			cin >> path;

			_instanceFileManager.saveAs(path);
			isFileSaved = true;
		}

		if (choice == e_HELP && !opened)
		{
			choice = entrance();
		}

		if ((choice == e_EXIT || choice == e_CLOSE) && opened)
		{
			if (isFileSaved)
			{
				_instanceFileManager.close();
				return;
			}
			cout << "\nDo you want to save changes or save in new file\n";
			cout << "To save in new file enter: " << e_SAVE_AS << endl;
			cout << "To save: " << e_SAVE << endl;
			cout << " If you don't want to - enter another number \n";
			cin >> currentchoice;
			if (currentchoice == e_SAVE)
			{
				choice = e_SAVE;
			}
			else if (currentchoice == e_SAVE_AS)
			{
				choice = e_SAVE_AS;
			}
			else
			{
				_instanceFileManager.close();
				return;
			}
		}

		if (choice == e_BOOKS_ALL)
		{
			_instanceFileManager.all();
		}

		if (choice == e_BOOKS_INFO)
		{
			cout << "Please enter ISBN of the book to be searched for:\n";
			int ISBN;
			cin >> ISBN;
			_instanceFileManager.info(ISBN);
		}

		if (choice == e_BOOKS_FIND)
		{
			MyString option = getOpitionForFINDfunction();
			MyString input;
			cout << "Enter input to be searched\n";
			cin >> input;
			_instanceFileManager.find(option, input);
		}

		if (choice == e_BOOKS_SORT && _instanceFileManager.getCurrentUser().getAccessLevel() == e_ADMIN)
		{
			isFileSaved = false;
			_instanceFileManager.sort(getOpitionForSortfunction(), choseACSorDECS());
		}

		if (choice == e_BOOKS_ADD && _instanceFileManager.getCurrentUser().getAccessLevel() == e_ADMIN)
		{
			isFileSaved = false;
			MyString author;
			MyString title;
			MyString genre;
			MyString shortDescription;
			int yearOfPublishing = 0;
			MyVector<MyString> keyWords;
			int rating = 0;
			int isbn = 0;

			cout << "Hello, you have chosen BOOK ADD\n"
				<< "Please enter:\n";

			cout << "author: ";
			cin >> author;

			cout << "title: ";
			cin >> title;

			cout << "genre: ";
			cin >> genre;

			cout << "Short Description: ";
			cin >> shortDescription;

			cout << "yearOfPublishing: ";
			cin >> yearOfPublishing;

			cout << "Number of keywords: ";
			int numberOfKeywords = 0;
			cin >> numberOfKeywords;

			cout << "keywords: ";
			MyString temp;
			for (size_t i = 0; i < numberOfKeywords; i++)
			{
				cin >> temp;
				keyWords.push(temp);
			}

			cout << "Rating: ";
			cin >> rating;

			cout << "ISBN: ";
			cin >> isbn;

			_instanceFileManager.addBook(author, title, genre, shortDescription, yearOfPublishing, keyWords, rating, isbn);
		}

		if (choice == e_BOOKS_REMOVE && _instanceFileManager.getCurrentUser().getAccessLevel() == e_ADMIN)
		{
			isFileSaved = false;
			MyString author;
			MyString title;
			MyString genre;
			MyString shortDescription;
			int yearOfPublishing = 0;
			MyVector<MyString> keyWords;
			int rating = 0;
			int isbn = 0;

			cout << "Hello, you have chosen BOOK REMOVE\n"
				<< "Please enter:\n";

			cout << "author: ";
			cin >> author;

			cout << "title: ";
			cin >> title;

			cout << "genre: ";
			cin >> genre;

			cout << "Short Description: ";
			cin >> shortDescription;

			cout << "yearOfPublishing: ";
			cin >> yearOfPublishing;

			cout << "Number of keywords: ";
			int numberOfKeywords = 0;
			cin >> numberOfKeywords;

			cout << "keywords: ";
			MyString temp;
			for (size_t i = 0; i < numberOfKeywords; i++)
			{
				cin >> temp;
				keyWords.push(temp);
			}

			cout << "Rating: ";
			cin >> rating;

			cout << "ISBN: ";
			cin >> isbn;

			_instanceFileManager.removeBook(author, title, genre, shortDescription, yearOfPublishing, keyWords, rating, isbn);
		}

		if (choice == e_USER_LOGIN)
		{
			MyString newCurrentUser = readUsername();
			_instanceFileManager.login(newCurrentUser);
			cout << "current user has been logged out\n";
			_instanceFileManager.getCurrentUser().logoutUser();
			_instanceFileManager.setCurrentUser(_instanceFileManager.getUser(newCurrentUser));
		}

		if (choice == e_USER_LOGOUT)
		{
			_instanceFileManager.logout(_instanceFileManager.getCurrentUser().getUsername());
		}

		if (choice == e_USER_ADD && _instanceFileManager.getCurrentUser().getAccessLevel() == e_ADMIN)
		{
			cout << "Hello, you have chosen to add new user\n";
			cout << "Please enter username and password \n";
			MyString username;
			MyString password;
			int accesslvl = 0;
			cin >> username;
			cin.ignore();
			cin >> password;
			cin.ignore();
			cout << "Please enter accesslvl, chose 1 for admin and 2 for user\n";
			cin >> accesslvl;


			while (accesslvl != 1 && accesslvl != 2)
			{
				cout << "invalid input, try again\n";
				cin >> accesslvl;
			}

			if (accesslvl == 1)
			{
				accesslvl = e_ADMIN;
			}
			else
			{
				accesslvl = e_USER;
			}

			_instanceFileManager.addUser(username, password, accesslvl);
		}

		if (choice == e_USER_REMOVE && _instanceFileManager.getCurrentUser().getAccessLevel() == e_ADMIN)
		{
			cout << "Hello, you have chosen to remove a user\n";
			cout << "Please enter username\n";
			MyString username;
			cin >> username;
			_instanceFileManager.removeUser(username);
		}

		choice = !opened ? entrance() : enterChoise();

	} while (choice != e_EXIT);
}