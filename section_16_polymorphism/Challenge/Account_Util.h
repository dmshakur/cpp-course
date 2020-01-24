#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include <vector>
// #include "Account.cpp"
#include "Savings_Account.cpp"
// #include "Checking_Account.cpp"
// #include "Trust_Account.cpp"

// Utility helper functions for Account class
template <class T>
void display(const std::vector<T> &accounts);

template <class T>
void deposit(std::vector<T> &accounts, double amount);

template <class T>
void withdraw(std::vector<T> &accounts, double amount);

#endif