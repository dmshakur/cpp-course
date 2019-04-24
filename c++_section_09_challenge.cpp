// P print sumNumbers
// a add a numbers
// m display mean of sum
// s display the smallest numbers
// l display the largest number
// q quit

#include <iostream>
#include <vector>
using namespace std;

int main() {

  cout << "Input a P to print all numbers" << endl;
  cout << "Input a A to add a number" << endl;
  cout << "Input a M to display the mean of all the number" << endl;
  cout << "Input a S to display the smallest number" << endl;
  cout << "Input a L to display the largest number" << endl;
  cout << "Input a Q to quit the program" << endl;

  char letter = {};
  cout << "Please enter one of the preceding commands... ";
  cin >> letter;

  vector<int> numbers;

  while (true) {

    if (letter == 'P' || letter == 'p') {
      for (int i = 0; i < numbers.size(); i++) {
        cout << numbers.at(i) << " ";
      }
      cout << endl;
    } else if (letter == 'A' || letter == 'a') {
      cout << "Please enter a number to add... ";
      int adder {0};
      cin >> adder;
      numbers.push_back(adder);
    } else if (letter == 'M' || letter == 'm') {
      if (numbers.size() > 1) {
        int x = {0};
        for (int j = 0; j < numbers.size(); j++) {
          x += numbers.at(j);
        }
        cout << x / numbers.size() << endl;
      } else {
        cout << "You do not have any numbers to get the mean of, please try again... ";
      }
    } else if (letter == 'S' || letter == 's') {
      if (numbers.size() > 1) {
        int y = {0};
        for (int k = 0; k < numbers.size(); k++) {
          if (numbers.at(k) < numbers.at(y)) {
            y = k;
          }
        }
        cout << numbers.at(y) << " is the smallest number." << endl;
      }
    } else if (letter == 'L' || letter == 'l') {
      if (numbers.size() > 1) {
        int z = {0};
        for (int k = 0; k < numbers.size(); k++) {
          if (numbers.at(k) > numbers.at(z)) {
            z = k;
          }
        }
        cout << numbers.at(z) << " is the largest number." << endl;
      }
    } else if (letter == 'q' || letter == 'Q') {
      cout << "Goodbye";
      break;
    } else {
      cout << "What you entered was invalid please try again... " << endl;
    }
    cout << "Please enter one of the preceding commands... ";
    cin >> letter;
  }

  return 0;
}
