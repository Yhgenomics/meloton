#include <string>

#include "NodeDetector.h"
#include "MRT.h"

void NodeDetector::callback( cb_on_detected_t callback )
{
    this->callback_ = callback;
}

void NodeDetector::start( )
{
    if ( started_ == true )
        return;

    this->started_ = true;
    uv_udp_.data = this;
    uv_loop_ = uv_default_loop( );
    uv_udp_init( uv_loop_ , &uv_udp_ );
    struct sockaddr_in recv_addr;
    uv_ip4_addr( "0.0.0.0" , 99 , &recv_addr );
    uv_udp_bind( &uv_udp_ , ( const struct sockaddr * )&recv_addr , UV_UDP_REUSEADDR );
    uv_udp_recv_start( &uv_udp_ , NodeDetector::uv_alloc_callback , NodeDetector::uv_read_callback );

    MRT::SyncWorker::create( 1000 , [ this ] ( MRT::SyncWorker* worker )
    { 
        if ( worker->loop_count( ) > 10 )
        {
            if ( this->detected )
            {
                return true;
            }
            else
            {
                this->stop( );
                if ( this->callback_ != nullptr )
                {
                    this->callback_( nullptr );
                }
            }
            
            this->stop( );
            return true;
        }

        return false;
    } , nullptr , nullptr );
}

void NodeDetector::stop( )
{
    if ( started_ == false )
        return;

    this->started_ = false;
    uv_udp_recv_stop( &this->uv_udp_ );
}

NodeDetector::NodeDetector( )
{

}

void NodeDetector::uv_alloc_callback( uv_handle_t * handle , size_t suggested_size , uv_buf_t * buf )
{
    buf->base = new char[suggested_size];
    buf->len  = suggested_size;
}

void NodeDetector::uv_read_callback( uv_udp_t * handle , ssize_t nread , const uv_buf_t * buf , const sockaddr * addr , unsigned flags )
{
    if ( nread < 0 )
    {
        LOG_DEBUG_UV( nread );

        if( buf->base != nullptr )
            delete buf->base;
        return;
    }

    if ( nread == 5 )
    {
        if ( buf->base[0] == 'Y' &&
             buf->base[1] == 'H' &&
             buf->base[2] == 'Y' &&
             buf->base[3] == 'S' &&
             buf->base[4] == 'B' )
        {
            NodeDetector* inst = scast<NodeDetector*>( handle->data );
            sockaddr_in sin;
            memcpy( &sin , addr , sizeof( sin ) );
            inst->stop( );
            if ( inst->callback_ != nullptr )
            {
                inst->callback_( &sin );
            }
        }
    }

    delete buf->base;
}
