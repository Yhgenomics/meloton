#include "NodeBroadcaster.h"
#include "MRT.h"

NodeBroadcaster::NodeBroadcaster( )
{
    this->uv_loop_ = uv_default_loop( );
    uv_udp_init( this->uv_loop_ , &this->uv_udp_ );
    struct sockaddr_in broadcast_addr;
    uv_ip4_addr( "0.0.0.0" , 0 , &broadcast_addr );
    uv_udp_bind( &this->uv_udp_ , ( const struct sockaddr * )&broadcast_addr , 0 );
    uv_udp_set_broadcast( &this->uv_udp_ , 1 );
}

NodeBroadcaster::~NodeBroadcaster( )
{

}

uv_buf_t NodeBroadcaster::make_discover_msg( )
{

    memcpy( broadcast_data_ , "YHYSK" , sizeof( broadcast_data_ ) );

    uv_buf_t t;
    t.base = broadcast_data_;
    t.len  = sizeof( broadcast_data_ );
    return t;
}

void NodeBroadcaster::start( )
{ 
    if ( started_ )
        return;
    started_ = true;
   
    MRT::SyncWorker::create( 500 , [ this ] ( MRT::SyncWorker* worker )
    {
        uv_udp_send_t send_req = { 0 };

        uv_buf_t discover_msg   = this->make_discover_msg( );
        send_req.data           = discover_msg.base;

        struct sockaddr_in send_addr;
        uv_ip4_addr( "255.255.255.255" , 99 , &send_addr );
        uv_udp_send( &send_req ,
                     &this->uv_udp_ ,
                     &discover_msg ,
                     1 ,
                     ( const struct sockaddr * )&send_addr ,
                     NodeBroadcaster::uv_udp_sent_callback );

        return !this->started_;
    } , nullptr , nullptr );

}

void NodeBroadcaster::uv_udp_sent_callback( uv_udp_send_t * req , int status )
{ 
    if ( status < 0 )
    {
        LOG_DEBUG_UV( status );
    }
}

void NodeBroadcaster::stop( )
{
    started_ = false;
}
