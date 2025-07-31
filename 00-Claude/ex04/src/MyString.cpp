#include "MyString.hpp"
#include <iostream>
#include <cstring>

MyString::MyString(const char *str)
{
    std::cout << "MyString Default constructor called" << std::endl;
    if (str)
    {
        _data = new char[std::strlen(str) + 1];
        std::strcpy(_data, str);
        _length = std::strlen(_data);
    }
    else
    {
        _data = new char[1];
        _data[0] = '\0';
    }
}

MyString::MyString(const MyString& other)
{
    std::cout << "MyString Copy constructor called" << std::endl;
    _length = other._length;
    _data = new char[_length + 1];
    std::strcpy(_data, other._data);
}

MyString& MyString::operator=(const MyString& other)
{
    std::cout << "MyString Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        if (this->_data)
            delete this->_data;
        this->_data = new char[std::strlen(other._data) + 1];
        std::strcpy(this->_data, other._data);
    }
    return *this;
}

MyString::~MyString()
{
    std::cout << "MyString Destructor called" << std::endl;
    delete[] _data;
}

size_t MyString::length() const
{
    size_t i;

    i = 0;
    while (_data[i])
    {
        i++;
    }
    return i; 
}

char * MyString::c_str() const
{
    return _data;
}

void MyString::append(MyString str)
{
    int i;
    int j;
    char *data;

    if (!str._data)
        return ;
    i = 0;
    while (str._data[i]) 
        i++;
    data = new char[this->_length + i + 1];
    i = 0;
    while (this->_data[i])
    {
        data[i] = this->_data[i];
        i++;
    }
    j = 0;
    while (str._data[j])
    {
        data[i] = str._data[j];
        j++;
        i++;
    }
    data[i] = '\0';
    delete _data;
    this->_data = data;
    this->_length = i;
}

int MyString::compare(const MyString& s1) const
{
    int i = 0;
    while (this->_data[i] && s1._data[i])
    {
        if (this->_data[i] != s1._data[i])
            return (this->_data[i] - s1._data[i]);
        i++;
    }
    return this->_data[i] - s1._data[i];
}

