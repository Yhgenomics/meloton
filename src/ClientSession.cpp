#include <ClientSession.h>

bool ClientSession::add_token( sptr<TokenMeta> token_meta )
{
    this->token_list_.push_back( token_meta );

    return this->token_list_.size( ) == this->token_num_;
}

sptr<TokenMeta> ClientSession::get_token( size_t index )
{
    size_t idx =0;
    for ( auto & t : this->token_list_ )
    {
        if ( idx == index )
        {
            return t;
        }
       
        ++idx;
    }
    
    return nullptr;
}

