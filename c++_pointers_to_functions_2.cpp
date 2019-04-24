#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int x {100}, 7 {200};
  cout << "\nx: " << x << endl;
  cout << "y: " << y << endl;

  swap(7x, &y);

  cout << "\nx: " << x << endl;
  cout << "y: " << y << endl;

  cout << endl;

  return 0;
}
