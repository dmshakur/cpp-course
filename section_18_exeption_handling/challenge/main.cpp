#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "InsufficentFundsException.h"
#include "IllegalBalanceException.h"

int main()
{
    Checking_Account checking {};
    Savings_Account savings {};
    Trust_Account trust {};

    std::cout << "Program completed successfully" << std::endl;
    return 0;
}
