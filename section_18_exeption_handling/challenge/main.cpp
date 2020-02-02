#include <iostream>
#include <memory>
#include "Account.cpp"
#include "Checking_Account.cpp"
#include "Savings_Account.cpp"
#include "Trust_Account.cpp"
#include "Account_Util.cpp"

using namespace std;

int main() {
    
    Checking_Account one {};
    Checking_Account two {"D'angelo"};
    Checking_Account three {"Marvin", 3000};
    vector <Checking_Account> checking_acc {one, two, three};

    display(checking_acc);
    deposit(checking_acc, 1000);
    withdraw(checking_acc, 1100);

    std::cout << "Program completed successfully" << std::endl;
    return 0;
}

/*
    Changed all #include(s) in main.cpp to be .cpp instead of .h
    Changed Account.h to have #include "I_Printable.cpp" instead of #include "I_Printable.h"
*/