#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>

class Exception : public std::exception{
    public:
        Exception(const char*);
        ~Exception();
        const char* what() const noexcept;
    private:
        char* msg;
};

#endif
