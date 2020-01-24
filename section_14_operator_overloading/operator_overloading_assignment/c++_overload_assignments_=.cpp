#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main() {
  Mystring a {"Hello"};
  Mystring b;
  b = a;

  b = "This is a test";

  /*

  Mystring empty;
  Mystring larry {"Larry"};
  Mystring stooge {"Larry"};
  Mystring stooges;

  emptty = stooge;

  empty.display();
  larry.display();
  stooge.display();
  empty.display();

  stooges = "Larry, Moe and Curly";

  */

  return 0;
}
