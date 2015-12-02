/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       :
* Description:
* * * * * * * * * * * * * * * */

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_ 

#include "Macro.h"
#include "json.hpp"
#include <string>

NS_MARATON_BEGIN

class Configuration
{
public:

    static Configuration * instance( )
    {
        static Configuration * pT = nullptr;
        if ( !pT )
        {
            static Configuration instance;
            pT = &instance;
        }
        return pT;
    };

    std::string get ( std::string key );

protected:

    Configuration   ( );

private:

    json config; 
};

NS_MARATON_END

#endif //!CONFIGURATION_H_ 