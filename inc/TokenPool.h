/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-30
* Description:
* * * * * * * * * * * * * * * */

#ifndef TOKEN_POOL_H_
#define TOKEN_POOL_H_

#include <string>
#include <vector>

#include "MRT.h"
#include "meloton.h"

class TokenPool
{
public:

    ~TokenPool( );
    SINGLETON( TokenPool );

    std::string create( );
    bool        check_token( std::string token );
    void        remove( std::string token );

private:

    TokenPool( );
    std::vector<std::string> token_list_;
};

#endif // !TOKEN_POOL_H_
