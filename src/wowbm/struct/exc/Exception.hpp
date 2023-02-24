#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <stdexcept>

class Exception : public std::exception{
    public:
        Exception(const char*);
        ~Exception();
        const char* what() const noexcept;
    protected:
        char* msg;
};

class OutOfRangeException : public Exception{
    public:
        OutOfRangeException(const char*);
    private:
        static const char premsg[];
};

class InvalidArgException : public Exception{
    public:
        InvalidArgException(const char*);
    private:
        static const char premsg[];
};

#endif
