#include <iostream>
#include <cstring>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;
}

// Move constructor
Mystring::Mystring(Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring()
{
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs)
{
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=(Mystring &&rhs) 
{
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

Mystring Mystring::operator-(const Mystring &rhs)
{
    char *buff = new char[std::strlen(rhs.get_str()) + 1];
    std::strcpy(buff, rhs.get_str());
    for (size_t i = 0; i < std::strlen(buff); ++i)
        buff[i] = tolower(buff[i]);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

Mystring Mystring::operator+(const Mystring &rhs)
{
    if (this->get_length() == 0)
    {
        char *buff = new char[rhs.get_length() + 1];
        std::strcpy(buff, rhs.get_str());
        Mystring temp = {buff};
        delete [] buff;
        return temp;
    }
    char *buff = new char[this->get_length() + rhs.get_length() + 1];
    std::strcpy(buff, this->get_str());
    std::strcat(buff, rhs.get_str());
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

Mystring &Mystring::operator+=(const Mystring &rhs)
{
    if (this->get_length() == 0)
    {
        char *buff = new char[rhs.get_length()];
        std::strcpy(buff, rhs.get_str());
        Mystring temp = {buff};
        delete [] buff;
        return temp;
    }
    char *buff = new char[this->get_length() + rhs.get_length() + 1];
    std::strcpy(buff, this->get_str());
    std::strcat(buff, rhs.get_str());
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

bool Mystring::operator==(const Mystring &rhs)
{
    if (this->get_length() != rhs.get_length())
        return false;
    else
    {
        for (size_t i = 0; i < rhs.get_length(); ++i)
            if (this->get_str()[i] != rhs.get_str()[i])
                return false;
    }
    return true;
}

bool Mystring::operator!=(const Mystring &rhs)
{
    if (this->get_length() != rhs.get_length())
        return true;
    else
        for (size_t i = 0; i < rhs.get_length(); ++i)
            if (this->get_str()[i] != rhs.get_str()[i])
                return true;
    return false;  
}

bool Mystring::operator<(const Mystring &rhs)
{
    for (size_t i = 0; i < rhs.get_length(); ++i)
        if (tolower(this->get_str()[i]) < tolower(rhs.get_str()[i]))
            return true;
    return false;
}

bool Mystring::operator>(const Mystring &rhs)
{
    for (size_t i = 0; i < rhs.get_length(); ++i)
        if (tolower(this->get_str()[i]) > tolower(rhs.get_str()[i]))
            return true;
    return false;
}

Mystring Mystring::operator*(size_t multiplier)
{
    if (multiplier <= 0)
    {
        char *buff = new char;
        Mystring temp {buff};
        delete [] buff;
        return temp;
    }
    char *buff = new char[(this->get_length() * multiplier) + 1];
    std::strcpy(buff, this->get_str());
    for (size_t i = 1; i < multiplier; ++i)
        std::strcat(buff, this->get_str());
    Mystring temp {buff};
    delete [] buff;
    return temp;    
}

Mystring &Mystring::operator*=(size_t multiplier)
{
    if (multiplier <= 0)
    {
        char *buff = new char;
        Mystring temp {buff};
        delete [] buff;
        return temp;
    }
    char *buff = new char[(this->get_length() * multiplier) + 1];
    std::strcpy(buff, this->get_str());
    for (size_t i = 1; i < multiplier; ++i)
        std::strcat(buff, this->get_str());
    Mystring temp {buff};
    delete [] buff;
    return temp; 
}

// Display method
void Mystring::display() const 
{
    std::cout << str << " : " << get_length() << std::endl;
}

// getters
int Mystring::get_length() const { return strlen(str); }
const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

