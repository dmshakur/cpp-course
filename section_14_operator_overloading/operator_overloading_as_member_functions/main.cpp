#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  cout << boolalpha << endl;

  Mystring larry {"Larry"};
  Mystring moe {"Moe"};

  Mystring stooge = larry;
  larry.display();
  moe.display();

  cout << (larry == moe) << endl;
  cout << (larry == stooge) << endl;

  larry.display();
  Mystring larry2 = -larry;
  larry2.display();

  Mystring stooges = larry + "Moe";
  // Mystring stooges = "Larry" + moe;

  Mystring two_stooges = moe + " " + "Larry";

  return 0;
}
