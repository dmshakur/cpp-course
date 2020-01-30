#ifndef _ILLEGAL_BALANCE_EXCEPTION_H_
#define _ILLEGAL_BALANCE_EXCEPTION_H_

class IllegalBalanceException : public std::exception
{
public:
    IllegalBalanceException() noexcept = default;
    virtual ~IllegalBalanceException() = default;
    virtual const char* what() const noexcept {
        return "Illegal Balance Exception";
    }
};

#endif // __ILLEGAL_BALANCE_EXCEPTION_H__
