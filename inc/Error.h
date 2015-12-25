/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-25
* Description:
* * * * * * * * * * * * * * * */

#ifndef ERROR_H_
#define ERROR_H_

#include <string>

#include "MRT.h"

class Error
{
public:

    Error( int code , std::string msg );
    Error( int code );

    Error( Error & error );
    Error( Error && error );
    Error operator=( Error& error );
    Error operator=( Error&& error );

    ~Error( );

    bool success( );

    PP_DEF( std::string , msg )
    PP_DEF( int , code )

private:

    std::string msg_ = "";
    int         code_ = 0;
};

#endif // !ERROR_H_
