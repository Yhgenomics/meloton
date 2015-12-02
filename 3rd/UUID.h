/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-10-22
* Description:
* * * * * * * * * * * * * * * */

#ifndef UUID_HPP_
#define UUID_HPP_

#include <random>
#include <string>

#include "Macro.h"

NS_MARATON_BEGIN

class UUID
{
public:

    static std::string create() 
    {
        char buf[UUID_LEN];
        const char *c = "yhgenomics";
        char *p = buf;
        int n;

        for ( n = 0; n < 16; ++n )
        {
            int seed = rand() % 255;
            switch ( n )
            {
            case 6:
#ifdef _WIN32
                sprintf_s( p, UUID_LEN , "4%x", seed % 15 );
#else
                sprintf( p, "4%x", seed % 15 );
#endif
                break;

            case 8:

#ifdef _WIN32
                sprintf_s( p, UUID_LEN ,"%c%x", c[rand() % strlen( c )], seed % 15 );
#else
                sprintf( p, "%c%x", c[rand() % strlen( c )], seed % 15 );
#endif
                break;

            default:
#ifdef _WIN32
                sprintf_s( p, UUID_LEN , "%02x", seed );
#else
                sprintf( p, "%02x", seed );
#endif
                break;
            }

            p += 2;
        }

        *p = 0;
        return std::string( buf );
    } 

private:

    const static int UUID_LEN = 37;

    UUID() {};
    ~UUID() {};
};

NS_MARATON_END

#endif // !UUID_HPP_