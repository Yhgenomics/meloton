#include "Error.h"

Error::Error( int code , std::string msg )
{
    this->code_ = code;
    this->msg_ = msg;
}

Error::Error( int code )
{
    this->code_ = code;
}

Error::Error( Error & error )
{
    this->code_ = error.code_;
    this->msg_ = error.msg_;
}

Error::Error( Error && error )
{
    this->code_ = error.code_;
    this->msg_ = error.msg_;

    error.code_ = 0;
    error.msg_ = "";
}

Error Error::operator=( Error & error )
{
    this->code_ = error.code_;
    this->msg_ = error.msg_;

    return *this;
}

Error Error::operator=( Error && error )
{
    this->code_ = error.code_;
    this->msg_ = error.msg_;

    error.code_ = 0;
    error.msg_ = "";

    return *this;
}

Error::~Error( )
{

}

bool Error::success( )
{
    return this->code_ == 0;
}
  