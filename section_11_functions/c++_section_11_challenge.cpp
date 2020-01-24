#include <iostream>
#include <vector>

using namespace std;

// print numbers
// add a number
// mean of numbers
// display smallest number
// display largest number
// quit function

void print(const vector<int> v);
void add();
void mean(const vector<int> v);
void smallest(const vector<int> v);
void largest(const vector<int> v);
// void clear();
void quit();
void entry();

vector<int> num_vec {};

int main() {
  entry();

  return 0;
}

void print(vector<int> v) {
  for (auto i: v)
    cout << i << " ";
  cout << endl;
  entry();
}

void add() {
  cout << "Please enter a number to add to the list... ";
  int num {};
  cin >> num;

  while (!cin) {
    cout << "Invalid input please try again... ";
    cin >> num;
  }

  num_vec.push_back(num);
  cout << endl;
  entry();
}

void mean(vector<int> v) {
  int sum {};

  for (auto i: v)
    sum += i;
  cout << sum << endl;
  entry();
}

void smallest(vector<int> v) {
  int temp = v.at(0);

  for (auto i: v)
    if (i < temp)
      temp = i;
  cout << temp << endl;
  entry();
}

void largest(vector<int> v) {
  int temp {};

  for (auto i: v)
    if (i > temp)
      temp = i;
  cout << temp << endl;
  entry();
}

void entry() {
  cout << "Input a P to print all numbers" << endl << "Input an A to add a number" << endl;
  cout << "Input a M to display the mean of all the number" << endl << "Input an S to display the smallest number" << endl;
  cout << "Input a L to display the largest number" << endl << "Input a Q to quit the program" << endl;

  char input {};

  cin >> input;

  if (input == 'P')
    print(num_vec);
  else if (input == 'A') {
    add();
  } else if (input == 'M')
    mean(num_vec);
  else if (input == 'S')
    smallest(num_vec);
  else if (input == 'L')
    largest(num_vec);
  else if (input == 'Q')
    return;
  else {
    cout << "\nInvalid input, please try again\n";
    entry();
  }
}
