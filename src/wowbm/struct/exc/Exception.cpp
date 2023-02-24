#include <struct\exc\Exception.hpp>
#include <cstring>

Exception::Exception(const char* msg){
    this->msg = new char[strlen(msg) + 1];
    strcpy(this->msg, msg);
}

Exception::~Exception(){
    delete[] msg;
}

const char* Exception::what() const noexcept{
    return msg;
}
