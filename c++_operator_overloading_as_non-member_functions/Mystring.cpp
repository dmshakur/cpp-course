Mystring &Mystring::operator=(Mystring &&rhs) {
  std::cout << "Using move assignment" << std::endl;
  if (this == &rhs)
    return *this;
  delete [] str;
  str = rhs.str;
  rhs.str = nullptr;
  return *this;
}

bool Mystring::operator==(const Mystring &rhs) const {
  return (std::strcmp(str, rhs.str) == 0);
}

Mystring Mystring::operator-() const {
  char *buff = new char[std::strlen(str) + 1];
  std::strcpy(buff, str);
  for (size_t i = 0; i < std::strlen(buff); i++)
    buff[i] = std::tolower(buff[i]);
  Mystring temp {buff};
  delete [] buff;
  return temp;
}

Mystring Mystring::operator+(const Mystring &rhs) const {
  char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
  std::strcpy(buff, str);
  std::strcat(buff, rhs.str);
  Mystring temp {buff};
  delete [] buff;
  return temp;
}

void Mystring::display() const {
  std::cout << str << " : " << get_length() << endl;
}

int Mystring::get_length() const {return std::strlen(str);}

const char *Mystring::get_str() const {return str;}
