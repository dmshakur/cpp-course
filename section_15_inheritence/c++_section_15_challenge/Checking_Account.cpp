#include "Checking_Account.h"

bool Checking_Account::withdraw(std::string name, double balance) {
  if (balance - amount < 1.5) {
    return false;
  } else {
    balance -= amount + 1.5;
    return true;
  }
}

std::ostream &operator<<(std::ostream &os, const Savings_Account &account) {
  os << "[Savings_Account: " << account.name << ": " << account.balance << "]";
  return os;
}
