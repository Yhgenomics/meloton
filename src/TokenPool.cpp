#include <TokenPool.h>

TokenPool::~TokenPool( )
{
}

sptr<Token> TokenPool::create( size_t index )
{
    sptr<Token> meta = make_sptr( Token , index );
    meta->token( MRT::UUID::create( ) );
    meta->index( index );
    this->token_list_.push_back( sptr<Token>(meta) );
    return sptr<Token>(meta);
}

bool TokenPool::check_token( std::string token )
{
    for ( auto & t : this->token_list_ )
    {
        if ( t->token() == token )
        {
            return true;
        }
    }
    
    return false;
}

sptr<Token> TokenPool::get_token( std::string token )
{
    for ( auto & t : this->token_list_ )
    {
        if ( t->token() == token )
        {
            return sptr<Token>(t);
        }
    }

    return nullptr;
}

void TokenPool::remove( std::string token )
{
    for ( auto i = this->token_list_.begin(); 
          i != this->token_list_.end( ); 
          i++ )
    {
        if ( (*i)->token() == token )
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
