#include <TokenPool.h>

TokenPool::~TokenPool( )
{
}

std::string TokenPool::create( )
{
    auto token = MRT::UUID::create( );
    this->token_list_.push_back( token );
    return token;
}

bool TokenPool::check_token( std::string token )
{
    for ( auto & t : this->token_list_ )
    {
        if ( t == token )
        {
            return true;
        }
    }
    
    return false;
}

void TokenPool::remove( std::string token )
{
    for ( auto i = this->token_list_.begin(); 
          i != this->token_list_.end( ); 
          i++ )
    {
        if ( *i == token )
        {
            this->token_list_.erase( i );
            return;
        }
    }
}

size_t TokenPool::token_num( )
{
    return this->token_list_.size( );
}

TokenPool::TokenPool( )
{
}
