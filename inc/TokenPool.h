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

class Token
{
public:

    Token( size_t index )
    {
        index_ = index;
        token_ = MRT::UUID::create( );
    }

    PP_DEF( size_t , index )
    PP_DEF( std::string , token )

private:

    size_t      index_ = 0;
    std::string token_ = "";
};

class TokenPool
{
public:

    ~TokenPool( );
    SINGLETON( TokenPool );

    sptr<Token> create( size_t index );
    bool            check_token( std::string token );
    sptr<Token> get_token( std::string token );
    void            remove( std::string token );
    size_t          token_num( );

private:

    TokenPool( );
    std::vector<sptr<Token>> token_list_;
};

#endif // !TOKEN_POOL_H_
