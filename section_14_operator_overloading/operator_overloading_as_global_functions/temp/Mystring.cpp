

void Mystring::display() const {
  std::cout << str << " : " << get_length() << std::endl;
}

int Mystring::get_length() const {return std::strlen(str);}

const char *Mystring::get_str() const {return str;}

// Equality
bool operator==(const Mystring &lhs, const Mystring &rhs) {
  return (std::strcmp(lhs.str, rhs.str) == 0);
}

// Make Lowercase
Mystring operator-(const Mystring &obj) {
  char *buff = new char[std::strlen(obj.str) + 1];
  std::strcpy(buff, obj.str);
  for (size_t i=0; i<std::strlen(buff); i++)
    buff[i] = std::tolower(buff[i]);
  Mystring temp {buff};
  delete [] buff;
  return temp;
}

// Concatenation
Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
  char *buff = new char[std::strlen(lhs.str + std::strlen(rhs.str) + 1)];
  std::strcpy(buff, lhs.str);
  std::str.cat(buff, rhs.str);
  Mystring temp {buff};
  delete [] buff;
  return temp;
}
