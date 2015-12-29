#include "RequestTokenTable.h"
#include <MessageToken.pb.h>

RequestTokenTable::RequestTokenTable( )
{

}

RequestTokenTable::~RequestTokenTable( )
{
}

sptr<RequestTokenCollection> RequestTokenTable::create( sptr<ClusterSession> client , 
                                              std::string request_id , 
                                              size_t token_num  )
{
    auto token = make_sptr( RequestTokenCollection , 
                            client ,
                            request_id ,
                            token_num);
    this->token_list_.push_back( move_ptr( token ) );
    return token;
}

sptr<RequestTokenCollection> RequestTokenTable::find( std::string request_id )
{
    for ( auto & t : this->token_list_ )
    {
        if ( t->request_id_ == request_id )
        {
            return move_ptr( t );
        }
    }

    return nullptr;
}

sptr<RequestTokenCollection> RequestTokenTable::remove( std::string request_id )
{
    for ( auto i = this->token_list_.begin(); i !=  this->token_list_.end(); i++ )
    {
        if ( ( *i )->request_id_ == request_id )
        {
            this->token_list_.erase( i );
            return *i;
        }
    }

    return nullptr;
}

RequestTokenCollection::RequestTokenCollection( sptr<ClusterSession> client , 
                                                std::string request_id ,
                                                size_t token_num )
{
    this->client_           = client;
    this->request_id_       = request_id;
    this->token_max_size_   = token_num;
}

RequestTokenCollection::~RequestTokenCollection( )
{

}

void RequestTokenCollection::add_token( sptr<NodeSession> client , 
                                        std::string token ,
                                        size_t index ,
                                        size_t block_id )
{
    
    sptr<TokenResponse> item = make_sptr( TokenResponse );

    std::get<0>( *item ) = client;
    std::get<1>( *item ) = token;
    std::get<2>( *item ) = index;
    std::get<3>( *item ) = block_id;

    this->token_list_.push_back( item );
}

void RequestTokenCollection::reply_token( )
{
    int index = 0;
    uptr<MessageToken> msg = make_uptr( MessageToken );

    for ( auto & t : this->token_list_ )
    {
        sptr<NodeSession> client = std::get<0>( *t );
        std::string token =  std::get<1>( *t );
        size_t index =  std::get<2>( *t );
        size_t block_id =  std::get<3>( *t );

        msg->set_address( index , client->data_ip( ) );
        msg->set_port( index , client->data_port( ) );
        msg->set_expire( index , MAX_SIZE_T );
        msg->set_token( index , token );
        msg->set_index( index , index );
        msg->set_block_id( index , block_id );

        ++index;
    }

    this->client_->send_message( move_ptr( msg ) );
    this->client_->close( );
}

bool RequestTokenCollection::is_full( )
{
    return this->token_max_size_ == this->token_list_.size( );
}

std::string RequestTokenCollection::request_id( )
{
    return this->request_id_;
}
