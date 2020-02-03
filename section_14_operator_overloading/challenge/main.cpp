#include <iostream>
#include "Mystring.cpp"

using namespace std;

int main()
{
  std::cout << std::boolalpha << std::endl;
  // Mystring a {"frank"};
  // Mystring b {"Frank"};

  // cout << (a == b) << endl;
  // cout << (a != b) << endl;

  // b = "frank";
  // std::cout << (a == b) << std::endl;

  // b = "george";
  // cout << (a == b) << endl;
  // cout << (a != b) << endl;

  // b = "frank";

  // cout << (a != b) << endl;
  // b = "george";

  // cout << a << " Less than " << b << (a < b) << endl;
  // cout << a << " Greater than " << b << (a > b) << endl;

  Mystring s1 {"FRANK"};
  // s1 = -s1;
  // std::cout << s1 << std::endl;

  // s1 = s1 + "*** *** ***";
  // cout << s1 << endl;

  s1 += " ********";
  cout << s1 << endl;

  Mystring s2 {"12345"};
  s1 = s2 * 3;
  cout << s1 << endl;

  Mystring s3 {"abcdef"};
  s3 *= 5;
  cout << s3 << endl;

//   Mystring s = "Frank";
//   ++s;
//   cout << s << endl;

//   s = -s;
//   cout << s << endl;

//   Mystring result;
//   result = ++s;
//   cout << s << endl;
//   cout << result << endl;

//   s = "Frank";
//   s++;
//   cout << s << endl;

//   s = -1;
//   cout << s << endl;
//   result = s++;
  // cout << s << endl;
  // cout << result << endl;

  return 0;
}

/*
  Section 14 Challenge Operator Overloading

  Overload the following operators in the provided Mystring class.

  To gain experience overloading using member functions and then in another project overload the same operators
  again using non-member functions.

  Please do it once using member methods and then again using non-member functions.

  Here is a list of some of the operators that you can overload for this class;

  -  unary minus. returns the lowercase version of the objects string CHECK
      (-string_name)
  == returns true if the two strings are equal CHECK
      (s1 == s2)
  != returns true if the two strings are not equal CHECK
      (s1 != s2)
  <  returns true if the lhs string is lexically less than the rhs string CHECK
      (s1 < s2)
  >  returns true if the lhs string is lexically greater than the rhs string CHECK
      (s1 > s2)
  +  concatenation. Returns an object that concatenates the lhs and the rhs CHECK
      (s1 + s2)
  += concatenate the rhs string to the lhs string and store the result in the lhs objects 
      (s1 += s2)
  *  repeat results in a string that is copied (n) times 
      (s2 * 3)
  *= repeat the string on the lhs (n) times and store the result in the lhs object 
      (s1 = "abc"
       s1 *= 4)

    if you wish to overload the ++ and -- operators remember that they have pre and post versions.

    The semantics should be as follows (this shows the member method version)

    Mystring &operator++() { // Pre-increment syntax
      // Do whatever you want increment to do - maybe make all the characters uppercase?
      return *this;
    }

    // Note that post-increment returns a Mystring by value not by reference

    Mystring operator++(int) { // Post-increment
      Mystring temp {*this}; // Make a copy
      operator++(); // Call Pre-increment
      return temp; // Return the old value
    }
*/
