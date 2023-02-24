#include <struct\exc\Exception.hpp>
#include <cstring>

const char OutOfRangeException::premsg[] = "Index out of range";
const char InvalidArgException::premsg[] = "Invalid argument";

Exception::Exception(const char* msg = NULL){
    this->msg = new char[strlen(msg) + 1];
    strcpy(this->msg, msg);
}

Exception::~Exception(){
    delete[] msg;
}

const char* Exception::what() const noexcept{
    return msg;
}

OutOfRangeException::OutOfRangeException(const char* msg = NULL): Exception(msg){
    if(msg == NULL){
        this->msg = new char[strlen(premsg) + 1];
        strcpy(this->msg, premsg);
    }else{
        this->msg = new char[strlen(premsg) + strlen(msg) + 3];
        strcpy(this->msg, premsg);
        strcat(this->msg, ": ");
        strcat(this->msg, msg);
    }
}

InvalidArgException::InvalidArgException(const char* msg = NULL): Exception(msg){
    if(msg == NULL){
        this->msg = new char[strlen(premsg) + 1];
        strcpy(this->msg, premsg);
    }else{
        this->msg = new char[strlen(premsg) + strlen(msg) + 3];
        strcpy(this->msg, premsg);
        strcat(this->msg, ": ");
        strcat(this->msg, msg);
    }
}
