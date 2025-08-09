#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#include <cstddef>

class MyString
{
    public:
        MyString(const char *str); // Default constructor
        MyString(const MyString& other);
        MyString& operator=(const MyString& other); // Copy assignment
        ~MyString(); // Destructor

        size_t length() const;
        char *c_str() const;
        void append(MyString str);
        int compare(const MyString& s1) const;
    private:
        char *_data;
        size_t _length;
};

#endif
