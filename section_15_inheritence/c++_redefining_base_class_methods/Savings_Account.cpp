#include <iostream>

Savings_Account::Savings_Account(double balance, double int_rate)
    : Account(balance), int_rate{int_rate} {
}

Savings_Account::Savings_Account()
  : Savings_Account{0.0, 0.0} {
  }

void Savings_Account::deposit(double amount)
{
    amount = amount + (amount * int_rate/100);
    Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const Savings_Account &account) {
  os << "Savings account balance: " << account.balance << " interest rate: " << account.int_rate;
  return os;
}

void Savings_Account::withdraw(double amount)
{
    std::cout << "Savings Account withdraw called with " << amount << std::endl;
}
