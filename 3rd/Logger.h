/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-10-22
* Description:
* * * * * * * * * * * * * * * */

#ifndef MRT_LOGER_H_
#define MRT_LOGER_H_ 

#include <stdio.h>
#include <iostream>
#include <stdarg.h>
#include "Timer.h"

class Logger
{
public:

    template<typename ...Types>
    static void sys( const char* fmt, Types... args)
    {

#ifdef _WIN32
        tprintf( "[SYS] %lld: ", Timer::tick() );
#else
        tprintf( "\033[1;33m[SYS] %lld: ", Timer::tick() );
#endif

        tprintf( fmt, args... );

#ifdef _WIN32
        tprintf( "\r\n" );
#else
        tprintf( "\033[0m\r\n" );
#endif      

    }

    template<typename ...Types>
    static void error( const char* fmt, Types... args )
    {
#ifdef _WIN32
        tprintf( "[ERROR] %lld: ", Timer::tick() );
#else
        tprintf( "\033[0;31m[ERROR] %lld: ", Timer::tick() );
#endif
        tprintf( fmt , args... );

#ifdef _WIN32
        tprintf( "\r\n" );
#else
        tprintf( "\033[0;31m\r\n" );
#endif    
    }

    template<typename ...Types>
    static void log( const char* fmt, Types... args )
    { 
        tprintf( "%lld: ", Timer::tick() );
        tprintf( fmt , args... );
        tprintf( "\r\n" );
    }
private:

    Logger( )
    {
    };
    ~Logger( )
    {
    };

    static void tprintf( const char* format ) // base function
    {
        std::cout << format;
    }

    template<typename T , typename... Targs>
    static void tprintf( const char* format , T value , Targs... Fargs ) // recursive variadic function
    {
        for ( ; *format != '\0'; format++ )
        {
            if ( *format == '%' )
            {
                std::cout << value;
                tprintf( format + 1 , Fargs... ); // recursive call
                return;
            }
            std::cout << *format;
        }
    }
};

#endif // !MRT_LOGER_H_ 