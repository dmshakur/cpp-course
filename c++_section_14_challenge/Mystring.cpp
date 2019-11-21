#include <iostream>
#include <cstring>
#include "Mystring.h"

Mystring::Mystring()
  : str{nullptr} {
    str = new char[1];
    *str = '\0';
  }

Mystring::Mystring(const char *s)
  : str {nullptr} {
    if (s == nullptr) {
      str = new char[1];
      *str = '\0';
    } else {
      str = new char[strlen(s) + 1];
      strcpy(str, s);
    }
  }

Mystring::Mystring(const Mystring &source)
  : str{nullptr} {
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
    std::cout << "Copy constructor used" << std::endl;
  }

Mystring::Mystring(Mystring &&source)
  : str(source.str) {
    source.str = nullptr;
    std::cout << "Move constructor called" << endl;
  }

Mystring::~Mystring() {
  delete [] str;
}

Mystring &Mystring::operator=(const Mystring &rhs) {
  std::cout << "Using copy assignment" << std::endl;
  if (this == &rhs)
    return *this;
  delete [] str;
  str = new char[strlen(rhs.str) + 1];
  strcpy(str, rhs.str);
  return *this;
}

Mystring &Mystring::operator=(Mystring &&rhs) {
  std::cout << "Using move assignment" << std::endl;
  if (this == &rhs)
    return *this;
  delete [] str;
  str = rhs.str;
  rhs.str = nullptr;
  return *this;
}

Mystring &Mystring::operator-() {
  char *buff = new char[strlen(str) + 1];
  std::strcpy(buff, str);
  for (size_t i = 0; i < std::strlen(buff); i++)
    buff[i] = std::tolower(buff[i]);
  Mystring temp {buff};
  delete [] buff;
  return temp;
}

Mystring &Mystring::operator==(const Mystring &rhs) const {
  return (strcmp(str, rhs.str) == 0);
}

Mystring &Mystring::operator!=(const Mystring &rhs) const {
  return !(strcmp(str, rhs.str) == 0);
}

Mystring &Mystring::operator<(const Mystring &lhs, const Mystring &rhs) const {
  return (std::strcmp(lhs.str, rhs.str) > 0)
}

Mystring &Mystring::operator>(const Mystring &lhs, const Mystring &rhs) const {
  return (std::strcmp(lhs.str, rhs.str) < 0)
}

Mystring &Mystring::operator+(const Mystring &rhs) const {
  char buff = new char[(std::strlen(str) + std::strlen(str) + 1)];
  std::strcpy(buff, str);
  std::strcat(buff, rhs.str);
  Mystring temp {buff};
  delete [] buff;
  return temp;
}

Mystring &Mystring::operator+=(const Mystring &rhs) {
  char buff = new char[(std::strlen(str) + std::strlen(str) + 1)];
  std::strcpy(buff, str);
  std::strcat(buff, rhs.str);
  Mystring temp {buff};
  delete [] buff;
  return temp;
}

Mystring &Mystring::operator*(const Mystring &rhs) {
  char buff = new char[((std::strlen(str) * rhs) + 1)];
  std::strcpy(buff, str);
  for (size_t i = 1; i < rhs; i++)
    std::strcat(buff, str);
  Mystring temp {buff};
  delete [] buff;
  return temp;
}

Mystring &Mystring::operator*=(const Mystring &rhs) {
  char buff = new char[((std::strlen(str) * rhs) + 1)];
  std::strcpy(buff, str);
  for (size_t i = 1; i < rhs; i++)
    std::strcat(buff, str);
  Mystring temp {buff};
  delete [] buff;
  return temp;
}

Mystring &Mystring::operator++() {
  char buff = new char[std::strlen(str) + 1];
  buff[0] = std::toupper(buff[0]);
  Mystring temp {buff};
  delete [] buff;
  return temp;
}

Mystring &Mystring::operator++(int) {
  char buff = new char[std::strlen(str) + 1];
  for (size_t i = 0; i < std::strlen(str); i++)
    buff[i] = std::toupper(buff[i]);
  Mystring temp {buff};
  delete [] buff;
  return temp;
}

Mystring &Mystring::operator--() {
  char buff = new char[std::strlen(str) + 1];
  buff[0] = std::tolower(buff[0]);
  Mystring temp {buff};
  delete [] buff;
  return temp;
}

Mystring &Mystring::operator--(int) {
  char buff = new char[std::strlen(str) + 1];
  for (size_t i = 0; i < std::strlen(str); i++)
    buff[i] = std::tolower(buff[i]);
  Mystring temp {buff};
  delete [] buff;
  return temp;
}

Mystring &Mystring::operator<<(std::ostream &os, const Mystring &rhs) {
  os << rhs.str;
  return os;
}

Mystring &Mystring::operator>>(std::istream &in, Mystring &rhs) {
  char buff = new char[1000];
  in >> buff;
  Mystring temp {buff};
  delete [] buff;
  return temp;
}

void Mystring::display() const {
  std::cout << str << " : " << get_length() << std::endl;
}

int Mystring::get_length() const {
  return strlen(str);
}
