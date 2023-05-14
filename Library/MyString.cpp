#include "MyString.h"
#include "StringUtils.h"


char* MyString::allocateString(size_t len)
{
	char* tmp = nullptr;
	try
	{
		tmp = new char[len + 1]();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw;
	}
	return tmp;
}


void MyString::freeMem()
{
	delete[] _str;
	_str = nullptr;
}

void MyString::resize()
{
	_capacity *= 2;
	try
	{
		char* buffer = allocateString(_capacity);
		StringUtils::strCpy(buffer, _str);
		freeMem();
		_str = buffer;

	}
	catch (...)
	{
		std::cerr << "String wasn't resized\n";
	}
}


MyString::MyString()
	: _str(nullptr), _size(0), _capacity(0)
{
}

MyString::MyString(const MyString& other)
	: _str(nullptr), _capacity(other._size), _size(other._size)
{
	if (other._str)
	{
		try
		{
			_str = allocateString(_size);
			StringUtils::strCpy(_str, other._str);
		}
		catch (...)
		{
			freeMem();
		}
	}
}

MyString& MyString::operator=(const MyString& other)
{
	freeMem();
	_capacity = other._size;
	_size = other._size;

	try
	{
		_str = allocateString(_size);
		StringUtils::strCpy(_str, other._str);
	}
	catch (...)
	{
		freeMem();
	}
	return *this;
}

MyString::~MyString()
{
	freeMem();
}


MyString::MyString(MyString&& obj)
	:_str(nullptr), _size(0), _capacity(0)
{
	std::swap(_str, obj._str);
	std::swap(_capacity, obj._capacity);
	std::swap(_size, obj._capacity);
}

MyString& MyString::operator=(MyString&& obj)
{
	freeMem();
	std::swap(_str, obj._str);
	std::swap(_capacity, obj._capacity);
	std::swap(_size, obj._capacity);
}


MyString::MyString(const char* text)
	: _str(nullptr), _capacity(0), _size(0)
{
	if (text)
	{
		_size = StringUtils::strLen(text);
		_capacity = _size;
		try
		{
			_str = allocateString(_size);
			StringUtils::strCpy(_str, text);
		}
		catch (...)
		{
			std::cerr << "Couldn't copy string\n";
		}
	}
}

MyString& MyString::operator+=(const char& letter)
{
	if (_size == _capacity)
	{
		resize();
	}
	push_back(letter);
	return *this;
}

MyString& MyString::operator+=(const MyString& rhs)
{
	while (_capacity < _size + rhs._size)
	{
		resize();
	}

	for (size_t i = 0; i < rhs._size; i++)
	{
		_str[_size++] = rhs[i];
	}

	return *this;
}

bool MyString::operator==(const MyString& rhs) const
{
	if (!(StringUtils::strCmp(_str, rhs._str)))
	{
		return true;
	}
	return false;
}


char& MyString::at(size_t pos)
{
	if (pos < 0 || pos >= _size)
	{
		throw std::invalid_argument("Out of range");
	}
	return _str[pos];
}

const char& MyString::at(size_t pos) const
{
	if (pos < 0 || pos >= _size)
	{
		throw std::invalid_argument("Out of range");
	}
	return _str[pos];
}

char& MyString::operator[](size_t pos)
{
	if (pos < 0 || pos >= _size)
	{
		return _str[_size];
	}
	return _str[pos];
}

const char& MyString::operator[](size_t pos) const
{
	if (pos < 0 || pos >= _size)
	{
		return _str[_size];
	}
	return _str[pos];
}


char& MyString::front()
{
	if (!_size)
	{
		throw std::invalid_argument("empty string\n");
	}
	return _str[0];
}

const char& MyString::front() const
{
	if (!_size)
	{
		throw std::invalid_argument("empty string\n");
	}
	return _str[0];
}

char& MyString::back()
{
	if (!_size)
	{
		throw std::invalid_argument("empty string\n");
	}
	return _str[_size - 1];
}

const char& MyString::back() const
{
	if (!_size)
	{
		throw std::invalid_argument("empty string\n");
	}
	return _str[_size - 1];
}

bool MyString::empty() const
{
	if (!_size)
	{
		return true;
	}
	return false;
}

void MyString::clear()
{
	freeMem();
	_str = allocateString(_size);
}

void MyString::push_back(char c)
{
	if (_size == _capacity)
	{
		resize();
	}
	_str[_size++] = c;
}


void MyString::pop_back()
{
	_str[--_size] = '\0';
}
const char* MyString::c_str() const
{
	return _str;
}

size_t MyString::size() const
{
	return _size;
}

int MyString::find(char c) const
{
	for (size_t i = 0; i < _size; i++)
	{
		if (_str[i] == c)
		{
			return i;
		}
	}
	return -1;
}

int MyString::find_the_first_c(char c) const
{
	return find(c);
}

int MyString::find_the_last_c(char c) const
{
	for (int i = _size - 1; i > 0; i--)
	{
		if (_str[i] == c)
		{
			return i;
		}
	}
	return -1;
}

std::ostream& operator<<(std::ostream& out, const MyString& obj)
{
	out << obj._str;
}

std::istream& operator>>(std::istream& in, MyString& obj)
{
	char tmp[1000] = {};
	in >> tmp;
	MyString tmpObj(tmp);
	obj = tmp;
}