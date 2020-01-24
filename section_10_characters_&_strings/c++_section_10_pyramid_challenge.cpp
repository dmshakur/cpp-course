#include <iostream>
#include <string>

using namespace std;

int main() {

  string user_input, pyra;
  cout << "Please enter a sequence of characters... ";
  cin >> user_input;

  if (user_input.length() < 1) {
    cout << "Sorry that is not long enough, please try again... ";
    cin >> user_input;
  }

  string space (user_input.length() - 1, ' ');

  for (size_t i{0}; i < user_input.length(); ++i) {
    pyra = user_input.substr(0, i + 1);
    cout << space << pyra;
    if (pyra.length() > 1) {
      for (int j {pyra.length() - 1}; j > 0; --j) {
        cout << pyra.at(j - 1);
      }
    }
    space.erase(0, 1);
    cout << endl;
  }
  return 0;
}
