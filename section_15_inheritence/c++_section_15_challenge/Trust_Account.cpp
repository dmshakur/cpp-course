#include "Trust_Account.h"

bool Trust_Account::deposit(double amount) {
  if (amount >= 5000)
    amount += 50;
  amount += amount * (int_rate/100);

  return Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
  if ((times_withdrew > 3) || (amount >= (Trust_Account::balance / 5)))
    return false;

  Trust_Account::increase_times_withdrew();

  return Account::withdraw(amount);
}
