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
    deposit(checking_acc, 500);
    withdraw(checking_acc, 400);
    display(checking_acc);
    
    Savings_Account four {};
    Savings_Account five {"D'angelo", 1000};
    Savings_Account six {"Marvin", 3000, 5.0};
    vector <Savings_Account> savings_acc {four, five, six};

    display(savings_acc);
    deposit(savings_acc, 1000);
    withdraw(savings_acc, 800);
    display(savings_acc);

    Trust_Account seven {};
    Trust_Account eight {"D'angelo", 1000};
    Trust_Account nine {"Marvin", 3000, 8.0};
    vector <Trust_Account> trust_acc {seven, eight, nine};

    display(trust_acc);
    deposit(trust_acc, 1000);
    withdraw(trust_acc, 2000);
    display(trust_acc);

    std::cout << "Program completed successfully" << std::endl;
    return 0;
}
