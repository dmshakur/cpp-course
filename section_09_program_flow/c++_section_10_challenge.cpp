#include <iostream>
#include <string>

using namespace std;

int main() {

  string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  string key {"xznlwebgjhqdyvtkfuompciasrXZNLWEBGJHQDYVKFUOMPCIASR"};

  cout << "Enter your secret message: ";
  string secret_message {};
  getline(cin, secret_message);

  cout << "Encrypting message... ";
  for (size_t i{0}; i < secret_message.length(); ++i) {
    int pos = alphabet.find(secret_message.at(i));
    secret_message.at(i) = key.at(pos);
  }
  cout << secret_message << endl;
  // loop here

  cout << "Decrypting message... ";
  // loop again
  for (size_t i{0}; i < secret_message.length(); ++i) {
    int pos = key.find(secret_message.at(i));
    secret_message.at(i) = alphabet.at(pos);
  }
  cout << secret_message << endl;



  return 0;
}
