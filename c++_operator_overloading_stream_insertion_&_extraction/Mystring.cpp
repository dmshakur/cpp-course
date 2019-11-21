#include <iostream>
#include <cstring>

Mystring::Mystring()
  :str{nullptr} {
    str = new char[1];
    *str = '\0';
  }

Mystring::Mystring(const char *s)
  :str{nullptr} {
    if (s == nullptr) {
      str = new char[1];
      *str = '\0';
    } else {
      str = new char[strlen(s) + 1];
      strcpy(str, s);
    }
  }

Mystring::Mystring(const Mystring &source)
  :str{nullptr} {
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
    std::cout << "Copy constructor used" << std::endl;
  }

Mystring::Mystring(Mystring &&source)
  :str(source.str) {
    source.str = nullptr;
    std::cout << "Move constructor used" << std::endl;
  }

Mystring::~Mystring() {
  delete [] str;
}

Mystring &Mystring::operator=(const Mystring &rhs) {
  std::cout << "Using copy assigment" << std::endl;

  if (this == &rhs)
    return *this;
  delete [] str;
  str = new char[strlen(rhs.str) + 1];
  std::strcpy(str, rhs.str);
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

void Mystring::display() const {
  std::cout << str << " : " <  get_length() << std::endl;
}

int Mystring::get_length() const { return strlen(str); }
const char *Mystring::get_str() const { return str; }

// Overloaded insertion operator

std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
  os << rhs.str;
  return os;
}

// Overloaded extraction operator

std::istream &operator>>(std::istream &in, Mystring &rhs) {
  char *buff new char[1000];
  in >> buff;
  rhs = Mystring{buff};
  delete [] buff;
  return in;
}
