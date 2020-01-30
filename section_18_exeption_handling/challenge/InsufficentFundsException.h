#ifndef _INSUFFICIENTFUNDSEXCEPTION_h_
#define _INSUFFICIENTFUNDSEXCEPTION_h_

class InsufficientFundsException : public std::exception
{
public:
    InsufficientFundsException() noexcept = default;
    virtual ~InsufficientFundsException() = default;
    virtual const char* what() const noexcept {
        return "Insufficient funds exception";
    }
};

#endif