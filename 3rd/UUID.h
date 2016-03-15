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
        std::string ret = "";
        //char buf[UUID_LEN];
        const char *c = "yhgenomics";
        char num_buf[8] = { 0 };

        for (int n = 0; n < 16; ++n )
        {
            int seed = rand() % 255;

#ifdef _WIN32
            sprintf_s( num_buf , "%02X" , seed );
#else
            sprintf( num_buf , "%02X" , seed );
#endif
            //itoa( seed , num_buf , 16 );
            ret += num_buf;
        } 

        return ret;
    } 

private:

    const static int UUID_LEN = 37;

    UUID() {};
    ~UUID() {};
};

NS_MARATON_END

#endif // !UUID_HPP_